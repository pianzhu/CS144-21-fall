#include "network_interface.hh"

#include "arp_message.hh"
#include "ethernet_frame.hh"

#include <iostream>

// Dummy implementation of a network interface
// Translates from {IP datagram, next hop address} to link-layer frame, and from link-layer frame to IP datagram

// For Lab 5, please replace with a real implementation that passes the
// automated checks run by `make check_lab5`.

// You will need to add private members to the class declaration in `network_interface.hh`

template <typename... Targs>
void DUMMY_CODE(Targs &&... /* unused */) {}

using namespace std;

//! \param[in] ethernet_address Ethernet (what ARP calls "hardware") address of the interface
//! \param[in] ip_address IP (what ARP calls "protocol") address of the interface
NetworkInterface::NetworkInterface(const EthernetAddress &ethernet_address, const Address &ip_address)
    : _ethernet_address(ethernet_address), _ip_address(ip_address) {
    cerr << "DEBUG: Network interface has Ethernet address " << to_string(_ethernet_address) << " and IP address "
         << ip_address.ip() << "\n";
}

//! \param[in] dgram the IPv4 datagram to be sent
//! \param[in] next_hop the IP address of the interface to send it to (typically a router or default gateway, but may also be another host if directly connected to the same network as the destination)
//! (Note: the Address type can be converted to a uint32_t (raw 32-bit IP address) with the Address::ipv4_numeric() method.)
void NetworkInterface::send_datagram(const InternetDatagram &dgram, const Address &next_hop) {
    // convert IP address of next hop to raw 32-bit representation (used in ARP header)
    const uint32_t next_hop_ip = next_hop.ipv4_numeric();
    const auto& _iter_arp = _arp_table.find(next_hop_ip);
    //! find the mac address in arp table
    if (_iter_arp != _arp_table.end()) {
        EthernetFrame _send_frame;
        _send_frame .header().dst = _iter_arp->second._mac_address;
        _send_frame.header().src = _ethernet_address;
        _send_frame.header().type = EthernetHeader::TYPE_IPv4;
        _send_frame.payload() = dgram.serialize();
        //! put this frame to frame_out to send it
        _frames_out.push(_send_frame);
    }
    //! mac addr and ip addr of the next hop is not in arp table
    else {
        //! we need to send an arp request
        const auto& iter = _waiting_response_datagram.find(next_hop_ip);
        if (iter != _waiting_response_datagram.end()
            && iter->second._time_since_last_ARP_request_send <= NetworkInterface::ARP_RESPONSE_TTL) {
            _waiting_response_datagram[next_hop_ip]._waiting_response_datagram.push(dgram);
            return;
        }
        ARPMessage _send_arp_message;
        _send_arp_message.opcode = ARPMessage::OPCODE_REQUEST;
        _send_arp_message.sender_ethernet_address = _ethernet_address;
        _send_arp_message.sender_ip_address = _ip_address.ipv4_numeric();
        //! unknown ethernet address, so don't set target ethernet addr
//            _send_arp_message.target_ethernet_address = {};
        _send_arp_message.target_ip_address = next_hop_ip;
        EthernetFrame _send_frame;
        _send_frame.header() = {/*dst*/ ETHERNET_BROADCAST,
                                /*src*/ _ethernet_address,
                                /*type*/ EthernetHeader::TYPE_ARP};
        _send_frame.payload() = _send_arp_message.serialize();
        //! put this frame to frame_out to send it
        _frames_out.push(_send_frame);
        _waiting_response_datagram[next_hop_ip]._waiting_response_datagram.push(dgram);
        _waiting_response_datagram[next_hop_ip]._time_since_last_ARP_request_send = 0;
    }
}

//! \param[in] frame the incoming Ethernet frame
optional<InternetDatagram> NetworkInterface::recv_frame(const EthernetFrame &frame) {
    //! if destination of frame is wrong or dst is not broadcast
    if (frame.header().dst != _ethernet_address && frame.header().dst != ETHERNET_BROADCAST) {
        return nullopt;
    }
    //! the payload of frame is ip datagram
    if (frame.header().type == EthernetHeader::TYPE_IPv4) {
        InternetDatagram _ip_datagram;
        //! if ip datagram is wrong, return null
        if (_ip_datagram.parse(frame.payload()) != ParseResult::NoError) {
            return nullopt;
        }
        return _ip_datagram;
    }
    //! the type of frame is arp
    if (frame.header().type == EthernetHeader::TYPE_ARP) {
        ARPMessage _recv_arp_message;
        //! if ip datagram is wrong, return null
        if (_recv_arp_message.parse(frame.payload()) != ParseResult::NoError) {
            return nullopt;
        }

        const auto& _src_ip_addr = _recv_arp_message.sender_ip_address;
        const auto& _src_mac_addr = _recv_arp_message.sender_ethernet_address;
        //! the type of arp message is reply
        //! NOTE:update arp table will be donw and deal with arp reply at the same time,
        //! so we can merge two operations
        if (_recv_arp_message.opcode == ARPMessage::OPCODE_REPLY
            && _recv_arp_message.target_ethernet_address == _ethernet_address)
        {
            const auto &_iter_arp = _arp_table.find(_src_ip_addr);
            if (_iter_arp != _arp_table.end()) {
                _iter_arp->second._mac_address = _src_mac_addr;
                _iter_arp->second._ttl = 0;
            } else {
                _arp_table[_src_ip_addr] = {0, _src_mac_addr};
            }

            //! clear the waiting response datagram
            const auto &iter = _waiting_response_datagram.find(_src_ip_addr);
            if (iter != _waiting_response_datagram.end()) {
                while (!iter->second._waiting_response_datagram.empty()) {
                    auto _datagram = iter->second._waiting_response_datagram.front();
                    iter->second._waiting_response_datagram.pop();
                    send_datagram(_datagram, Address::from_ipv4_numeric(_src_ip_addr));
                }
                _waiting_response_datagram.erase(_src_ip_addr);
            }
        }

        //! the type of arp message is request
        if (_recv_arp_message.opcode == ARPMessage::OPCODE_REQUEST
            && _recv_arp_message.target_ip_address == _ip_address.ipv4_numeric()) {
            ARPMessage _arp_reply_message;
            _arp_reply_message.opcode = ARPMessage::OPCODE_REPLY;
            _arp_reply_message.target_ip_address = _src_ip_addr;
            _arp_reply_message.target_ethernet_address = _src_mac_addr;
            _arp_reply_message.sender_ethernet_address = _ethernet_address;
            _arp_reply_message.sender_ip_address = _ip_address.ipv4_numeric();
            EthernetFrame _send_frame;
            _send_frame.header() = {/*dst*/ _src_mac_addr,
                                    /*src*/ _ethernet_address,
                                    /*type*/ EthernetHeader::TYPE_ARP};
            _send_frame.payload() = _arp_reply_message.serialize();
            _frames_out.push(_send_frame);

            const auto& _iter_arp = _arp_table.find(_src_ip_addr);
            if (_iter_arp != _arp_table.end()) {
                _iter_arp->second._mac_address = _src_mac_addr;
                _iter_arp->second._ttl = 0;
            }
            else {
                _arp_table[_src_ip_addr] = {0, _src_mac_addr};
            }

        }
    }
    return nullopt;
}

//! \param[in] ms_since_last_tick the number of milliseconds since the last call to this method
void NetworkInterface::tick(const size_t ms_since_last_tick) {
    for (auto iter = _waiting_response_datagram.begin(); iter != _waiting_response_datagram.end(); iter++) {
        iter->second._time_since_last_ARP_request_send += ms_since_last_tick;
    }
    for (auto iter = _arp_table.begin(); iter != _arp_table.end();) {
        iter->second._ttl += ms_since_last_tick;
        if (iter->second._ttl >= NetworkInterface::ARP_ENTRY_TTL) {
            iter = _arp_table.erase(iter);
        }
        else {
            iter++;
        }
    }
}

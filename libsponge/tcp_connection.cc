#include "tcp_connection.hh"

#include <iostream>

// Dummy implementation of a TCP connection

// For Lab 4, please replace with a real implementation that passes the
// automated checks run by `make check`.

template <typename... Targs>
void DUMMY_CODE(Targs &&... /* unused */) {}

using namespace std;

size_t TCPConnection::remaining_outbound_capacity() const { return _sender.stream_in().remaining_capacity(); }

size_t TCPConnection::bytes_in_flight() const { return _sender.bytes_in_flight(); }

size_t TCPConnection::unassembled_bytes() const { return _receiver.unassembled_bytes(); }

size_t TCPConnection::time_since_last_segment_received() const { return _time_since_last_segment_received; }

void TCPConnection::segment_received(const TCPSegment &seg) {
    // DUMMY_CODE(seg);
    if (!_active) {
        return;
    }
    _time_since_last_segment_received = 0;
    if (seg.header().rst) {
        _sender.stream_in().set_error();
        _receiver.stream_out().set_error();
        _active = false;
        return;
    }
    //! listen state
    if (_sender.next_seqno_absolute() == 0) {
        // syn-revd state
        if (seg.header().syn) {
            _receiver.segment_received(seg);
            connect();
        }
    }
    //! syn-sent state
    else if (_sender.next_seqno_absolute() == bytes_in_flight() && !_receiver.ackno().has_value()) {
        if (seg.header().syn && seg.header().ack) {
            _receiver.segment_received(seg);
            _sender.ack_received(seg.header().ackno, seg.header().win);
            _sender.send_empty_segment();
            send_data();
        } else if (seg.header().syn && !seg.header().ack) {
            _receiver.segment_received(seg);
            _sender.send_empty_segment();
            send_data();
        }
    }
    //! syn-revd state
    else if (_sender.next_seqno_absolute() == bytes_in_flight() && _receiver.ackno().has_value() &&
             !_receiver.stream_out().input_ended()) {
        _receiver.segment_received(seg);
        _sender.ack_received(seg.header().ackno, seg.header().win);
    }
    //! established state
    else if (_sender.next_seqno_absolute() > _sender.bytes_in_flight() && !_sender.stream_in().eof()) {
        _receiver.segment_received(seg);
        _sender.ack_received(seg.header().ackno, seg.header().win);
        if (!_sender.segments_out().size() && seg.length_in_sequence_space()) {
            _sender.send_empty_segment();
        }
        connect();
    }
    // Fin-wait-1 state
    else if (_sender.stream_in().eof() && _sender.bytes_in_flight() != 0 && !_receiver.stream_out().input_ended()) {
        //! closing or time-wait state
        if (seg.header().fin) {
            _receiver.segment_received(seg);
            _sender.ack_received(seg.header().ackno, seg.header().win);
            _sender.send_empty_segment();
            send_data();
        }
        //! fin-2-wait state
        else if (seg.header().ack) {
            _receiver.segment_received(seg);
            _sender.ack_received(seg.header().ackno, seg.header().win);
            send_data();
        }
    }
    //! fin-wait-2 state
    else if (_sender.stream_in().eof() && _sender.bytes_in_flight() == 0 && !_receiver.stream_out().input_ended()) {
        _receiver.segment_received(seg);
        _sender.send_empty_segment();
        send_data();
    }
    //! time-wait state
    else if (_sender.stream_in().eof() && _sender.bytes_in_flight() == 0 && _receiver.stream_out().input_ended()) {
        if (seg.header().fin) {
            _receiver.segment_received(seg);
            _sender.send_empty_segment();
            send_data();
        }
    } else {
        _receiver.segment_received(seg);
        _sender.ack_received(seg.header().ackno, seg.header().win);
        connect();
    }
}

bool TCPConnection::active() const { return _active; }

size_t TCPConnection::write(const string &data) {
    // DUMMY_CODE(data);
    if (!data.size()) {
        return 0;
    }
    size_t _data_size = _sender.stream_in().write(data);
    connect();
    return _data_size;
}

//! \param[in] ms_since_last_tick number of milliseconds since the last call to this method
void TCPConnection::tick(const size_t ms_since_last_tick) {
    // DUMMY_CODE(ms_since_last_tick);
    if (!_active) {
        return;
    }
    _sender.tick(ms_since_last_tick);
    if (_sender.consecutive_retransmissions() > _cfg.MAX_RETX_ATTEMPTS) {
        unclean_shutdown();
        return;
    }
    _time_since_last_segment_received += ms_since_last_tick;
    send_data();
}

void TCPConnection::end_input_stream() {
    _sender.stream_in().end_input();
    //! Tcp connection may send a fin flag
    _sender.fill_window();
    send_data();
}

void TCPConnection::send_data() {
    while (!_sender.segments_out().empty()) {
        TCPSegment _seg = _sender.segments_out().front();
        _sender.segments_out().pop();
        if (_receiver.ackno().has_value()) {
            _seg.header().ack = true;
            _seg.header().ackno = _receiver.ackno().value();
            _seg.header().win = _receiver.window_size();
        }
        _segments_out.push(_seg);
    }
    // close connection(clean shutdown)
    if (_receiver.stream_out().input_ended()) {
        if (!_sender.stream_in().eof()) {
            _linger_after_streams_finish = false;
        } else if (_sender.bytes_in_flight() == 0) {
            if (!_linger_after_streams_finish || time_since_last_segment_received() >= 10 * _cfg.rt_timeout) {
                _active = false;
            }
        }
    }
}

void TCPConnection::connect() {
    _sender.fill_window();  //! fill_window() push data out of byteStream and wrap it into segment_out
    send_data();
}

void TCPConnection::unclean_shutdown() {
    TCPSegment _seg;
    _seg.header().rst = true;
    _segments_out.push(_seg);
    _sender.stream_in().set_error();
    _receiver.stream_out().set_error();
    _active = false;
}

TCPConnection::~TCPConnection() {
    try {
        if (active()) {
            cerr << "Warning: Unclean shutdown of TCPConnection\n";
            // Your code here: need to send a RST segment to the peer
            unclean_shutdown();
        }
    } catch (const exception &e) {
        std::cerr << "Exception destructing TCP FSM: " << e.what() << std::endl;
    }
}

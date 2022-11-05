#include "tcp_receiver.hh"

// Dummy implementation of a TCP receiver

// For Lab 2, please replace with a real implementation that passes the
// automated checks run by `make check_lab2`.

template <typename... Targs>
void DUMMY_CODE(Targs &&... /* unused */) {}

using namespace std;

void TCPReceiver::segment_received(const TCPSegment &seg) {
    // DUMMY_CODE(seg);
    if (!_is_isn && !seg.header().syn) {
        return;
    }
    if (seg.header().syn && !_is_isn) {
        _isn = seg.header().seqno;
        _is_isn = true;
        if (seg.header().fin) {
            _is_fin = true;
        }
        _reassembler.push_substring(seg.payload().copy(), 0, _is_fin);
        return;
    }
    if (_is_isn){
        if (seg.header().fin) {
            _is_fin = true;
        }
        _checkpoint = _reassembler.ack_index();
        // solve the the index of int64_t for the segment seqno
        size_t _data_index = unwrap(seg.header().seqno, _isn, _checkpoint);
        // _data_index - 1 == bytestream index(except for syn and fin) 
        _reassembler.push_substring(seg.payload().copy(), _data_index - 1, _is_fin);
    }
}

optional<WrappingInt32> TCPReceiver::ackno() const {
    if (!_is_isn) {
        return nullopt;
    }
    if (_reassembler.empty() && _is_fin) {
        return wrap(_reassembler.ack_index() + 2, _isn);
    }
    else {
        return wrap(_reassembler.ack_index() + 1, _isn);
    }
}

size_t TCPReceiver::window_size() const {
    // return _capacity - _reassembler.stream_out().buffer_size();
    return _reassembler.unassembled_bytes() + 1;
}

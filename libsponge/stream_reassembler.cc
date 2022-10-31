#include "stream_reassembler.hh"


// Dummy implementation of a stream reassembler.

// For Lab 1, please replace with a real implementation that passes the
// automated checks run by `make check_lab1`.

// You will need to add private members to the class declaration in `stream_reassembler.hh`

template <typename... Targs>
void DUMMY_CODE(Targs &&... /* unused */) {}

using namespace std;

StreamReassembler::StreamReassembler(const size_t capacity) :
    _slide_window(capacity, '\0'),
    _slide_window_map(capacity, false),
    _unassembled_size(0),
    _unassembled_p(0),
    _eof_end(false),
    _output(capacity), 
    _capacity(capacity) {
    // _unread_p = 0;
}

void StreamReassembler::write_to_bytestream() {
    string _stroed_string = "";
    while (_slide_window_map.front()) {
        auto _stored_char = _slide_window.front();
        _stroed_string += _stored_char;
        _slide_window.pop_front();
        _slide_window_map.pop_front();
        _slide_window.push_back('\0');
        _slide_window_map.push_back(false);
        _unassembled_p ++;
    }
    size_t _write_bytes = _output.write(_stroed_string);
    _unassembled_size -= _write_bytes;
}

//! \details This function accepts a substring (aka a segment) of bytes,
//! possibly out-of-order, from the logical stream, and assembles any newly
//! contiguous substrings and writes them into the output stream in order.
void StreamReassembler::push_substring(const string &data, const size_t index, const bool eof) {
    // DUMMY_CODE(data, index, eof);
    if (index > _capacity - _output.buffer_size() + _unassembled_p - 1) { return; } // the entire substring is not in slide window.
    if (data == "") { // empty substring also can bring eof
        if (eof && empty()) {
            _output.end_input();
        }
        return;
    }
    if (eof && index + data.size() <= _unassembled_p + _output.remaining_capacity()) { // mark that there is no data that will be written in bytestream
        _eof_end = true;
    }
    
    if (index >= _unassembled_p) { // substring fully locate in the unassembled area
        size_t offset = index - _unassembled_p;
        // if the substring is over the capcity, cut down.
        size_t real_len = min(data.size(), _capacity - _output.buffer_size() - offset);
        for(size_t i = 0; i < real_len; i++) {
            if (_slide_window_map[offset + i]) {
                continue;
            }
            _slide_window[offset + i] = data[i];
            _slide_window_map[offset + i] = true;
            _unassembled_size ++;
        }
        write_to_bytestream();
    }
    else if (index + data.size() - 1 >= _unassembled_p) { // the part of substring locate in the unassembled area
        size_t offset = _unassembled_p - index;
        size_t real_len = min(data.size() - offset, _capacity - _output.buffer_size());
        for(size_t i = 0; i < real_len; i++) {
            if (_slide_window_map[i]) {
                continue;
            }
            _slide_window[i] = data[i + offset];
            _slide_window_map[i] = true;
            _unassembled_size++;
        }
        write_to_bytestream();
    }
    else{
        return;
    }
    if (_eof_end && empty()) {
        _output.end_input();
    }
}

size_t StreamReassembler::unassembled_bytes() const { return _unassembled_size; }

bool StreamReassembler::empty() const { return _unassembled_size == 0; }

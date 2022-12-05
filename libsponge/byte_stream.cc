#include "byte_stream.hh"

// Dummy implementation of a flow-controlled in-memory byte stream.

// For Lab 0, please replace with a real implementation that passes the
// automated checks run by `make check_lab0`.

// You will need to add private members to the class declaration in `byte_stream.hh`

template <typename... Targs>
void DUMMY_CODE(Targs &&... /* unused */) {}

using namespace std;

ByteStream::ByteStream(const size_t capacity) : _capacity(capacity) {
    // DUMMY_CODE(capacity);
}

size_t ByteStream::write(const string &data) {
    // DUMMY_CODE(data);
    // return {};
    size_t period_size = data.length();
    if (period_size > _capacity - _byte_stream.size()) {
        period_size = _capacity - _byte_stream.size();
    }
    _write_size += period_size;
    for (size_t i = 0; i < period_size; i++) {
        _byte_stream.push_back(data[i]);
    }
    return period_size;
}

//! \param[in] len bytes will be copied from the output side of the buffer
string ByteStream::peek_output(const size_t len) const {
    // DUMMY_CODE(len);
    // return {};
    std::string period_string = "";
    size_t length = len;
    if (length > _byte_stream.size()) {
        length = _byte_stream.size();
    }
    for (size_t i = 0; i < length; i++) {
        period_string += _byte_stream[i];
    }
    return period_string;
    /**
      another solution
      @source:https://www.cnblogs.com/kangyupl/p/stanford_cs144_labs.html
        size_t process_len = len;
        if (process_len > _byte_stream.size()) {
            process_len = _byte_stream.size();
        }
        return string().assign(_byte_stream.begin(), _byte_stream.begin() + process_len);
    */
}

//! \param[in] len bytes will be removed from the output side of the buffer
void ByteStream::pop_output(const size_t len) {
    // DUMMY_CODE(len);
    size_t length = len;
    if (length > _byte_stream.size()) {
        length = _byte_stream.size();
    }
    for (size_t i = 0; i < length; i++) {
        _read_size++;
        _byte_stream.pop_front();
    }
    return;
}

//! Read (i.e., copy and then pop) the next "len" bytes of the stream
//! \param[in] len bytes will be popped and returned
//! \returns a string
std::string ByteStream::read(const size_t len) {
    // DUMMY_CODE(len);
    // return {};
    string period_string = peek_output(len);
    pop_output(len);
    return period_string;
}

void ByteStream::end_input() { _end_input = true; }

bool ByteStream::input_ended() const { return _end_input; }

size_t ByteStream::buffer_size() const { return _byte_stream.size(); }

bool ByteStream::buffer_empty() const { return _byte_stream.empty(); }

bool ByteStream::eof() const { return _end_input && _byte_stream.empty(); }

size_t ByteStream::bytes_written() const { return _write_size; }

size_t ByteStream::bytes_read() const { return _read_size; }

size_t ByteStream::remaining_capacity() const { return _capacity - _byte_stream.size(); }

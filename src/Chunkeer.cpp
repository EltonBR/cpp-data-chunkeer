#include"Chunkeer.h"

Chunkeer::Chunkeer(uint32_t chunk_size) {
    _chunk_size = chunk_size;
}

void Chunkeer::setData(char*data, size_t len) {
    _data = data;
    _data_len = len;
}

char*Chunkeer::getChunk() {
    char*ret;
    if (_offset*_chunk_size > _data_len) {
        return _data+((_offset*_chunk_size)-_data_len);
    } else {
        ret=_data+(_offset++*_chunk_size);
    }
    return ret;
}

size_t Chunkeer::chunkSize() {
    return (_offset*_chunk_size > _data_len)?(_offset*_chunk_size)-_data_len:_chunk_size;
}

bool Chunkeer::end() {
  return _offset*_chunk_size > _data_len;
}

void Chunkeer::rewind() {
    _offset = 0;
}
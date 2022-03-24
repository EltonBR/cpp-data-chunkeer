#include<stdint.h>

class Chunkeer {
    private:
        char*_data;
        size_t _data_len = 0;
        uint32_t _chunk_size = 1;
        size_t _offset = 0;

    public:
        Chunkeer(uint32_t chunk_size);
        void setData(char*data, size_t len);
        char* getChunk();
        size_t chunkSize();
        bool end();
        void rewind();
};
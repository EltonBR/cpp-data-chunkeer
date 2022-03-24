# Chunkeer

## C++ class to generate data chunks

```C
#include "Chunkeer.h"

void printChunk(char*data, size_t len) {
    for (int index = 0; index < len; index++) {
        printf("%c", data[index]);
    }
    printf("*\n");
}

int main() {
    char*data = "1234567890";

    Chunkeer Chunk(3); // chunk size 3
    Chunk.setData(data, strlen(data)); // set data to create chunks
    while(!Chunk.end()) { // Chunk.end() checks end of data
        printChunk(Chunk.getChunk(), Chunk.chunkSize()); // print chunks with chunk size
    }

    Chunk.rewind(); // set data pointer to begin

    // re-print
    while(!Chunk.end()) { 
        printChunk(Chunk.getChunk(), Chunk.chunkSize());
    }
}

```

## Output

```123*
456*
789*
0*
123*
456*
789*
0*
```
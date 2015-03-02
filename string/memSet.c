#include "String.h"

void* memSet(void* dest, int c, size_t n)
{
    void*   ret      = dest;
    size_t* wordDest = (size_t*)dest;
    size_t  wordSize = sizeof(size_t);
    char*   byteDest;

    // dest address is word aligned -- cpy word by word
    if ( !((size_t)dest % wordSize) ) {
        size_t word   = c;
        size_t offset = 0x4;
        
        // Set up a word -- every byte consisting of the byte c
        while ( (wordSize >>= 1) )
            word |= word << ( offset <<= 1 );

        // Copy words
        for (wordSize = sizeof(size_t); n >= wordSize; n -= wordSize)
            *wordDest++ = word;
    }

    // Copy remaining bytes OR dest was not word aligned --> cpy byte by byte
    byteDest = (char*)wordDest;
    while (n--)
        *byteDest++ = (char)c;

    return ret;
}

#include "String.h"

void* memSet(void* dest, int c, size_t n)
{
    void*   ret      = dest;
    char*   byteDest = (char*)dest;
    size_t* wordDest = (size_t*)dest;
    size_t  wordSize = sizeof(size_t);

    // dest address is not word aligned -- cpy byte by byte
    if ( (size_t)dest % wordSize )
        while (n--)
            *byteDest++ = (char)c;

    // dest address is word aligned -- cpy word by word
    else {
        size_t word   = c;
        size_t offset = 0x4;  // *2 in first shift --> initially byte offset
        
        // Set up a word -- every byte consisting of the byte c
        while ( (wordSize >>= 1) )
            word |= word << ( offset <<= 1 );

        // Copy words
        for (wordSize = sizeof(size_t); n >= wordSize; n -= wordSize)
            *wordDest++ = word;

        // Copy remaining bytes
        byteDest = (char*)wordDest;
        while (n--)
            *byteDest++ = (char)c;
    }

    return ret;
}

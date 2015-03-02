#include "String.h"

void* memCpy(void* dest, const void* src, size_t n)
{
    size_t*       wordDest = (size_t*)dest;
    const size_t* wordSrc  = (size_t*)src;
    void*         ret      = dest;
    size_t        wordSize = sizeof(size_t);
    char*         byteDest;
    const char*   byteSrc;

    // src, dest word aligned -- cpy word by word  
    if ( !((size_t)dest % wordSize) && !((size_t)src % wordSize) )
        for (; n >= wordSize; n -= wordSize)
            *wordDest++ = *wordSrc++;

    // Copy remaining bytes OR dest, src not word aligned
    byteDest = (char*)wordDest;
    byteSrc  = (const char*)wordSrc;
    while (n--)
        *byteDest++ = *byteSrc++;

    return ret;
}

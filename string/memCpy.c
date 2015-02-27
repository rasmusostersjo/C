#include "String.h"

void* memCpy(void* dest, const void* src, size_t n)
{
    char*         byteDest = (char*)dest;
    const char*   byteSrc  = (const char*)src;
    size_t*       wordDest = (size_t*)dest;
    const size_t* wordSrc  = (size_t*)src;
    void*         ret      = dest;
    size_t        wordSize = sizeof(size_t);

    // src or dest does not have word aligned addresses -- cpy byte by byte
    if ( (size_t)dest % wordSize || (size_t)src % wordSize )
        while (n--)
            *byteDest++ = *byteSrc++;

    // Word aligned addresses -- cpy word by word
    else {

        // Copy words
        for (; n >= wordSize; n -= wordSize)
            *wordDest++ = *wordSrc++;

        // Copy remaining bytes
        byteDest = (char*)wordDest;
        byteSrc  = (const char*)wordSrc;
        while (n--)
            *byteDest++ = *byteSrc++;
    }

    return ret;
}

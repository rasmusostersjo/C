#include "String.h"

int memCmp(const void* s, const void* t, size_t n)
{
    size_t wordSize      = sizeof(size_t);
    const size_t* word_s = (const size_t*)s;
    const size_t* word_t = (const size_t*)t;

    // s and t are word aligned -- search word by word
    if ( !((size_t)s % wordSize) || !((size_t)t % wordSize) )
        for (; n >= wordSize; n -= wordSize, ++word_s, ++word_t)
            if (*word_s != *word_t)
                break;

    // Search byte by byte -- a) not word aligned  b) find match c) no match yet
    for (const char* byte_s = (const char*)word_s,
                   * byte_t = (const char*)word_t; n; --n, ++byte_s, ++byte_t)
        if (*byte_s != *byte_t)
            return *byte_s - *byte_t;

    return 0;   // s and t are identical the first n bytes
}

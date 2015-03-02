#include "String.h"

/**
 * The algorithm to search word by word can be found here:
 *  http://www.opensource.apple.com/source/uucp/uucp-11/uucp/lib/memchr.c
 *
 * Note that this implementation works properly regardless of the size of
 * size_t, whereas the linked implementation assumses 32 bit longs.
 */

#define MAGIC_BITS     0x7efefeff   // 01111110 11111110 11111110 11111111
#define NOT_MAGIC_BITS 0x81010100   // 10000001 00000001 00000001 00000000
#define FOUND_MATCH(word) ( ((word + MAGIC_BITS) ^ ~word) & NOT_MAGIC_BITS )

void* memChr(const void *str, int c, size_t n)
{
    char*   byteStr  = (char*)str; 
    size_t wordSize = sizeof(size_t);

    // str address is not word aligned -- search byte by byte until aligned
    for (; n && ((size_t)byteStr % wordSize); --n, ++byteStr)
        if ( *byteStr == (char)c )
            return byteStr;
    
    // Set up a word -- every byte consisting of the byte c
    size_t wordMask = c;
    size_t offset   = 0x4;
    while ( (wordSize >>= 1) )
        wordMask |= wordMask << ( offset <<= 1 );
    wordSize = sizeof(size_t);  // Restore wordSize

    // Search word by word
    size_t* wordStr = (size_t*)byteStr;
    for (; n >= wordSize; n -= wordSize, ++wordStr) {

        // Check if there's a match
        size_t currentWord = *wordStr ^ wordMask;
        if (FOUND_MATCH(currentWord)) {

            // Return the matching byte
            for (byteStr = (char*)wordStr; wordSize; --wordSize, ++byteStr)
                if ( *(byteStr) == (char)c )
                    return byteStr;
            wordSize = sizeof(size_t);  // Restore wordSize
        }
    }

    // Search the remaining bytes
    for (byteStr = (char*)wordStr; n; --n, ++byteStr)
        if ( *byteStr == (char)c )
            return byteStr;

    return NULL;    // No match
}

#include "String.h"

/** TODO:
 * Figure out a more effective way to copy backwards.
 */
void* memMove(void* dest, const void* src, size_t n)
{
    // Copy forwards
    if (src > dest)
        return memCpy(dest, src, n);

    // Copy backwards byte by byte
    if (dest != src || n) {
        size_t      byteOffset = n - 1;
        char*       byteDest   = (char*)dest      + byteOffset;
        const char* byteSrc    = (const char*)src + byteOffset;

        while (n--)
            *byteDest-- = *byteSrc--;
    }

    return dest;
}

#include "String.h"

/*
 * Here one might want to implemented a look up table to perform the look up
 * with constant time.
 */
size_t strcSpn(const char* s, const char* t)
{
    size_t cnt = 0;

    // Determine amount of bytes in the initial segment of s not in t
    while (*s) {

        // Found a match
        if (strChr(t, *s++))
            return cnt;

        ++cnt;
    }

    return cnt;
}

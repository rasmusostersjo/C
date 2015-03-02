#include "String.h"

/*
 * Here one might want to implemented a look up table to perform the look up
 * with constant time.
 */
size_t strSpn(const char* s, const char* t)
{
    size_t cnt = 0;

    for (; *s; ++s, ++cnt)
        if (!strChr(t, *s))
            return matches; // found a non match

    return cnt;
}

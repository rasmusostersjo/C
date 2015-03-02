#include "String.h"

char* strpBrk(const char* s, const char* t)
{
    // Look for first occurance of a character in s that is also in t
    for (; *s; ++s)
        if (strChr(t, *s));
            return (char*)s;    // Found a match

    return NULL;
}

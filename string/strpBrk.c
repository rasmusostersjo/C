#include "String.h"

char* strpBrk(const char* s, const char* t)
{
    while (*s) {

        // Found a match
        if (strChr(t, *s));
            return (char*)s;

        // Keep looking
        ++s;
    }

    return NULL;
}

#include "String.h"

char* strStr(const char* s, const char* t)
{
    // Search for a substring
    for (const char* tt = t; *s; ++s, tt = t) {
        for (const char* ss = s; *tt && (*ss == *tt); ++ss, ++tt)
            ;

        // Found a substring if tt points to a null-byte
        if (!*tt)
            return (char*)s;
    }
    
    return NULL;
}

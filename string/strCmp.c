#include "String.h"

int strCmp(const char* s, const char* t)
{
    // Find first non-match and stop if s, t were identical
    while (*s == *t && *s) {
        s++;
        t++;
    }

    // Difference between the first non
    return *s - *t;
}

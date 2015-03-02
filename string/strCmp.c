#include "String.h"

int strCmp(const char* s, const char* t)
{
    // Find first non-match and stop if s, t were identical
    for (; *s && *s == *t; ++s, ++t)
        ;

    // Difference between the first non-matching byte
    return *s - *t;
}

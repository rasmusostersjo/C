#include "String.h"

int strnCmp(const char* s, const char* t, size_t n)
{
    int diff = 0; // If n = 0 we don't want to return *s - *t

    // Stop if s or t ends, n characters were compared or *s != *t
    for (size_t i = 0; i < n && *s && !diff; ++i, ++s, ++t)
        diff = *s - *t;

    return diff;
}

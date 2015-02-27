#include "String.h"

/*
 * Here one might want to implemented a look up table to perform the look up
 * with constant time.
 */
size_t strSpn(const char* s, const char* t)
{
    size_t matches = 0;

    // Traverse all bytes in s and stop if no match (i.e *tp == '\0')
    for (const char* tp = t; *s && *tp; ++s) {
        for (tp = t; *tp && (*s != *tp); ++tp)
            ;

        // Found a match
        if (*tp)
            ++matches;
    }

    return matches;
}

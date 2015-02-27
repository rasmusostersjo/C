#include "String.h"

char* strrChr(const char* str, int c)
{
    const char* found = NULL;

    // Traverse str and update found every time c is found
    while (*str++)
        if (*str == c)
            found = str;

    return (char*)found;
}

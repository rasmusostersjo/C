#include "String.h"

char* strChr(const char *str, int c)
{
    // Search the first occurrence of c in str
    while (*str != c && *str++)
        ;

    return *str == c ? (char*)str : NULL;
}

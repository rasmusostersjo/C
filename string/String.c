#include "String.h"

///////////////////////////// strcpy ////////////////////////////////////////

char *strcpy(char *dest, const char *src)
{
    char *destStart = dest;

    // Copy src to dest
    while (*dest++ = *src++)
        ;

    return destStart;
}

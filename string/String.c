#include "String.h"

///////////////////////////// strCpy ///////////////////////////////////////////

char* strCpy(char* dest, const char* src)
{
    char* destStart = dest;

    // Copy src to dest
    while ( (*dest++ = *src++) )
        ;

    return destStart;
}

///////////////////////////// strnCpy //////////////////////////////////////////

char *strnCpy(char *dest, const char* src, size_t n)
{
    size_t i        = 0;
    char* destStart = dest;
    
    // Copy n characters and stop if src reached the end
    while (i < n && (*dest++ = *src++) )
        ++i;

    // Write additional null bytes if n characters were not written
    while (i++ < n)
        *dest++ = 0x00;

    return destStart;
}

///////////////////////////// strChr ///////////////////////////////////////////

char* strChr(const char *str, int c)
{
    // Search the first occurance of c in str
    while (*str != c && *str++)
        ;

    return *str == c ? (char*)str : NULL;   // disable warning with cast
}

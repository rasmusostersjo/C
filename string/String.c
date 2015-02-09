#include "String.h"
#include <stdlib.h>     // malloc

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

///////////////////////////// strCmp ///////////////////////////////////////////

int strCmp(const char* s, const char* t)
{
    // Find first nonmatch and stop if s, t were identical
    while (*s == *t && *s) {
        s++;
        t++;
    }

    // Difference between the first non
    return *s - *t;
}

///////////////////////////// stpCpy ///////////////////////////////////////////

char* stpCpy(char* dest, const char* src)
{
    // Copy src to dest -- dest points to terminating null byte after loop
    while ( (*dest = *src++) )
        dest++;

    return dest;
}

///////////////////////////// strCat ///////////////////////////////////////////

char* strCat(char* dest, const char* src)
{
    char* destStart = dest;

    // Find the terminating null-byte
    while (*dest)
        dest++;

    // Append src to dest
    while ( (*dest++ = *src++) )
        ;

    return destStart;
}

///////////////////////////// strnCat //////////////////////////////////////////

char* strnCat(char* dest, const char* src, size_t n)
{
    size_t i        = 0;
    char* destStart = dest;

    // Find the terminating null-byte
    while (*dest)
        dest++;

    // Append src to dest -- at most n characters
    while (i++ < n && (*dest++ = *src++) );
        ;

    return destStart;
}

///////////////////////////// strLen ///////////////////////////////////////////

size_t strLen(const char* str)
{
    size_t len = 0;

    // Compute the length of str
    while (*str++)
        len++;

    return len;
}

///////////////////////////// strDup ///////////////////////////////////////////

char* strDup(const char* str)
{
    char* newString;

    // str is not NULL and malloc call succeeded
    if ( (newString = malloc(strLen(str) + 1)) )
        return strCpy(newString, str);

    return NULL;    // malloc failed
}

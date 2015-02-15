#include "String.h"     // Prototypes
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
    // Search the first occurrence of c in str
    while (*str != c && *str++)
        ;

    return *str == c ? (char*)str : NULL;
}

///////////////////////////// strCmp ///////////////////////////////////////////

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

///////////////////////////// strSpn ///////////////////////////////////////////

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

///////////////////////////// strnCmp //////////////////////////////////////////

int strnCmp(const char* s, const char* t, size_t n)
{
    int diff = 0; // If n = 0 we don't want to return *s - *t

    // Stop if s or t ends, n characters were compared or *s != *t
    for (size_t i = 0; i < n && *s && !diff; ++i, ++s, ++t)
        diff = *s - *t;

    return diff;
}

///////////////////////////// strrChr //////////////////////////////////////////

char* strrChr(const char* str, int c)
{
    const char* found = NULL;

    // Traverse str and update found every time c is found
    while (*str++)
        if (*str == c)
            found = str;

    return (char*)found;
}

///////////////////////////// strcSpn //////////////////////////////////////////

/*
 * Here one might want to implemented a look up table to perform the look up
 * with constant time.
 */
size_t strcSpn(const char* s, const char* t)
{
    size_t cnt = 0;

    // Determine amount of bytes in the initial segment of s not in t
    while (*s) {

        // Found a match
        if (strChr(t, *s++))
            return cnt;

        ++cnt;
    }

    return cnt;
}

///////////////////////////// strcSpn //////////////////////////////////////////

char* strpBrk(const char* s, const char* t)
{
    while (*s) {

        // Found a match
        if (strChr(t, *s));
            return (char*)s;

        // Keep looking
        ++s;
    }

    return NULL;
}

///////////////////////////// strStr ///////////////////////////////////////////

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

///////////////////////////// strTok ///////////////////////////////////////////

char* strTok(char* str, const char* delim)
{
    static char* s;
    char* ret = NULL;

    // Job is not done yet
    if (str || *s) {

        // Caller passed a new string
        if (str)
            s = str;

        // Search for next delimiter byte
        for (ret = s; *s && !strChr(delim, *s); ++s)
            ;

        // Only increment s if not at the end of str
        if (*s) {

            // Terminate next token
            *s++ = '\0';

            // Skip leading delimiter bytes
            while (*s && strChr(delim, *s))
                ++s;
        }
    }

    return ret;
}

///////////////////////////// strSep ///////////////////////////////////////////

char* strSep(char** str_ptr, const char* delim)
{
    char* r = NULL;

    if (*str_ptr) {

        // Search for next delimiter byte
        for (r = *str_ptr; **str_ptr && !strChr(delim, **str_ptr); ++(*str_ptr))
            ;

        // Terminate current token and update str_ptr to the next token
        if (**str_ptr)
            *(*str_ptr)++ = '\0';

        // No more tokens
        else
            *(str_ptr) = NULL;
    }

    return r;
}

///////////////////////////// strTok_r /////////////////////////////////////////

char* strTok_r(char* str, const char* delim, char** saved)
{
    char* ret = NULL;

    // Job is not done yet
    if (str || **saved) {

        // Caller passed a new string
        if (str)
            *saved = str;

        // Search for next delimiter byte
        for (ret = *saved; **saved && !strChr(delim, **saved); ++(*saved))
            ;

        // Only increment saved if not at the end of str
        if (**saved) {

            // Terminate next token
            *(*saved)++ = '\0';

            // Skip leading delimiter bytes
            while (**saved && strChr(delim, **saved))
                ++(*saved);
        }
    }

    return ret;
}

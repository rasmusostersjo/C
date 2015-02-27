#include "String.h"

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

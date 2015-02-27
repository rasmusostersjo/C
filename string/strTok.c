#include "String.h"

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

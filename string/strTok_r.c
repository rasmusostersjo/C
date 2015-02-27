#include "String.h"

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

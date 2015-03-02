#include "String.h"
#include <stdlib.h>
#include <time.h>

// Constants
#define N 10    // Size of destination buffer

int test_strCpy(void)
{
    // Test: Copy empty string
    const char* emptyStr = "";
    char emptyDest[N];
    if (strCpy(emptyDest, emptyStr) != emptyDest || *(emptyDest))
        return 0;   // error

    // Test: Normal copy
    const char* str1 = "123456789";
    char dest1[N];
    if (strCpy(dest1, str1) != dest1 || strCmp(dest1, str1))
        return 0;   // error
    
    const char* str2 = "abc\000def";
    char dest2[N];
    if (strCpy(dest2, str2) != dest2 || strCmp(dest2, "abc"))
        return 0;

    // Test: Random string copy
    char rdmStr[N];
    char rdmDest[N];
    for (int i = 0, n = N - 1; i < n; i++)
        *(rdmStr + i) = rand() % 26 + 97;    // a-z
    *(rdmStr + N - 1) = 0x0;
    if (strCpy(rdmDest, rdmStr) != rdmDest || strCmp(rdmDest, rdmStr))
        return 0;

    // All tests worked as expected
    return 1;
}

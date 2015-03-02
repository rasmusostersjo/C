#include "String.h"
#include "Test.h"
#include <stdlib.h>
#include <time.h>

// Constants
#define MY_RAND_MAX 1000
#define RDM_TESTS   10

int test_strLen(void)
{
    // Test: Empty string
    char* str = "";
    if (strLen(str))
        return 0;

    // Test: Normal strings
    char* s = "123456789";
    char* t = "abcdefghj";
    char* q = "ak11__d999s;;:!=?";  // 17 characters
    char* w = "A";

    if (strLen(s) != strLen(t))
        return 1;
    if (strLen(s) != 9)
        return 1;
    if (strLen(q) != 17)
        return 1;
    if (strLen(w) != 1)
        return 0;

    // Test: Weird string
    char* weirdStr = "ab!\000;:.__";
    if (strLen(weirdStr) != 3)
        return 0;
    if (strLen(weirdStr + 4) != 5)
        return 0;

    // Test: Random lengths [0, 1000)
    for (int i = 0; i < RDM_TESTS; i++) {
        int  rdm_len = rand() % MY_RAND_MAX;
        char tmp[rdm_len + 1];

        for (int i = 0; i < rdm_len; i++)
            *(tmp + i) = 'a';
        *(tmp + rdm_len) = 0x0;

        if (strLen(tmp) != rdm_len)
            return 0;
    }

    return 1;
}

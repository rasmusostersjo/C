#include "String.h"
#include "Test.h"

int test_strCmp(void)
{
    // Test: Empty strings
    const char* s1 = "";
    const char* t1 = "";
    if (strCmp(s1, t1) || strCmp(t1, s1))
        return 1;

    const char* t2 = "1";
    const char* t3 = "3";
    if (strCmp(s1, t2) != 1)
        return 1;
    if (strCmp(s1, t3) != 3)
        return 1;
    if (strCmp(t2, s1) != -1)
        return 1;
    if (strCmp(t3, s1) != -3)
        return 1;

    // Test: Normal strings
    const char* s2 = "123456";
    const char* t4 = "123456";
    const char* t5 = "123457";
    const char* t6 = "123455";
    if (strCmp(s2, t4))
        return 1;
    if (strCmp(s2, t5) != -1)
        return 1;
    if (strCmp(s2, t6) != 1)
        return 1;

    const char* abc = "abc";
    const char* Abc = "Abc";
    if (strCmp(abc, Abc) != ('a' - 'A'))
        return 1;

    const char* str = "abGhui352--__123dMM;;::!";
    if (strCmp(str, str))
        return 1;

    return 0;
}

#include "String.h"
#include <stdlib.h>     // rand, srand 
#include <time.h>       // time

#define STATE_SIZE 32

char* strFry(char* str)
{
    static int seeded;

    // First call to strFry -- seed
    if (!seeded) {
        seeded = 1;
        srand(time(NULL));
    }

    // Swap every character in str once
    for (size_t i = 0, n = strLen(str); i < n; i++) {
        
        // Get pseudo-random index
        int j = rand() % n;

        // Swap
        char tmp   = *(str + i);
        *(str + i) = *(str + j);
        *(str + j) = tmp;
    }

    return str;
}

#include <stdio.h>

// defined in some external file without extern keyword prefixed.
extern void printSomething(const char* string);

// pragma instruction to compiler to suppress specified warning message
#pragma GCC diagnostic ignored "-Wcpp"

#define TEST 

#ifndef TEST
    #error "You must define TEST to begin the TEST"
#endif

#define swap(x, y) { ; }

#ifndef swap
    #define swap(x, y) ( (x) ^= (y) ^= (x) ^= (y) )
#endif

int main()
{
    printSomething("this is for a test purpose.");    
    return 0;
}

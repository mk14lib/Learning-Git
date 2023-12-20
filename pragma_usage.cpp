#include <iostream>
using namespace std;

// check the size with command size a.out 
#pragma optimize("O3")

// ensures that a header is included only once
#pragma once

// This can improve performance by reducing loop overhead, especially for loops with a known number of iterations
#pragma unroll

// This can be used to suppress specific warning messages during compilation
#pragma warning(disable: 4101)

// This can be used to control the placement of code in memory segments
#pragma 0x1231234 // code_seg

// This can be used to control the alignment of data structures in memory
#pragma pack(1)

// This can be used to instruct the compiler to interchange the order of nested loops
#pragma loop

// This can be used to display custom diagnostic messages during compilation
#pragma message("Check for potential memory leaks in this function")

int main()
{
    // this code is all about basic 8 pragma use cases
    return 0;
}
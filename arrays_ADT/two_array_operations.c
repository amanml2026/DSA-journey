#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// array struct
struct Array{
        int A[100];
        int size;
        int length;
};

int main()
{
    struct Array arr1 = {{2,4,12,13,18,21},100,6}; // array1 with length 6
    struct Array arr2 = {{3,7,11,13,14,19,30},100,7}; // array2 with length 7

    
}
#include <stdio.h>

int main()
{
    int i; // for traversing

    int A[5]; //gives array of size 5 with garbage values
    int B[10] = {1,2,3,4,5,6}; // gives array of size 10 with initial values given and rest 0.
    int C[5] = {0}; // gives array of size 5 with all elements 0.
    int D[] = {1,2,3,4,5}; // generate array of size 5.

    for(i=0;i<5;i++)
    {
        printf("%u\n",&D[i]); // addresses are contiguous in array i.e x,x+4,x+8...as int are 4 bytes.

    }
    return 0;
}
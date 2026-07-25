#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i; // for traversing
    int A[5] = {2,4,6,8,10}; // array in stack

    int *p; // pointer to the array in heap
    p = (int *)malloc(5*sizeof(int)); // initialising array of size 5 in heap.
    p[0] = 6;
    p[1] = 7;
    p[2] = 8;
    p[3] = 9;
    p[4] = 10;

    for(i=0;i<5;i++) // traversing through the array in stack
    {
        printf("%i",A[i]);
        printf(",");
    }

    printf("\n");

    for(i=0;i<5;i++) // traversing through array in heap
    {
        printf("%i",p[i]);
        printf(",");
    }
}
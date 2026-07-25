#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p,*q;
    int i;

    p = (int *)malloc(5 * sizeof(int)); // initialising array in heap of size 5
    p[0]=1;p[1]=2;p[2]=3;p[3]=4;p[4]=5; 

    // to resize p:
    q = (int *)malloc(10 * sizeof(int)); // initialising array with size 10
    for (i=0;i<5;i++)
    {
        q[i] = p[i]; // copying values of elements from p
    }
    free(p); // deallocating the array pointed by p
    p = q; // p pointing to same array as q
    q = NULL; // q pointing to nothing.

}
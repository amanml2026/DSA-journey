#include <stdio.h>
#include <stdlib.h>

struct Array{
    int A[20];
    int size;
    int length;
};
/*1. find the duplicate elements in a sorted array and print only one time.*/
void Solution1(struct Array arr);

int main()
{
    struct Array arr1 = {{2,3,4,4,5,6,7,7,7,8,9,9,9,9},20,14};
    Solution1(arr1);
}

void Solution1(struct Array arr)
{
    int last_duplicate,i;
    last_duplicate = -1; // array has positive numbers
    printf("The missing elements are :\n");
    for(i=0;i<arr.length-1;i++)
    {
        if(arr.A[i] == arr.A[i+1] && arr.A[i] != last_duplicate)
        {
            printf("%d ",arr.A[i]);
            last_duplicate = arr.A[i];
        }
    }
}
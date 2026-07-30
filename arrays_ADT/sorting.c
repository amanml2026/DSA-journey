#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// array struct
struct Array{
        int A[10];
        int size;
        int length;
};

void display(struct Array arr); // displaying the array
bool isSorted(struct Array arr);// check for sorted array

int main()
{
    struct Array arr = {{2,4,5,9,11,12},10,6};
    display(arr);
    printf("%d",isSorted(arr));
    return 0;
}

// display array
void display(struct Array arr)
{
    int i;

    printf("\nThe elements are :\n");
    for(i=0;i<arr.length;i++)
    {
        printf("%d ",arr.A[i]);
    }
    printf("\n");
}
// Checking if the array is sorted
bool isSorted(struct Array arr)
{
    int i;
    for(i=0;i<arr.length-1;i++)
    {
        if(arr.A[i]>arr.A[i+1])
        {
            return false; // returns 0 for unsorted array
        }
    }
    return true; // returns 1 for sorted array
}
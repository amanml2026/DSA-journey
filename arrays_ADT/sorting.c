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
void sortInsert(struct Array *arr,int x); // inserting element in sorted array

int main()
{
    struct Array arr = {{2,4,5,9,11,12},10,6};
    display(arr);
    printf("%d\n",isSorted(arr));
    sortInsert(&arr,7); // inserting 7 in sorted array
    display(arr);
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
// Insert element in sorted array
void sortInsert(struct Array *arr,int x)
{
    if(arr->length<arr->size)
    {
        if(isSorted(*arr) == 1)
        {
            int i=arr->length-1;
            while(x<arr->A[i])
            {
                arr->A[i+1] = arr->A[i];
                i--;
            }
            arr->A[i+1] = x;
        }
        else{
            printf("Array must be sorted\n ");
        }
    }
    else{
        printf("Array is full\n");
    }
}
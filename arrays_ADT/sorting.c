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
void NegativeShift(struct Array *arr); // shifting negative elements to left

int main()
{
    struct Array arr = {{-2,4,5,-9,-11,12},10,6};
    display(arr);
    NegativeShift(&arr); // negative elements shift to left
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
// shifting negative elements to left side
void NegativeShift(struct Array *arr)
{
    // initialising two indexes
    int i = 0;
    int j = arr->length-1;
    while(i<j) // loop runs till i<j so list all elements are iterated once
    {
        while(i<arr->length && arr->A[i]<0){i++;} // if there is negative element then move left to right else stops when positive element found
        while(j>0 && arr->A[j]>=0 ){j--;} // if there is positive element then move right to left else stops at negative element
        if(i<j)
        {
            // swapping positive element with negative one
            int temp = arr->A[i];
            arr->A[i] = arr->A[j];
            arr->A[j] = temp;
        }
    }
}
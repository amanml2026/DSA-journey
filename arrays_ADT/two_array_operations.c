#include <stdio.h>
#include <stdlib.h>

// array struct
struct Array{
        int A[100];
        int size;
        int length;
};
struct Array *Merge(struct Array *arr1,struct Array *arr2); // Merging two sorted arrays
void display(struct Array arr);

int main()
{
    struct Array arr1 = {{2,4,12,13,18,21},100,6}; // array1 with length 6
    struct Array arr2 = {{3,7,11,13,14,19,30},100,7}; // array2 with length 7

    struct Array *arr3; // pointer for the merged array
    arr3 = Merge(&arr1,&arr2);
    display(*arr3); // displaying merged array
}

// display function
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

struct Array *Merge(struct Array *arr1,struct Array *arr2) //returning pointer to merged array
{
    int i,j,k;
    i=j=k=0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array)); // pointer for third array in heap
    arr3->size = 100; // size of the arr3
    while(i<arr1->length && j<arr2->length) // boundary check
    {
        if(arr1->A[i]<arr2->A[j])
        {
            arr3->A[k] = arr1->A[i];
            i++;
            k++;
        }
        else{
            arr3->A[k] = arr2->A[j];
            j++;
            k++;
        }
    }
    // copying the remaining elemnts from either arr1 or arr2 
    for(;i<arr1->length;i++)
    {
        arr3->A[k] = arr1->A[i];
        k++;
    }
    for(;j<arr2->length;j++)
    {
        arr3->A[k] = arr2->A[j];
        k++;
    }
    arr3->length = arr1->length + arr2->length; // setting the length of arr3 to be equal to sum of lengths of arr1 and arr2.
    return arr3; // returning arr3 which is a pointer to merged array
}
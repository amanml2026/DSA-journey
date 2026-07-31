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

    struct Array *arr3;
    arr3 = Merge(&arr1,&arr2);
    display(*arr3);
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

struct Array *Merge(struct Array *arr1,struct Array *arr2)
{
    int i,j,k;
    i=j=k=0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    arr3->size = 100;
    while(i<arr1->length && j<arr2->length)
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
    arr3->length = arr1->length + arr2->length;
    return arr3;
}
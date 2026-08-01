#include <stdio.h>
#include <stdlib.h>

// array struct
struct Array{
        int A[100];
        int size;
        int length;
};
struct Array *Merge(struct Array *arr1,struct Array *arr2); // Merging two sorted arrays
void display(struct Array arr); // displaying array
struct Array *Union_unsorted(struct Array *arr1,struct Array *arr2); //union of two unsorted arrays.
int Search(struct Array *arr,int key); //search -- gives 0 for successful search and -1 for unsuccessful one.
struct Array *Union_sorted(struct Array *arr1,struct Array *arr2);
struct  Array *Intersection_unsorted(struct Array *arr1,struct Array *arr2);

int main()
{
    struct Array arr1 = {{2,4,12,13,19,21},100,6}; // array1 with length 6
    struct Array arr2 = {{3,7,11,13,14,19,30},100,7}; // array2 with length 7

    struct Array *arr3; // pointer for the merged array
    arr3 = Merge(&arr1,&arr2);
    display(*arr3); // displaying merged array
    struct Array *arr4;
    arr4 = Union_unsorted(&arr1,&arr2);
    display(*arr4);
    struct Array *arr5;
    arr5 = Union_sorted(&arr1,&arr2);
    display(*arr5);
    struct Array *arr6;
    arr6 = Intersection_unsorted(&arr1,&arr2);
    display(*arr6);
    
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

// union of two unsorted sets(arrays) : time complexity ~ O(n^2) for n,n length arrays
struct Array *Union_unsorted(struct Array *arr1,struct Array *arr2)
{
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    int i,j,k;
    arr3->size = 100;
    for(i=0;i<arr1->length;i++)
    {
        arr3->A[i] = arr1->A[i]; // copying elements from array1
    }
    arr3->length = arr1->length;

    k = arr3->length; //initlising a pointer after the last copied element in arr3
    for(j=0;j<arr2->length;j++) // searching
    {
        if(Search(arr1,arr2->A[j])== -1) // search unsuccessful
        {
            arr3->A[k] = arr2->A[j]; // copy the non-duplicate element
            k++;
            arr3->length++; //increasing the length
        }
    }
    return arr3;
}
// union for two sorted arrays: time complexity ~ O(n) for n,n length array
struct Array *Union_sorted(struct Array *arr1,struct Array *arr2)
{
    int i,j,k;
    i=j=k=0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array)); // pointer for third array in heap
    arr3->size = 100; // size of the arr3
    arr3->length = 0;
    while(i<arr1->length && j<arr2->length) // boundary check
    {
        if(arr1->A[i]<arr2->A[j])
        {
            arr3->A[k] = arr1->A[i];
            i++;
            k++;
        }
        else if(arr1->A[i]>arr2->A[j])
        {
            arr3->A[k] = arr2->A[j];
            j++;
            k++;
        }
        else
        {
            arr3->A[k] = arr1->A[i];
            i++;
            j++;
            k++;
        }
        arr3->length++;
    }
    // copying the remaining elemnts from either arr1 or arr2 
    for(;i<arr1->length;i++)
    {
        arr3->A[k] = arr1->A[i];
        k++;
        arr3->length++;
    }
    for(;j<arr2->length;j++)
    {
        arr3->A[k] = arr2->A[j];
        k++;
        arr3->length++;
    }
    
    return arr3; // returning arr3 which is a pointer to merged array
}
// unsorted arrays intersection : O(n^2)
struct  Array *Intersection_unsorted(struct Array *arr1,struct Array *arr2)
{
    struct Array *arr3;
    arr3 = (struct Array *)malloc(sizeof(struct Array));
    arr3->size = 100;
    int i,j,k;
    k = 0;
    for(i=0;i<arr1->length;i++)
    {
        if(Search(arr2,arr1->A[i])==0) // successful search
        {
            arr3->A[k] = arr1->A[i];
            k++;
            arr3->length++;
        }
    }
    return arr3;
}


int Search(struct Array *arr,int key) 
{
    int i;
    for (i = 0;i<arr->length;i++)
    {
        if (arr->A[i] == key)
        {
            return 0; // search successful
        }
    }
    return -1; // search unsuccessful
}
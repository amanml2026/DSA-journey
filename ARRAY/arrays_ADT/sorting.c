#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

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
void Merge(struct Array *arr,int p,int q,int r); // merging two sorted arrays
void MergeSort(struct Array *arr,int p,int r); // merge sort using recursion
void BubbleSort(struct Array *arr); // bubble sort using nested loop

int main()
{
    struct Array arr = {{-2,4,5,-9,-11,12},10,6};
    display(arr);
    NegativeShift(&arr); // negative elements shift to left
    display(arr);
    printf("%d\n",isSorted(arr));
    sortInsert(&arr,7); // inserting 7 in sorted array
    display(arr);
    printf("Bubble sorted:");
    BubbleSort(&arr);
    // printf("Merge sorted:");
    // MergeSort(&arr,0,5);
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
            while(i>=0 && x<arr->A[i])
            {
                arr->A[i+1] = arr->A[i];
                i--;
            }
            arr->A[i+1] = x;
            arr->length++;
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

// Merging two sorted arrays:
void Merge(struct Array *arr,int p,int q,int r)
{
    int n1,n2,i,j,k;
    n1 = q-p+1; // length of left array
    n2 = r-q; // length of right array
    float L[n1+1]; // left array
    float R[n2+1]; // right array

    // copying elements into left and right array
    for(i=0;i<n1;i++) 
    {
        L[i] = arr->A[p+i];
    }
    for(j=0;j<n2;j++)
    {
        R[j] = arr->A[q+j+1];
    }
    // sentinels
    L[n1] = INFINITY;
    R[n2] = INFINITY;

    // copying into A in sorted order
    i=j=0;
    for(k=p;k<=r;k++)
    {
        if(L[i]<=R[j])
        {
            arr->A[k] = L[i];
            i++;
        }
        else{
            arr->A[k] = R[j];
            j++;
        }
    }
}
// MERGE SORT: 
void MergeSort(struct Array *arr,int p,int r)
{
    if(p<r) // when p = r i.e one element only -> leaf node recursion tree
    {
        int q;
        q = (p+r)/2;
        MergeSort(arr,p,q); // recursive call
        MergeSort(arr,q+1,r); 
        Merge(arr,p,q,r); // merging two sorted arrays
    }
}
// Bubble sort --> O(n^2)
void BubbleSort(struct Array *arr) 
{
    int i,j;
    int temp;
    for(i=0;i<arr->length-1;i++)
    {
        for(j=arr->length-1;j>=i+1;j--) // pass from right to left
        {
            if(arr->A[j]<arr->A[j-1]) // swapping the elements
            {
                temp = arr->A[j];
                arr->A[j] = arr->A[j-1];
                arr->A[j-1] = temp;
            }
        }
    }
}
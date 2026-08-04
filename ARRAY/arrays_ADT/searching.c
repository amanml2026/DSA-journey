#include <stdio.h>
#include <stdlib.h>

// array struct
struct Array{
        int A[10];
        int size;
        int length;
};

int LinearSearch_tr(struct Array *arr,int key); // linear search with transpose
void swap(int *x,int *y); // swap elements
int LinearSearch_head(struct Array *arr,int key); // linear search with key element moving to head
void display(struct Array arr); // displaying array elements
int iter_BinarySearch(struct Array arr , int key); // iterative binary search
int rec_BinarySearch(struct Array arr,int l,int h,int key); // recursive binary search

int main()
{
    struct Array arr = {{2,4,6,8,10},10,5}; // array

    /* implemented binary search before linear search because in linear search we are 
    changing order of elements and in binary search we want a sorted array*/
    
    printf("%d\n",iter_BinarySearch(arr,10)); // successful iterative binary search
    printf("%d\n",rec_BinarySearch(arr,0,arr.length-1,8));  // successful recursive binary search
    printf("%d\n",LinearSearch_tr(&arr,8)); // successful search 
    display(arr);
    printf("%d\n",LinearSearch_tr(&arr,12)); // unsuccessful search -> returns -1
    printf("%d\n",LinearSearch_head(&arr,10)); // moving key element to head returns 0 if successful else -1.
    display(arr);
    return 0;
}

// function for searching a element using linearsearch with transposing
int LinearSearch_tr(struct Array *arr,int key) 
{
    int i;
    for (i = 0;i<arr->length;i++)
    {
        if (arr->A[i] == key)
        {
            if (i>0)
            {
                swap(&arr->A[i],&arr->A[i-1]);
                return i-1; // search successful
            }
            else{
                return 0; // if key is at index 0 
            }
        }
    }
    return -1; // search unsuccessful
}
// function for searching a element using linearsearch with moving the key element to head
int LinearSearch_head(struct Array *arr,int key) 
{
    int i;
    for (i = 0;i<arr->length;i++)
    {
        if (arr->A[i] == key)
        {
            swap(&arr->A[i],&arr->A[0]);
            return 0; // search successful
        }
    }
    return -1; // search unsuccessful
}

// binary search iterative form:
int iter_BinarySearch(struct Array arr , int key)
{
    int l,h,mid;
    l = 0;
    h = arr.length-1;
    
    while(l<=h)
    {
        mid = (l+h)/2;
        if (key==arr.A[mid])
        {
            return mid; // search successful
        }
        else if(key > arr.A[mid])
        {
            l = mid + 1; // moving to right side
        }
        else{
            h = mid - 1; // moving to left side
        }
    }
    return -1; // unsuccessful search
}

// recursive binary search
int rec_BinarySearch(struct Array arr,int l,int h,int key)
{
    int mid;
    if (l <= h)
    {
        mid = (l+h)/2;
        if (arr.A[mid] == key)
        {
            return mid; // success
        }
        else if(key > arr.A[mid])
        {
            return rec_BinarySearch(arr,mid+1,h,key); // calling function giving the left side
        }
        else{
            return rec_BinarySearch(arr,l,mid-1,key); // calling function giving the right side
        }
    }
    return -1; // unsuccessful search
}
// swapping the elements
void swap(int *x,int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
// function to display the elements of the array:
void display(struct Array arr)
{
    int i;

    printf("The elements are :\n");
    for(i=0;i<arr.length;i++)
    {
        printf("%d ",arr.A[i]);
    }
    printf("\n");
}
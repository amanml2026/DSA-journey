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

int main()
{
    struct Array arr = {{2,4,6,8,10},10,5}; // array
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
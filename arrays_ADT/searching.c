#include <stdio.h>
#include <stdlib.h>

// array struct
struct Array{
        int A[10];
        int size;
        int length;
};

int LinearSearch_tr(struct Array *arr,int key);
void swap(int *x,int *y);

int main()
{
    struct Array arr = {{2,4,6,8,10},10,5}; // array
    printf("%d\n",LinearSearch_tr(&arr,8)); // successful search 
    printf("%d\n",LinearSearch_tr(&arr,12)); // unsuccessful search -> returns -1
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


void swap(int *x,int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
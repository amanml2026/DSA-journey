#include <stdio.h>
#include <stdlib.h>

// array struct
struct Array{
        int A[10];
        int size;
        int length;
};
void display(struct Array arr); // display

int main()
{
    struct Array arr = {{24,42,61,84,100},10,5}; // array
    display(arr);
    return 0;
}
// reversing array using auxillary array
void reverse_aux(struct Array *arr)
{
    int B[arr->length]; // auxillary array
    int i,j;
    for(i=(arr->length)-1,j=0;i>=0;i--,j++)
    {
        B[j] = arr->A[i];
    }
    for(i=0;i<(arr->length)-1;i++)
    {
        arr->A[i] = B[i];
    }
}
// display array
void display(struct Array arr)
{
    int i;

    printf("The elements are :\n");
    for(i=0;i<arr.length;i++)
    {
        printf("%d ",arr.A[i]);
    }
}
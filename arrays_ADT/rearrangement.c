#include <stdio.h>
#include <stdlib.h>

// array struct
struct Array{
        int A[10];
        int size;
        int length;
};
void display(struct Array arr); // display
void reverse_aux(struct Array *arr); // reversing using auxillary array
void reverse_twoP(struct Array *arr); // reversing using two pointers

int main()
{
    struct Array arr = {{24,42,61,84,100},10,5}; // array
    display(arr);
    reverse_aux(&arr); // reversing using auxillary array
    display(arr);
    reverse_twoP(&arr); // again reversing using two pointers -> return original unchanched array
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
        B[j] = arr->A[i]; // copying elements in reverse order
    }
    for(i=0;i<arr->length;i++)
    {
        arr->A[i] = B[i]; // changing the original array
    }
}

// reversing the array using two pointers
void reverse_twoP(struct Array *arr)
{
    int i,j;
    for(i=0,j=(arr->length)-1;i<j;i++,j--)
    {
        // swapping
        int temp = arr->A[i];
        arr->A[i] = arr->A[j];
        arr->A[j] = temp;
    }
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
}
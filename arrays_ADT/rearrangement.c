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
void shift(struct Array *arr,char direction); // shifting the array in given direction and setting the missing space=0

int main()
{
    struct Array arr = {{24,42,61,84,100},10,5}; // array
    display(arr);
    reverse_aux(&arr); // reversing using auxillary array
    display(arr);
    reverse_twoP(&arr); // again reversing using two pointers -> return original unchanched array
    display(arr);
    shift(&arr,'l'); // left shifting
    display(arr);
    shift(&arr,'r'); // right shifting
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
// Shifting
void shift(struct Array *arr,char direction)
{
    int i;
    if(direction == 'r') // right shifitng
    {
        for(i=arr->length-2;i>=0;i--)
        {
            arr->A[i+1] = arr->A[i];
        }
        arr->A[0] = 0; // missing space

    }
    if(direction == 'l') // left shifting
    {
        for(i=1;i<arr->length;i++)
        {
            arr->A[i-1] = arr->A[i];
        }
        arr->A[arr->length-1] = 0; // missing space
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
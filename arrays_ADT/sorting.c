#include <stdio.h>
#include <stdlib.h>

// array struct
struct Array{
        int A[10];
        int size;
        int length;
};

void display(struct Array arr); // displaying the array

int main()
{
    struct Array arr = {{2,4,5,9,11,12},10,6};
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
}
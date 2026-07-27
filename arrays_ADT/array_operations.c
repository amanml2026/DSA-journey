#include <stdio.h>
#include <stdlib.h>

// Array data structure:
struct Array{
    int *A;
    int size;
    int length;
};

int main()
{

    struct Array arr;
    int n,i; // for taking the values fron the user
    printf("Enter the size of the array: "); // asked user for size of the array
    scanf("%d",&arr.size);

    arr.A = (int *)malloc(arr.size * sizeof(int)); // allocated the memory for the array of given size.
    arr.length = 0; // no elements currently

    printf("Enter the number of elements you want to insert :");
    scanf("%d",&n);
    
    // checking that the number of elements user wants to insert doesn't exceed the size of the array.
    if(n > arr.size)
    {
        printf("Size of the array is %i",arr.size);
        return 1;
    }
    printf("Enter the elements :");
    printf("\n");

    for(i=0;i<n;i++)
    {
        scanf("%d",&arr.A[i]);
    }
    arr.length = n; // setting the length = no. of elements in array

    return 0;
}
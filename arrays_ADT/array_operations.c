#include <stdio.h>
#include <stdlib.h>

// Array data structure:
struct Array{
    int *A;
    int size;
    int length;
};
void display(struct Array arr); // display function
void append(struct Array *arr,int x); // append function

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
        printf("Size of the array is %i! You cant exceed sorry.",arr.size);
        return 1;
    }
    printf("Enter the elements :");
    printf("\n");

    for(i=0;i<n;i++)
    {
        scanf("%d",&arr.A[i]);
    }
    arr.length = n; // setting the length = no. of elements in array
    display(arr); // displaying the array

    append(&arr,12); // appending an element

    display(arr); // displaying with the appended element

    return 0;
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
}

// function to append the element in array:
void append(struct Array *arr,int x)
{
    if (((arr->length) + 1) <= (arr->size)) // checking for the space in array 
    {
        arr->A[arr->length] = x;
        arr->length++;
        printf("\nSuccessfully appended %i\n",x);
    }
    else{
        printf("\nArray is full!\n"); // array is full . size = length
    }
}
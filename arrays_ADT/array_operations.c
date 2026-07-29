#include <stdio.h>
#include <stdlib.h>

// Array data structure:
struct Array{
    int *A;
    int size;
    int length;
};
void display(struct Array arr); // display 
void append(struct Array *arr,int x); // append 
void insert(struct Array *arr,int index,int x); // insert at given index
void delete(struct Array *arr,int index); // deleting an element of given index
int Get(struct Array arr,int index); // getting an element of given index

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
    delete(&arr,4); // deleting an element
    insert(&arr,3,22); // inserting 22 at index 3 
    display(arr); // displaying with the appended element
    printf("\n%d",Get(arr,4)); // element at given index

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

// function to insert a element at given index
void insert(struct Array *arr,int index,int x)
{
    if (((arr->length) + 1) <= (arr->size) && (index < arr->size)) // checking the index is valid and there is space in array to shift elements
    {
        int i;
        // shifting elements after the given index to get free space at given index
        for(i=arr->length;i>index;i--)
        {
            arr->A[i] = arr->A[i-1]; 
        }
        arr->A[index] = x; // inserting element in free space
        arr->length++;
    }   
}

// function to delete the element at given index
void delete(struct Array *arr,int index)
{
    if (index <0 || index >= arr->length) // checking for a valid index
    {
        printf("Invalid index.");
    }
    else{
        int i;
        for(i=index;i<(arr->length)-1;i++)
        {
            arr->A[i] = arr->A[i+1];
        }
        arr->length--;
    }
}

// getting an element of given index
int Get(struct Array arr,int index)
{
    if(index>0 && index<arr.length)
    {
        return arr.A[index];
    }
}
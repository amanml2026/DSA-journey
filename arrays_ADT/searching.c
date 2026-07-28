#include <stdio.h>
#include <stdlib.h>

// array struct
struct Array{
        int A[10];
        int size;
        int length;
};

int LinearSearch(struct Array arr,int key);

int main()
{
    struct Array arr = {{2,4,6,8,10},10,5}; // array
    printf("%d\n",LinearSearch(arr,2)); // successful search -> gives index 0
    printf("%d\n",LinearSearch(arr,12)); // unsuccessful search -> returns -1
    return 0;
}

// function for searching a element using linearsearch
int LinearSearch(struct Array arr,int key)
{
    int i;
    for (i = 0;i<arr.length;i++)
    {
        if (arr.A[i] == key)
        {
            return i; // search successful
        }
    }
    return -1; // search unsuccessful
}
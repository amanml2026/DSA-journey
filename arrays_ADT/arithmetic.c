#include <stdio.h>
#include <stdlib.h>

// array struct
struct Array{
        int A[10];
        int size;
        int length;
};

int max(struct Array arr); // maximum of given array

int main()
{
    struct Array arr = {{24,42,61,84,10},10,5}; // array
    // maximum
    printf("The maximum of this array is %d",max(arr));
    
    return 0;
}

// maximum of an array
int max(struct Array arr)
{
    int max,i;
    max = arr.A[0];
    for(i=1;i<arr.length;i++) // iterated from second element because first is already set as max
    {
        if(arr.A[i]>max)
        {
            max = arr.A[i];
        }
    }
    return max;
}
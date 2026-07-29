#include <stdio.h>
#include <stdlib.h>

// array struct
struct Array{
        int A[10];
        int size;
        int length;
};

int max(struct Array arr); // maximum of given array
int min(struct Array arr); // minimum of an array
int sum(struct Array arr); // sum of all the elements of an array

int main()
{
    struct Array arr = {{24,42,61,84,100},10,5}; // array
    // maximum
    printf("The maximum of this array is %d\n",max(arr));
    //minimum
    printf("The minimum of this array is %d\n",min(arr));
    //sum
    printf("The sum of the elements is %d\n",sum(arr));

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

// minimum of an array
int min(struct Array arr)
{
    int min,i;
    min = arr.A[0];
    for(i=1;i<arr.length;i++) // iterated from second element because first is already set as min
    {
        if(arr.A[i]<min)
        {
            min = arr.A[i];
        }
    }
    return min;
}
// finding sum of elements of the array
int sum(struct Array arr)
{
    int sum = 0;
    int i;
    for(i=0;i<arr.length;i++)
    {
        sum = sum + arr.A[i];
    }
    return sum;
}

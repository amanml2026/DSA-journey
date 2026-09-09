#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    int left;
    int right;
    int sum;
}info;

int main()
{

    return 0;

}

// Brute force approach
info MaxSubarray(int A[])
{
    int len,l,r,low,high,sum,MaxSum;
    len = sizeof(A);
    MaxSum = -INFINITY;

    for(l=0;l<len;l++)
    {
        sum = 0;
        for(r=l;r<len;r++)
        {
            sum += A[r];
            if(sum > MaxSum)
            {
                MaxSum = sum;
                low = l;
                high = r;
            }
        }
    }
    info output = {low,high,MaxSum};
    return output;

}

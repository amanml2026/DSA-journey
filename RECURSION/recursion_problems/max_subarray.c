#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    int left;
    int right;
    int sum;
}info;

info MaxSubarray(int A[]);

int main()
{
    int Test[] = {-2, 3, -1, 5, -6, 4, 2, -1, 3, -8, 7, -2, 4, -1, 2, -5, 4};
    printf("%d,%d,%d",MaxSubarray(Test).left,MaxSubarray(Test).right,MaxSubarray(Test).sum);
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

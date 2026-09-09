#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    int left;
    int right;
    int sum;
}info;

info MaxSubarray(int A[],int len); // brute force approach - O(n^2)

int main()
{
    int Test[] = {-2, 3, -1, 5, -6, 4, 2, -1, 3, -8, 7, -2, 4, -1, 2, -5, 4}; // test1
    printf("%d,%d,%d\n",MaxSubarray(Test,17).left,MaxSubarray(Test,17).right,MaxSubarray(Test,17).sum);
    int Test2[] = {-4, 2, -3, 6, -1, 4, -7, 3, 5, -2, 4, -6, 2, 8, -3, 1, -5}; // test2
    printf("%d,%d,%d\n",MaxSubarray(Test2,17).left,MaxSubarray(Test2,17).right,MaxSubarray(Test2,17).sum);
    return 0;

}

// Brute force approach
info MaxSubarray(int A[],int len)
{
    int l,r,low,high,sum;
    float MaxSum;
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

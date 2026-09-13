#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    int left;
    int right;
    int sum;
}info;

info MaxSubarray(int A[],int len); // brute force approach - O(n^2)
info MidCrossMaxSubarray(int A[],int low,int mid,int high);
info MaxSubarrayRecursion(int A[],int low,int high);

int main()
{
    int Test[] = {-2, 3, -1, 5, -6, 4, 2, -1, 3, -8, 7, -2, 4, -1, 2, -5, 4}; // test1
    printf("%d,%d,%d\n",MaxSubarray(Test,17).left,MaxSubarray(Test,17).right,MaxSubarray(Test,17).sum);
    int Test2[] = {-4, 2, -3, 6, -1, 4, -7, 3, 5, -2, 4, -6, 2, 8, -3, 1, -5}; // test2
    printf("%d,%d,%d\n",MaxSubarray(Test2,17).left,MaxSubarray(Test2,17).right,MaxSubarray(Test2,17).sum);
    printf("%d,%d,%d\n",MaxSubarrayRecursion(Test2,0,16).left,MaxSubarrayRecursion(Test2,0,16).right,MaxSubarrayRecursion(Test2,0,16).sum);
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
// Divide and conquer (Recursion)

// Max. subarray crossing the middle element
info MidCrossMaxSubarray(int A[],int low,int mid,int high)
{
    int sum,i,j,max_left,max_right;
    float left_sum = -INFINITY; // max. sum of subarray to left of mid(including mid)
    sum = 0;
    for(i=mid;i>=low;i--) // iterating through each element for creating a subarray ending at mid
    {
        sum += A[i]; // subarray sum addition
        if (sum > left_sum){
            left_sum = sum; // max left subarray sum
            max_left = i; // max subarray left index
        }
    }
    float right_sum = -INFINITY; // max. sum of subarray to right of the mid
    sum = 0;
    for(j=mid+1;j<=high;j++) // iterating through each element to create subarray starting from mid+1
    {
        sum += A[j];
        if (sum>right_sum)
        {
            right_sum = sum; // max right subarray sum
            max_right = j; // max subarray right index
        }
    }
    info output = {max_left,max_right,left_sum + right_sum}; // output
    return output;
}

info MaxSubarrayRecursion(int A[],int low,int high)
{
    // base case i.e one element => low==high
    if(low==high){
        info output = {low,high,A[low]}; 
        return output;
    }
    else
    {
        int mid = (low + high)/2; // calculating middle element
        info left,right,cross; // for returning the values
        left = MaxSubarrayRecursion(A,low,mid); // left nodes

        right = MaxSubarrayRecursion(A,mid+1,high); // right nodes

        cross = MidCrossMaxSubarray(A,low,mid,high); // merging them using the crossing mid term solution

        if((left.sum >= right.sum) && (left.sum >= cross.sum)) // left subarray (only) max subarray
        {
            return left;
        }
        if((right.sum >= left.sum) && (right.sum >= cross.sum)) // right subarray (only) max subarray
        {
            return right;
        }
        else{ // max subarray created by crossing through the middle of the array
            return cross;
        }
    }
}
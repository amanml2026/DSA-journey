#include <stdio.h>
#include <stdlib.h>

int Search(int A[],int len,int target); // binary search (while loop)

int main()
{
    int Arr1[] = {-3,-1,0,4,6,7,11,13}; // test
    printf("%d\n",Search(Arr1,8,11));
    printf("%d\n",Search(Arr1,8,-3));
    printf("%d\n",Search(Arr1,8,5));
    return 0;

}

int Search(int A[],int len,int target)
{
    int l,h,mid; // pointers
    l = 0;
    h = len - 1;

    while (l <= h)
    {
        mid = (l+h)/2; // mid
        if (target == A[mid])
        {
            return mid; // target found
        }
        else if(target > A[mid]) // moving l to mid+1 for working with the larger subarray
        {
            l = mid + 1;
        }
        else{             // moving h to mid-1 for working with the smaller subarray
            h = mid - 1;
        }
    }
    return -1; // Target not in the array
}
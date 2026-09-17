#include <stdio.h>
#include <stdlib.h>

int Search(int A[],int len,int target);

int main()
{
    int Arr1[] = {-3,-1,0,4,6,7,11,13};
    printf("%d",Search(Arr1,8,11));
    return 0;

}

int Search(int A[],int len,int target)
{
    int l,h,mid;
    l = 0;
    h = len - 1;

    while (l <= h)
    {
        mid = (l+h)/2;
        if (target == A[mid])
        {
            return mid;
        }
        else if(target > A[mid])
        {
            l = mid + 1;
        }
        else{
            h = mid - 1;
        }
    }
    return -1;
}
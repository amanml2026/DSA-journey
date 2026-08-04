#include <stdio.h>
#include <stdlib.h>

struct Array{
    int A[20];
    int size;
    int length;
};

/*Finding the pair (a,b) such that a+b = k where output should be only (a,b) pair not (b,a) and b!=a*/
int main()
{
    struct Array arr = {{2,1,4,5,3,7,10},20,7};

    return 0;
}

void Approach1(struct Array arr,int key) // O(n^2)
{
    int i,j;
    for(i=0;i<arr.length-1;i++)
    {
        for(j=i+1;j<arr.length;j++)
        {
            if(arr.A[i]+arr.A[j] == key)
            {
                printf("(%d,%d\n)",arr.A[i],arr.A[j]);
            }
        }
    }
}
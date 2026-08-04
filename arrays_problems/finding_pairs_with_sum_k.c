#include <stdio.h>
#include <stdlib.h>

struct Array{
    int A[20];
    int size;
    int length;
};

/*Finding the pair (a,b) such that a+b = k where output should be only (a,b) pair not (b,a) and b!=a*/
void Approach1(struct Array arr,int key); // O(n^2) [using nested loop]
void Approach2(struct Array arr,int key); // O(n) using hash table
// sorted array
void Approach3(struct Array arr); // O(n) [sorted array]

int main()
{
    struct Array arr = {{2,1,4,5,3,7,10},20,7};
    Approach1(arr,9);
    printf("\n");
    Approach2(arr,9);
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
                printf("(%d,%d)\n",arr.A[i],arr.A[j]);
            }
        }
    }
}
void Approach2(struct Array arr,int key) // O(n) using hash table
{
    int min,max,i,len;
    int *H;
    // finding max and min
    min = max = arr.A[0];
    for(i=0;i<arr.length;i++)
    {
        if(arr.A[i]>max){max = arr.A[i];}
        else if(arr.A[i]<min){min = arr.A[i];}
    }
    // making a hashtable/frequency array
    len = max-min+1;
    H = (int *)malloc(len*sizeof(int));
    for(i=0;i<len;i++)
    {
        H[i] = 0;
    }
    
    for(i=0;i<arr.length;i++)
    {
        int complement = key - arr.A[i];
        if (complement >= min && complement <= max)
        {
            if(H[(key-arr.A[i])-min]>0)
            {
                printf("(%d,%d)\n",arr.A[i],key-arr.A[i]);
            }
        }
        H[arr.A[i]-min] ++;
    }
    free(H);
}
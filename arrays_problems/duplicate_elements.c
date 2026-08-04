#include <stdio.h>
#include <stdlib.h>

struct Array{
    int A[20];
    int size;
    int length;
};
/*1. find the duplicate elements in a sorted array and print only one time.*/
void Solution1(struct Array arr);
/*find the duplicates along with their count*/
void Solution2(struct Array arr);
/*find the duplicates in unsorted array along with their count*/
void Solution3(struct Array arr);

int main()
{
    struct Array arr1 = {{2,3,4,4,5,6,7,7,7,8,9,9,9,9},20,14};
    Solution1(arr1);
    printf("\n");
    Solution2(arr1);
    struct Array arr2 = {{3,4,1,1,2,7,7,3,5,1},20,10};
    printf("\n");
    Solution3(arr2);
}

void Solution1(struct Array arr)
{
    int last_duplicate,i;
    last_duplicate = -1; // array has positive numbers
    printf("The missing elements are :\n");
    for(i=0;i<arr.length-1;i++)
    {
        if(arr.A[i] == arr.A[i+1] && arr.A[i] != last_duplicate)
        {
            printf("%d ",arr.A[i]);
            last_duplicate = arr.A[i];
        }
    }
}
void Solution2(struct Array arr)
{
    int i,j;
    for(i=0;i<arr.length-1;i++)
    {
        if(arr.A[i] == arr.A[i+1])
        {
            j = i+1;
            while(arr.A[i] == arr.A[j]){j++;}
            printf("%d appears %d times.\n",arr.A[i],j-i);
            i = j-1;
        }
    }
}
void Solution3(struct Array arr)
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
    // fill the hashtable
    for(i=0;i<arr.length;i++)
    {
        H[(arr.A[i])-min] ++;
    }
    // printing the duplicates i.e H[i](count) >1
    for(i=0;i<len;i++)
    {
        if(H[i]>1){
            printf("%d appears %d times.\n",i+min,H[i]);
        }
    }
    // freeing the hashtable memory
    free(H);
}
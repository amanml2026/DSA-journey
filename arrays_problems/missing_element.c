/* 1.Given a natural number array : [1,2,3,4,5,6,8,9]
Find the missing number in the sequence

2.Given an array which is not starting from 1 i.e [6,7,8,9,10,12,13,14,15]
find missing element

3.Given an array not starting from 1 i.e [6,7,8,9,11,12,15,16]
find multiple(all) missing elements

4. Finding missing elements in an unsorted array of given range i.e [3,6,2,4,1,8,9]*/

#include <stdio.h>
#include <stdlib.h>

struct Array{
    int A[10];
    int size;
    int length;
};
int solution1(struct Array arr); // missing element in a sequence of numbers starting from 1
int solution2(struct Array arr); // missing element in a sequence of numbers starting from any number
void Solution3(struct Array arr); // multiple missing elements
void Solution4(struct Array arr);

int main()
{
    struct Array arr1 = {{1,2,3,4,5,6,8,9},10,8};
    struct Array arr2 = {{6,7,8,9,10,12,13,14,15},10,9};
    struct Array arr3 = {{6,7,8,9,11,12,15,16},10,8};
    struct Array arr4 = {{3,6,2,4,1,8,9},10,7};
    printf("%i\n",solution1(arr1));
    printf("%i\n",solution2(arr2));
    Solution3(arr3);
    Solution4(arr4);
    return 0;
}

int solution1(struct Array arr)
{
    int i,n,sum,sum_actual;
    n = arr.A[arr.length-1];

    sum = (n*(n+1))/2;
    sum_actual = 0;
    for(i=0;i<arr.length;i++)
    {
        sum_actual += arr.A[i];
    }
    return sum - sum_actual;

}

int solution2(struct Array arr)
{
    int i,diff;
    diff = arr.A[0]-0;
    for(i=0;i<arr.length;i++)
    {
        if(arr.A[i] - i != diff)
        {
            return diff+i;
            break;
        }
    }
}
void Solution3(struct Array arr)
{
    int diff,i;
    diff = arr.A[0]-0;
    printf("\nMissing elements are :\n");
    for(i=0;i<arr.length;i++)
    {
        if(arr.A[i]-i != diff)
        {
            
            while(diff<arr.A[i]-i)
            {
                printf("%d\n",i+diff);
                diff++;
            }
        }
    }
}

void Solution4(struct Array arr)
{
    int i,min,max;
    // finding max and min
    min = max = arr.A[0];
    for(i=0;i<arr.length;i++)
    {
        if(arr.A[i]>max){max = arr.A[i];}
        if(arr.A[i]<min){min = arr.A[i];}
    }
    // dynamic array / bitset /Hashmap
    int *H = (int *)malloc((max+1)*sizeof(int));
    // all the indexes become zero
    for(i=0;i<max+1;i++)
    {
        H[i] = 0;
    }
    // Increasing the value of index(element in arr is present) in H 
    for(i=0;i<arr.length;i++)
    {
        H[arr.A[i]] ++;
    }
    // printing the missing elements
    printf("Missing elements : ");
    for(i=min;i<=max;i++)
    {
        if(H[i] == 0){printf("%d ",i);}
    }
}
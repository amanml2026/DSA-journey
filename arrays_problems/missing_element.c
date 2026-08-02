/* 1.Given a natural number array : [1,2,3,4,5,6,8,9]
Find the missing number in the sequence

2.Given an array which is not starting from 1 i.e [6,7,8,9,10,12,13,14,15]
find missing element

3.*/

#include <stdio.h>
#include <stdlib.h>

struct Array{
    int A[10];
    int size;
    int length;
};
int solution1(struct Array arr); // missing element in a sequence of numbers starting from 1
int solution2(struct Array arr); // missing element in a sequence of numbers starting from any number

int main()
{
    struct Array arr1 = {{1,2,3,4,5,6,8,9},10,8};
    struct Array arr2 = {{6,7,8,9,10,12,13,14,15},10,9};
    printf("%i\n",solution1(arr1));
    printf("%i\n",solution2(arr2));
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
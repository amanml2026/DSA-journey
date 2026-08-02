/* Given a natural number array : 1,2,3,4,5,6,8,9
Find the missing number in the sequence*/

/*Approach: finding the last element and finding sum using formula n(n+1)/2 and then finding sum of the
array and finding difference , difference = missing element*/

#include <stdio.h>
#include <stdlib.h>

struct Array{
    int A[10];
    int size;
    int length;
};
int solution(struct Array arr);

int main()
{
    struct Array arr = {{1,2,3,4,5,6,8,9},10,8};
    printf("%i",solution(arr));
    return 0;
}

int solution(struct Array arr)
{
    int i,n,sum,sum_actual;
    n = arr.A[arr.length-1];

    sum = (n*(n+1))/2;
    sum_actual = 0;
    for(i=0;i<arr.length;i++)
    {
        sum_actual += arr.A[i];
    }
    int element = sum - sum_actual;
    return element;

}


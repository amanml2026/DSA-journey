#include <stdio.h>

int main()
{
    int n;
    printf("Enter a number :\n");
    scanf(&n);
    
}

// summation
int Summation(int n)
{
    if (n==0) 
    {
        return 0;
    }
    return n + Summation(n-1); 
}
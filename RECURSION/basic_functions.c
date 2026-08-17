#include <stdio.h>

int Summation(int n);
int Factorial(int n);

int main()
{
    int n;
    printf("Enter a number : ");
    scanf("%d",&n);

    printf("The summation is %d.\n",Summation(n));
    printf("The factorial of  given number is %d.\n",Factorial(n));
    return 0;
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
// factorial
int Factorial(int n)
{
    if (n==0)
    {
        return 1;
    }
    return n*Factorial(n-1);
}
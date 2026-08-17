#include <stdio.h>

int Summation(int n); // summation of number n from 1 to n
int Factorial(int n); // factorial of number n

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
    if (n==0) // base case
    {
        return 0;
    }
    return n + Summation(n-1); // recursive call
}
// factorial
int Factorial(int n)
{
    if (n==0) // base case
    {
        return 1;
    }
    return n*Factorial(n-1); // recursive call
}
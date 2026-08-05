#include <stdio.h>

int length(char *s); // length of the string
char *Lower(char *s); // Make the string to lower case
int main()
{
    char s[] = "CALIFORNIA";
    printf("Length of the string is %d\n",length(s));
    
    printf("%s",Lower(s));
    return 0;
}

// find length of the string
int length(char *s)       
{
    int i;
    i=0;
    while(s[i] != '\0') // iterate till the end of string character
    {
        i++; // incrementing i
    }
    // i will stop at the index where the string delimiter is there
    return i; // i = length
}

// change the upper case to lower case given a string of upper chars only
char *Lower(char *s)
{
    char *lower = s;
    int i = 0;
    while(s[i] != '\0')
    {
        s[i] += 32;
        i++;
    }
    return lower;
}
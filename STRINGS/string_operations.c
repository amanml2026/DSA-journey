#include <stdio.h>

int main()
{
    char *s = "California";

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
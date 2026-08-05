#include <stdio.h>

int length(char *s); // length of the string
char *Lower(char *s); // Make the string to lower case
char *Toggle(char *s); // toggles the cases.
int main()
{
    char s[] = "California";
    printf("Length of the string is %d\n",length(s));
    // printf("%s",Lower(s));
    printf("%s",Toggle(s));
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
    while(lower[i] != '\0')
    {
        lower[i] += 32;
        i++;
    }
    return lower;
}

// toggle the case of the string i.e lower--> upper and upper--> lower
char *Toggle(char *s)
{   
    char *toggle = s;
    int i = 0;
    while (toggle[i] != '\0')
    {
        if(toggle[i] >= 65 && toggle[i] <=90)
        {
            toggle[i] += 32;
        }
        else if (toggle[i] >= 97 && toggle[i]<=122)
        {
            toggle[i] -= 32;
        }
        i++;
    }
    return toggle;
}
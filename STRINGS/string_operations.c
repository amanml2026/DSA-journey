#include <stdio.h>

int length(char *s); // length of the string
char *Lower(char *s); // Make the string to lower case
char *Toggle(char *s); // toggles the cases.
void Count_vowels_cons(char *s); // counting vowels and consonants
int main()
{
    char s[] = "California";
    printf("Length of the string is %d\n",length(s));
    // printf("%s",Lower(s));
    printf("%s",Toggle(s));
    Count_vowels_cons(s);
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
// to count vowels and consonants
void Count_vowels_cons(char s[])
{
    int i,vowels,consonants;
    vowels=consonants=0;
    for(i=0; s[i] != '\0';i++)
    {
        // vowels
        if(s[i] == 'a' || s[i] == 'A' ||s[i] == 'e' || s[i] == 'E' ||s[i] == 'i' || s[i] == 'I' ||
        s[i] == 'o' || s[i] == 'O' ||s[i] == 'u' || s[i] == 'U')
        {
            vowels++;
        }
        // consonants
        else if((s[i] >= 'a' && s[i] <= 'z')||(s[i] >= 'A' && s[i] <= 'Z'))
        {
            consonants++;
        }
    }
    printf("The no of vowels : %d and consonants is %d.",vowels,consonants);
}
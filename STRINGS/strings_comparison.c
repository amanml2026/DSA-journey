#include <stdio.h>
#include <stdlib.h>

void Compare(char *s,char *t); // comapring string s with string t

int main()
{
    char s[] = "madam";
    char t[] = "madame";
    char p[] = "madam";
    Compare(s,t); // comparing strings
    Compare(s,p);
}

void Compare(char *s,char *t)
{
    int i,j;
    for(i=0,j=0;s[i]!='\0' && t[j]!='\0';i++,j++) // runs until both reaches end of the string
    {
        if(s[i]!=t[j]){break;} // if unequal -> loop ends 
    }
    if(s[i]==t[j]){printf("Equal\n");} // loop ran till the end of string character
    else if(s[i]<t[j]){printf("Smaller\n");}
    else{printf("Greater\n");}
}
#include <stdio.h>
#include <stdlib.h>

void Compare(char *s,char *t); // comapring string s with string t
int IsPalindrome(char *s); // Checking if given string is palindrome or not 

int main()
{
    char s[] = "madam";
    char t[] = "madame";
    char p[] = "madam";
    Compare(s,t); // comparing strings
    Compare(s,p);
    printf("%d\n",IsPalindrome(p));
}
// comparing two strings
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
// Checking if the given string is palindrome or not 
int IsPalindrome(char *s) // two pointers approach
{
    int i,j;
    for(j=0;s[j]!='\0';j++){} // j comes to the end of the string
    j = j-1; // Decreasing j so that it doesn't refer to the end of string character

    for(i=0;i<j;i++,j--) // comparing
    {
        if(s[i]!=s[j]){return 0;}
    }
    return 1;
}
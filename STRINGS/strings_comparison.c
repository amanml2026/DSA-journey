#include <stdio.h>
#include <stdlib.h>

void Compare(char *s,char *t); // comapring string s with string t
int IsPalindrome(char *s); // Checking if given string is palindrome or not
void Duplicate_NL(char *s); // Finding duplicates using nested loop in a string
void Duplicate_HT(char *s); // finding duplicates using hash table

int main()
{
    char s[] = "abstractions";
    char t[] = "madame";
    char p[] = "madam";
    Compare(s,t); // comparing strings
    Compare(s,p);
    printf("%d\n",IsPalindrome(p));
    Duplicate_NL(s); // duplicates
    Duplicate_HT(s);
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

// finding duplicates using nested loop -> O(n^2)
void Duplicate_NL(char *s) // NL = Nested Loop
{
    int i,j;
    printf("Duplicate elements are: \n");
    for(i=0;s[i]!='\0';i++)
    {
        for(j=i+1;s[j]!='\0';j++)
        {
            if(s[i]==s[j])
            {
                printf("%c\n",s[i]);
            }
        }
    }
}

// finding duplicates using hash table -> O(n)
void Duplicate_HT(char *s) // HT-> hash table
{
    int i;
    int *H; // hash table
    H = (int *)malloc(26*sizeof(int)); // memory allocation for 26 alphabets(lower case)
    for(i=0;i<26;i++)
    {
        H[i] = 0; // frequencies of every alphabet is zero initially
    }
    for(i=0;s[i]!='\0';i++)
    {
        H[(s[i])-'a'] ++; // frequency increased
    }
    // printing duplicates and their frequency
    for(i=0;i<26;i++)
    {
        if(H[i]>1)
        {
            printf("%c appears %d times.\n",i+'a',H[i]);
        }
    }
    free(H); // freeing the allocated memory
}
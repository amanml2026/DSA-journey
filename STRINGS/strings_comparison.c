#include <stdio.h>
#include <stdlib.h>

void Compare(char *s,char *t); // comapring string s with string t
int IsPalindrome(char *s); // Checking if given string is palindrome or not
void Duplicate_NL(char *s); // Finding duplicates using nested loop in a string
void Duplicate_HT(char *s); // finding duplicates using hash table
void Duplicate_bits(char *s);
int IsAnagram(char *s,char *t);

int main()
{
    char s[] = "abstractions";
    char t[] = "madame";
    char p[] = "madam";
    char q[] = "seats";
    char r[] = "asset";
    Compare(s,t); // comparing strings
    Compare(s,p);
    printf("%d\n",IsPalindrome(p));
    Duplicate_NL(s); // duplicates
    Duplicate_HT(s);
    Duplicate_bits(s);
    printf("%d\n",IsAnagram(q,r));
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

// finding duplicates using bits -> O(n)
void Duplicate_bits(char *s)
{
    int H,X,i;
    H = 0; // 32 bits where the bit becomes on which coressponds to the character in the string
    for(i=0;s[i]!='\0';i++)
    {
        X = 1; // 32 bits for doing merging and masking
        X = X << s[i]-'a'; // left shift
        if ((H & X) == 0) // if the bit is off i.e masking output = 0
        {
            H = X|H; // merging-> turning the bit on
        }
        else{
            printf("%c is duplicate.\n",s[i]); // duplicate i.e bit is already on
        }
    }
}
// to find if the given two strings are anagram or not
int IsAnagram(char *s,char *t)
{
    int i;
    int *H;
    H = (int *)malloc(26*sizeof(int));
    for(i=0;i<26;i++)
    {
        H[i] = 0;
    }
    for(i=0;s[i]!='\0';i++)
    {
        H[(s[i])-'a'] ++;
    }
    for(i=0;t[i]!='\0';i++)
    {
        H[(t[i])-'a'] --;
    }
    for(i=0;i<26;i++)
    {
        if(H[i]!=0)
        {
            return 0;
        }
    }
    return 1;
}
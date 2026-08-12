#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[] = "madam";
    char t[] = "madam";
}

void Compare(char *s,char *t)
{
    int i,j;
    for(i=0,j=0;s[i]!='\0' && t[j]!='\0';i++,j++)
    {
        if(s[i]!=t[j]){break;}
    }
    if(s[i]==t[j]){printf("Equal\n");}
    else if(s[i]<t[j]){printf("Smaller\n");}
    else{printf("Greater\n");}
}
#include <stdio.h>

int main()
{
    char name[5] = {'J','o','h','n','\0'}; // method1
    char city[] = {'D','u','b','a','i','\0'}; // method2
    char country[] = "India"; // method3
    char *job = "SDE"; // method4

    printf("%s,%s,%s,%s",name,city,country,job);
    return 0;
}
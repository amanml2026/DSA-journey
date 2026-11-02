#include <stdio.h>
#include <stdlib.h>

typedef struct List{
    int key;
    struct List *next;
}List;

typedef struct DoubleList{
    int key;
    struct DoubleList *prev;
    struct DoubleList *next;
}DoubleList;

int main()
{
    return 0;
}
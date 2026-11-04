#include <stdio.h>
#include <stdlib.h>

// single linked list
typedef struct List{
    int key;
    struct List *next;
}List;

// double linked list
typedef struct DoubleList{
    int key;
    struct DoubleList *prev;
    struct DoubleList *next;
}DoubleList;

int main()
{
    return 0;
}
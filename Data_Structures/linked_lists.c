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

// singly linked list functions:
void Insert(List *head,List *x)
{
    if (head == NULL)
    {
        List *head = malloc(sizeof(List));
        if(head == NULL)
        {
            return 1;
        }
        head = x;
        x->next = NULL;

    }
    else{
        x->next = head;
        head = x;
    }
}

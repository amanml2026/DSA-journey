#include <stdio.h>
#include <stdlib.h>

typedef struct Stack{
    int S[10];
    int top;
}Stack;

typedef struct Queue{
    int Q[10];
    int head;
    int tail;
}Queue;

int main()
{
    return 0;
}

// STACK FUNCTIONS:

// Inserting elements -> O(1)
void push(Stack *S,int x)
{
    S->top ++;
    S->S[S->top] = x;
}

// deleting and popping out elements -> O(1)
int pop(Stack *S)
{
    S->top --;
    return S->S[S->top + 1];
}
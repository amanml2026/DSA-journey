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

int isEmptyStack(Stack S);
void push(Stack *S,int x);
int pop(Stack *S);
void DisplayStack(Stack S);

int main()
{
    Stack S = {{},-1};
    push(&S,4);
    push(&S,7);
    push(&S,10);
    printf("Element popped : %i\n",pop(&S));
    DisplayStack(S);

    return 0;
}

// STACK FUNCTIONS:

// empty check:
int isEmptyStack(Stack S)
{
    if(S.top == -1){
        return 1;
    }
    return 0;
}

// Inserting elements -> O(1)
void push(Stack *S,int x)
{
    S->top ++;
    S->S[S->top] = x;
}

// deleting and popping out elements -> O(1)
int pop(Stack *S)
{
    if (isEmptyStack(*S))
    {
        printf("Stack is empty!");
    }
    else{
        S->top --;
        return S->S[S->top + 1];
    }
}

// stack display
void DisplayStack(Stack S)
{
    int i;
    for(i=0;i<=S.top;i++)
    {
        printf("%i",S.S[i]);
        printf("\t");
    }
}
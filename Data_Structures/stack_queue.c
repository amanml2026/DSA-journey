#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 10
typedef struct Stack{
    int S[CAPACITY];
    int top;
}Stack;

typedef struct Queue{
    int Q[CAPACITY];
    int head;
    int tail;
    int len;
}Queue;

int isEmptyStack(Stack S);
void push(Stack *S,int x);
void pop(Stack *S);
void DisplayStack(Stack S);
void Enqueue(Queue *Q,int x);
void DisplayQueue(Queue Q);
void Deque(Queue *Q);

int main()
{
    Stack S = {{},-1};
    push(&S,4);
    push(&S,7);
    push(&S,10);
    pop(&S);
    DisplayStack(S);
    push(&S,8);
    push(&S,5);
    pop(&S);
    DisplayStack(S);

    printf("\n");
    Queue Q = {{},0,0,0};
    Enqueue(&Q,2);
    Enqueue(&Q,6);
    DisplayQueue(Q);
    Deque(&Q);
    Enqueue(&Q,7);
    Deque(&Q);
    DisplayQueue(Q);

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
void pop(Stack *S)
{
    if (isEmptyStack(*S))
    {
        printf("\nStack is empty!\n");
    }
    else{
        S->top --;
        printf("\nElement popped : %i\n",S->S[S->top + 1]);
    }
}

// stack display
void DisplayStack(Stack S)
{
    int i;
    for(i=0;i<=S.top;i++)
    {
        printf("%i",S.S[i]);
        printf(" ");
    }
}
// QUEUE FUNCTIONS:

// queue display
void DisplayQueue(Queue Q)
{
    int i;
    for(i=0;i<Q.len;i++)
    {
        int idx;
        idx = (Q.head + i)%CAPACITY;
        printf("%i",Q.Q[idx]);
        printf(" ");
    }   
}
// Insertion (enqueue) -> O(1)
void Enqueue(Queue *Q,int x)

{
    if (Q->len == CAPACITY) {
        printf("\nQueue is full!\n");
        return;
    }

    Q->Q[Q->tail] = x;
    Q->tail = (Q->tail + 1) % CAPACITY;
    Q->len++;
}

// deletion(deque) -> O(1)
void Deque(Queue *Q)
{
    if (Q->len == 0) {
        printf("\nQueue is empty!\n");
        return;
    }

    int x = Q->Q[Q->head];

    Q->head = (Q->head + 1) % CAPACITY;
    Q->len--;

    printf("\nElement dequeued: %d\n", x);
}

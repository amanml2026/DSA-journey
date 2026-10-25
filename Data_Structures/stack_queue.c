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
        printf("Stack is empty!\n");
    }
    else{
        S->top --;
        printf("Element popped : %i\n",S->S[S->top + 1]);
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
    for(i=Q.head;i<Q.tail;i++)
    {
        printf("%i",Q.Q[i]);
        printf(" ");
    }   
}
// Insertion (enqueue) -> O(1)
void Enqueue(Queue *Q,int x)
{
    Q->Q[Q->tail] = x;
    Q->len ++;
    if (Q->tail == Q->len-1){
        Q->tail = 0;
    }
    else{
        Q->tail ++;
    }
}
// deletion(deque) -> O(1)
void Deque(Queue *Q)
{
    int x;
    x = Q->Q[Q->head];
    Q->len -- ;
    if (Q->head == Q->len-1){
        Q->head = 0;
    }
    else{
        Q->head ++;
    }
    printf("Element dequed : %i\n",x);
}

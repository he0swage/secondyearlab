#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define QUEUE_EMPTY INT_MIN
#define STACK_LENGTH 5
#define EMPTY -1
#define STACK_EMPTY INT_MIN

typedef struct node
{
    int val;
    struct node *next;
} node;

typedef struct
{
    node *head;
    node *tail;
} queue;

void init_queue(queue *q)
{
    q->head = NULL;
    q->tail = NULL;
}

bool enqueue(queue *q, int val)
{
    node *newnode = malloc(sizeof(node));
    if (newnode == NULL)
        return false;

    newnode->val = val;
    newnode->next = NULL;

    if (q->tail != NULL)
        q->tail->next = newnode;

    q->tail = newnode;

    if (q->head == NULL)
        q->head = newnode;

    return true;
}

int dequeue(queue *q)
{
    if (q->head == NULL)
        return QUEUE_EMPTY;

    node *tmp = q->head;
    int result = tmp->val;

    q->head = q->head->next;

    if (q->head == NULL)
        q->tail = NULL;

    free(tmp);
    return result;
}
int mystack[STACK_LENGTH];
int top = EMPTY;

bool push(int val)
{
    if (top >= STACK_LENGTH - 1)
        return false;

    top++;
    mystack[top] = val;
    return true;
}

int pop()
{
    if (top == EMPTY)
        return STACK_EMPTY;
    int result = mystack[top];
    top--;
    return result;
}

int main()
{
    queue q;
    init_queue(&q);

    int x;

    for (int i = 0; i < 5; i++)
    {
        printf("enter the value %d : ", i + 1);
        scanf("%d", &x);
        enqueue(&q, x);
        push(x);
    }

    int t;
    while ((t = pop()) != STACK_EMPTY)
    {
        printf("t = %d\n", t);
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define QUEUE_EMPTY INT_MIN

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

int main()
{
    queue q;
    init_queue(&q);

    enqueue(&q, 56);
    enqueue(&q, 53);
    enqueue(&q, 554);
    enqueue(&q, 6);
    enqueue(&q, 58);

    int t;
    while ((t = dequeue(&q)) != QUEUE_EMPTY)
    {
        printf("t = %d\n", t);
    }

    return 0;
}

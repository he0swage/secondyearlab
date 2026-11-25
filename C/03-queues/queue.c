#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int typeinfo;

struct node
{
    typeinfo info;
    struct node *next;
};

struct queue
{
    struct node *head;
    struct node *tail;
};

void createqueue(struct queue *q)
{
    q->head = NULL;
    q->tail = NULL;
}

bool isempty(struct queue *q)
{
    return (q->head == NULL);
}

void enqueue(struct queue *q, typeinfo val)
{
    struct node *newnode = malloc(sizeof(struct node));
    newnode->info = val;
    newnode->next = NULL;

    if (q->head == NULL)
    {
        q->head = newnode;
        q->tail = newnode;
    }
    else
    {
        q->tail->next = newnode;
        q->tail = newnode;
    }
}

void dequeue(struct queue *q, typeinfo *val)
{
    if (isempty(q))
    {
        printf("The queue is empty!\n");
        return;
    }

    struct node *temp = q->head;
    *val = temp->info;

    if (q->head == q->tail)
    {
        q->tail = NULL;
    }

    q->head = q->head->next;
    free(temp);
}

int main()
{
    int i;
    typeinfo v;
    struct queue q;

    createqueue(&q);

    for (i = 1; i < 7; i++)
    {
        printf("Enter a value: ");
        scanf("%d", &v);
        enqueue(&q, v);
    }

    while (!isempty(&q))
    {
        dequeue(&q, &v);
        printf("%d\n", v);
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *creation(int item); // we put only the value
void display(struct node *head); // for display
void insertend(struct node **head, struct node **tail, int item);

struct node *creation(int item)
{
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = item;
    newnode->prev = NULL;
    newnode->next = NULL;
    // important
    return newnode;
}

void display(struct node *head)
{

    if (head == NULL)
    {
        printf("list is empty");
    }

    struct node *p = head;
    while (p != NULL)
    {
        printf("%d<=>", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

void insertend(struct node **head, struct node **tail, int item)
{
    // important
    struct node *newnode = creation(item);
    if (*head == NULL)
    {
        *head = newnode;
        *tail = newnode;
    }
    else
    {
        (*tail)->next = newnode;
        newnode->prev = *tail;
        *tail = newnode;
    }
}
int main()
{
    struct node *head = NULL;
    struct node *tail = NULL;
    int i, n, item;

    printf("enter the number of node you want to have:\n");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("enter a value to the new node:\n");
        scanf("%d", &item);
        insertend(&head, &tail, item);
    }
    display(head);
}

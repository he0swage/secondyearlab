#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

int main()
{
    int i, n, item;
    struct node *p, *head = NULL, *newnode;

    printf("enter the number of node you want to have:\n");
    scanf("%d", &n);

    // creation of node 0

    printf("enter the element of the node 0:\n");
    scanf("%d", &item);

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = item;
    newnode->next = NULL;
    newnode->prev = NULL;

    head = newnode;
    p = newnode;

    // cration of the other nodes

    printf("enter the element of the other nodes:\n");
    for (i = 1; i < n; i++)
    {
        printf("enter the node:\n");
        scanf("%d", &item);
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = item;
        newnode->next = NULL;
        newnode->prev = p;
        p->next = newnode;
        p = p->next;
    }

    // display the list

    p = head;
    printf("here is the list :\n");
    while (p != NULL)
    {
        printf("%d<=>", p->data);
        p = p->next;
    }
    printf("NULL\n");
}
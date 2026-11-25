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
    struct node *head = NULL, *p, *newnode;
    printf("enter the number of node you want to have:\n");
    scanf("%d", &n);

    // creation of the node 0

    printf("enter the element of the node 0:\n");
    scanf("%d", &item);

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = item;
    newnode->next = NULL;
    newnode->prev = NULL;

    head = newnode;
    p = newnode;

    // creation of the other node

    for (i = 0; i < n; i++)
    {
        printf("enter the element:\n");
        scanf("%d", &item);
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = item;
        newnode->next = NULL;
        newnode->prev = p;

        p->next = newnode;
        p = p->next;
    }
    p = head;
    while (p != NULL)
    {
        printf("%d<=>", p->data);
        p = p->next;
    }
    printf("NULL\n");
}
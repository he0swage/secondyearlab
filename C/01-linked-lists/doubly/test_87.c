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

    // number of node
    printf("enter the number of node you want to have:\n");
    scanf("%d", &n);

    // creation of the node 0
    printf("enter the element of the node 0:\n");
    scanf("%d", &item);

    // malloc
    newnode = (struct node *)malloc(sizeof(struct node));

    // important
    newnode->data = item;
    newnode->next = NULL;
    newnode->prev = NULL;

    // imporant
    head = newnode;
    p = newnode;

    // creation of the oder node
    for (i = 1; i < n; i++)
    {
        printf("enter the element of the oder node:\n");
        scanf("%d", &item);
        newnode = (struct node *)malloc(sizeof(struct node));

        newnode->data = item;
        newnode->next = NULL;
        newnode->prev = p;

        // important
        p->next = newnode;
        p = p->next;
    }
    // display
    p = head;
    while (p != NULL)
    {
        printf("%d<=>", p->data);

        p = p->next;
    }
    printf("NULL\n");

    // add a node at the head

    printf("enter the element of the node you want to add in the head of the list:\n");
    scanf("%d", &item);
    newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = item;
    newnode->next = head;
    head->prev = newnode;
    newnode->prev = NULL;
    // important
    head = newnode;

    p = head;
    // display
    while (p != NULL)
    {
        printf("%d<=>", p->data);
        p = p->next;
    }
    printf("NULL\n");
}
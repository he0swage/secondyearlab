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

    // size of the ll

    printf("enter the size of the node:\n");
    scanf("%d", &n);

    // creation of the node 0

    printf("enter the element of the node 0:\n");
    scanf("%d", &item);

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = item;
    newnode->next = NULL;
    newnode->prev = NULL;
    // important
    head = newnode;
    p = newnode;
    // enter the element of the list

    printf("enter the element of the new node:\n");
    for (i = 1; i < n; i++)
    {
        scanf("%d", &item);
        newnode = (struct node *)malloc(sizeof(struct node));

        newnode->data = item;
        newnode->next = NULL;
        newnode->prev = p;

        // important
        p->next = newnode;
        p = p->next;
    }
    // list befor adding
    p = head;
    while (p != NULL)
    {
        printf("%d<->", p->data);

        // important
        p = p->next;
    }
    printf("NULL\n");

    // add a node in the beggin

    printf("enter the element of the node you want to add:\n");
    scanf("%d", &item);
    newnode = (struct node *)malloc(sizeof(struct node));

    // important
    newnode->data = item;

    newnode->next = head;
    head->prev = newnode;
    newnode->prev = NULL;
    head = newnode;

    // list after ading
    p = head;
    while (p != NULL)
    {
        printf("%d<->", p->data);

        // important
        p = p->next;
    }
    printf("NULL\n");
}
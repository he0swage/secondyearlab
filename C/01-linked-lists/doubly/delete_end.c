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
    struct node *head = NULL, *p, *newnode, *storeprev;

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
    // list befor deleting
    printf("here is the list before delete the end:\n");

    p = head;
    while (p != NULL)
    {
        printf("%d<->", p->data);

        // important
        p = p->next;
    }
    printf("NULL\n");

    // delete end
    printf("here is the list after deleting the end:\n");

    // deleting
    p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    // imporant
    storeprev = p->prev;
    storeprev->next = NULL;
    free(p);

    // list after deleting
    p = head;
    while (p != NULL)
    {
        printf("%d<->", p->data);

        // important
        p = p->next;
    }
    printf("NULL\n");
}
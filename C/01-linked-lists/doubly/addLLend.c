#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

// main program

int main()
{
    int i, n, item, cpt = 0;
    struct node *head = NULL, *p, *newnode;

    printf("enter the number of node you want to have:\n");
    scanf("%d", &n);

    // creating node 0

    printf("enter the element of the node 0:\n");
    scanf("%d", &item);
    if (item < 5)
    {
        cpt = cpt + 1;
    }

    // malloc
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = item;
    newnode->next = NULL;
    newnode->prev = NULL;

    // imporant
    head = newnode;
    p = newnode;

    // creating the other node

    for (i = 1; i < n; i++)
    {
        printf("enter the element of the node:\n");
        scanf("%d", &item);
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = item;
        newnode->next = NULL;
        newnode->prev = p;

        if (item < 5)
        {
            cpt = cpt + 1;
        }

        // important
        p->next = newnode;
        p = p->next;
    }

    // display the list

    p = head;
    while (p != NULL)
    {
        printf("%d<->", p->data);

        // important
        p = p->next;
    }
    printf("NULL\n");
    printf("the number of element under 10 are:%d\n", cpt);

    printf("enter the number you want to add in the end of the list:\n");
    scanf("%d", &item);

    // addding the node at the end

    p = head;
    // imporant
    while (p->next != NULL)
    {
        p = p->next;
    }
    // mallocc
    newnode = (struct node *)malloc(sizeof(struct node));
    // imporant

    newnode->data = item;
    newnode->next = NULL;
    newnode->prev = p;
    p->next = newnode;

    // display the list
    p = head;
    while (p != NULL)
    {
        printf("%d<->", p->data);

        // important
        p = p->next;
    }
    printf("NULL\n");
}
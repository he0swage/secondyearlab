#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *p, *newnode, *head = NULL;
    int i, n, item;

    printf("enter the number of nodes you want:\n");
    scanf("%d", &n);

    printf("enter the element of the first node:\n");
    scanf("%d", &item);
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = item;
    newnode->next = NULL;
    head = newnode;
    p = newnode;

    printf("enter the element of the other nodes:\n");

    for (i = 1; i < n; i++)
    {
        scanf("%d", &item);
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = item;
        newnode->next = NULL;
        p->next = newnode;
        p = p->next;
    }
    p->next = head;

    struct node *temp = head;
    do
    {
        printf("->%d->", temp->data);
        temp = temp->next;
    } while (temp != head);

    return 0;
}

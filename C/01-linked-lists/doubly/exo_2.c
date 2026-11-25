#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

void deletenega(node **head);
void sortlist(node **head);
void intsorted(node **head, int value);

node *(node *head)

    node *createNode(int value)
{
    node *NewNode = (node *)malloc(sizeof(node));
    NewNode->data = value;
    NewNode->prev = NULL;
    NewNode->next = NULL;
    return NewNode;
}
void insert(node **head, int value)
{
    node *NewNode = createNode(value);
}
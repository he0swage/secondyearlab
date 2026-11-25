#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};
Node *createNode(Node *L; int data);
void deleteNegative(node *head);
void insert();
void reversewithallocation();
void reversewithoutallocation();
void relese();

void deleteNegatives(struct Node **head)
{
    struct Node *current = *head;

    while (current != NULL)
    {
        struct Node *nextNode = current->next;

        if (current->data < 0)
        {
            if (current->prev != NULL)
                current->prev->next = current->next;
            else
                *head = current->next;

            if (current->next != NULL)
                current->next->prev = current->prev;

            free(current);
        }

        current = nextNode;
    }
}

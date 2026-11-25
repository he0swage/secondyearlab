#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>

#define EMPTY -1
#define STACK_EMPTY INT_MIN

typedef struct node
{
    int val;
    struct node *next;
} node;

node *head = NULL;

bool push(int val)
{
    node *newnode = malloc(sizeof(node));
    if (newnode == NULL)
        return false;
    newnode->val = val;
    newnode->next = head;
    head = newnode;
    return true;
}

int pop()
{
    if (head == NULL)
        return STACK_EMPTY;

    int result = head->val;
    node *tmp = head;
    head = head->next;
    free(tmp);
    return result;
}

int main()
{

    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);
    push(7);
    push(8);
    push(9);
    push(10);
    push(11);
    push(12);
    push(13);
    push(14);

    int t;
    while ((t = pop()) != STACK_EMPTY)
    {
        printf("t=%d\n", t);
    }
}
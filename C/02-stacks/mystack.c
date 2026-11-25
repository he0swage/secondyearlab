#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int typeinfo;
typedef struct node *stack;

struct node
{
    typeinfo info;
    stack next;
};

void createstack(stack *s)
{
    *s = NULL;
}

bool isempty(stack s)
{
    return (s == NULL);
}

void push(stack *s, typeinfo val)
{
    stack new;
    new = malloc(sizeof(struct node));
    new->info = val;
    new->next = *s;
    *s = new;
}

void pop(stack *s, typeinfo *val)
{
    stack temp;
    if (isempty((*s)))
    {
        printf("the stack is empty!\n");
    }
    else
    {
        *val = (*s)->info;
        temp = *s;
        *s = (*s)->next;
        free(temp);
    }
}

int main()
{
    int i;
    typeinfo v;
    stack s;
    createstack(&s);
    printf("enter the element of the stack:\n");
    for (i = 1; i < 7; i++)
    {
        scanf("%d", &v);
        push(&s, v);
    }
    printf("here is the stack after the pop:\n");
    while (!isempty(s))
    {
        pop(&s, &v);
        printf("%d\n", v);
    }
    return 0;
}
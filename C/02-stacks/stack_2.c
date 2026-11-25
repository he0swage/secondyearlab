#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define STACK_LENGTH 5
#define EMPTY -1
#define STACK_EMPTY INT_MIN

int mystack[STACK_LENGTH];
int top = EMPTY;

bool push(int val)
{
    if (top >= STACK_LENGTH - 1)
        return false;

    top++;
    mystack[top] = val;
    return true;
}

int pop()
{
    if (top == EMPTY)
        return STACK_EMPTY;
    int result = mystack[top];
    top--;
    return result;
}

int main()
{

    int x, i, t;

    for (i = 0; i < STACK_LENGTH; i++)
    {
        printf("Enter element to push: ");
        scanf("%d", &x);

        if (!push(x))
        {
            printf("Stack is full!\n");
            break;
        }
    }
    while ((t = pop()) != STACK_EMPTY)
    {
        printf("%d\n", t);
    }
}
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define STACK_LENGTH 5
#define EMPTY -1
#define STACK_EMPTY INT_MIN

#define STACK_LENGTH2 5
#define EMPTY -1
#define STACK_EMPTY2 INT_MIN

int mystack[STACK_LENGTH];
int mystack[STACK_LENGTH2];
int top = EMPTY;
int top2 = EMPTY;

bool push(int val, int top, int sl) // push(vqleur,top,STACK_LENGHT);
{
    if (top >= sl - 1)
        return false;

    top++;
    mystack[top] = val;
    return true;
}

int pop(int top)
{
    if (top == EMPTY)
        return STACK_EMPTY;
    int result = mystack[top];
    top--;
    return result;
}

#define STACK_LENGTH2 5
#define EMPTY -1
#define STACK_EMPTY2 INT_MIN

int mystack2[STACK_LENGTH2];
int top2 = EMPTY;

int pop2()
{
    if (top2 == EMPTY)
        return STACK_EMPTY2;
    int result = mystack2[top2];
    top2--;
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
    while ((t = pop()) != STACK_EMPTY2)
    {
        printf("%d\n", t);
    }
}
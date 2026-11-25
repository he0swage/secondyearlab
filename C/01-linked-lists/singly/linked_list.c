#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int Data;
    struct Node *next;
}

Node *
createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

int main()
{
    Node *L = NULL;
    int i;
    int value;
    int sum = 0;
    printf("enter a value:\n");
    scanf("%d", &value);
    for (i = 1; i < value; i++)
    {
        if (value % i == 0)
        {
            sum += i;
        }
    }

    if (sum == value)
    {
        printf("the value :%d is a perfect number!!", value);
    }
    else
    {
        printf("no the value :%d isn't a perfect number!!", value);
    }
}

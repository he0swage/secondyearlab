#include <stdio.h>
#include <stdlib.h>

struct test_2
{
    int B;
    struct test_2 *next;
};

int main()
{
    struct test_2 *head = NULL;
    struct test_2 *newNode = NULL;
    struct test_2 *temp = NULL;
    int B, i, sum = 0;

    printf("Enter the number B: ");
    scanf("%d", &B);

    for (i = 0; i < B; i++)
    {
        newNode = (struct test_2 *)malloc(sizeof(struct test_2));
        newNode->B = i;
        newNode->next = NULL;

        if (head == NULL)
            head = newNode;
        else
        {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    printf("Linked list: ");
    temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->B);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}

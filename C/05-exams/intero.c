#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *creation(int item);
void insertend(struct node **head, struct node **tail, int item);
void display(struct node *head);
struct node *merge(struct node *p, struct node *q);

struct node *creation(int item)
{
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = item;
    newnode->next = NULL;
    return newnode;
}

void insertend(struct node **head, struct node **tail, int item)
{
    struct node *newnode = creation(item);

    if (*head == NULL)
    {
        *head = newnode;
        *tail = newnode;
    }
    else
    {
        (*tail)->next = newnode;
        *tail = newnode;
    }
}

void display(struct node *head)
{
    struct node *p = head;

    if (p == NULL)
    {
        printf("list is empty\n");
        return;
    }

    while (p != NULL)
    {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

struct node *merge(struct node *p, struct node *q)
{
    if (p == NULL)
        return q;
    if (q == NULL)
        return p;

    struct node *head = NULL;
    struct node *sorting = NULL;

    // Initial head
    if (p->data <= q->data)
    {
        head = sorting = p;
        p = p->next;
    }
    else
    {
        head = sorting = q;
        q = q->next;
    }

    // Merge
    while (p && q)
    {
        if (p->data <= q->data)
        {
            sorting->next = p;
            sorting = p;
            p = p->next;
        }
        else
        {
            sorting->next = q;
            sorting = q;
            q = q->next;
        }
    }

    // One list still remaining
    if (p)
        sorting->next = p;
    if (q)
        sorting->next = q;

    return head;
}

int main()
{
    struct node *head1 = NULL, *tail1 = NULL;
    struct node *head2 = NULL, *tail2 = NULL;

    int n1, n2, val;

    printf("Enter number of nodes for list 1: ");
    scanf("%d", &n1);

    for (int i = 0; i < n1; i++)
    {
        printf("Enter value: ");
        scanf("%d", &val);
        insertend(&head1, &tail1, val);
    }

    printf("List 1: ");
    display(head1);

    printf("Enter number of nodes for list 2: ");
    scanf("%d", &n2);

    for (int i = 0; i < n2; i++)
    {
        printf("Enter value: ");
        scanf("%d", &val);
        insertend(&head2, &tail2, val);
    }

    printf("List 2: ");
    display(head2);

    struct node *merged = merge(head1, head2);

    printf("Merged list: ");
    display(merged);

    return 0;
}

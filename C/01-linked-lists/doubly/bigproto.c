#include <stdio.h>
#include <stdlib.h>

// ===== STRUCTURE =====
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

// ===== PROTOTYPES =====
struct node *creation(int item);
void display(struct node *head);

void insertBeg(struct node **head, struct node **tail, int item);
void insertEnd(struct node **head, struct node **tail, int item);
void insertMiddle(struct node **head, struct node **tail, int item, int val);

void deleteBeg(struct node **head, struct node **tail);
void deleteEnd(struct node **head, struct node **tail);
void deleteMiddle(struct node **head, struct node **tail, int val);

void deleteEven(struct node **head, struct node **tail);

// ===== CREATION =====
struct node *creation(int item)
{
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = item;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

// ===== DISPLAY =====
void display(struct node *head)
{
    struct node *p = head;
    while (p != NULL)
    {
        printf("%d <=> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

// ===== INSERTION =====
void insertBeg(struct node **head, struct node **tail, int item)
{
    struct node *newnode = creation(item);

    if (*head == NULL)
    {
        *head = *tail = newnode;
    }
    else
    {
        newnode->next = *head;
        (*head)->prev = newnode;
        *head = newnode;
    }
}

void insertEnd(struct node **head, struct node **tail, int item)
{
    struct node *newnode = creation(item);

    if (*head == NULL)
    {
        *head = *tail = newnode;
    }
    else
    {
        (*tail)->next = newnode;
        newnode->prev = *tail;
        *tail = newnode;
    }
}

void insertMiddle(struct node **head, struct node **tail, int item, int val)
{
    struct node *p = *head;

    while (p != NULL && p->data != val)
        p = p->next;

    if (p == NULL)
    {
        printf("Value not found!\n");
        return;
    }

    struct node *newnode = creation(item);

    newnode->next = p->next;
    newnode->prev = p;

    if (p->next != NULL)
        p->next->prev = newnode;
    else
        *tail = newnode;

    p->next = newnode;
}

// ===== SUPPRESSION =====

void deleteBeg(struct node **head, struct node **tail)
{
    if (*head == NULL)
        return;

    struct node *temp = *head;

    if (*head == *tail)
        *head = *tail = NULL;
    else
    {
        *head = (*head)->next;
        (*head)->prev = NULL;
    }

    free(temp);
}

void deleteEnd(struct node **head, struct node **tail)
{
    if (*head == NULL)
        return;

    struct node *temp = *tail;

    if (*head == *tail)
        *head = *tail = NULL;
    else
    {
        *tail = (*tail)->prev;
        (*tail)->next = NULL;
    }

    free(temp);
}

void deleteMiddle(struct node **head, struct node **tail, int val)
{
    if (*head == NULL)
        return;

    struct node *p = *head;

    while (p != NULL && p->data != val)
        p = p->next;

    if (p == NULL)
    {
        printf("Value not found!\n");
        return;
    }

    if (p == *head)
    {
        deleteBeg(head, tail);
        return;
    }

    if (p == *tail)
    {
        deleteEnd(head, tail);
        return;
    }

    p->prev->next = p->next;
    p->next->prev = p->prev;

    free(p);
}

void deleteEven(struct node **head, struct node **tail)
{
    struct node *p = *head;

    while (p != NULL)
    {
        if (p->data % 2 == 0)
        {
            struct node *temp = p;
            p = p->next;

            if (temp == *head)
                deleteBeg(head, tail);
            else if (temp == *tail)
                deleteEnd(head, tail);
            else
            {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                free(temp);
            }
        }
        else
        {
            p = p->next;
        }
    }
}

// ===== MAIN =====

int main()
{
    struct node *head = NULL;
    struct node *tail = NULL;

    int n, item, val;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &item);
        insertEnd(&head, &tail, item);
    }

    printf("List before modifications:\n");
    display(head);

    printf("Insert at beginning: ");
    scanf("%d", &item);
    insertBeg(&head, &tail, item);

    printf("Insert at end: ");
    scanf("%d", &item);
    insertEnd(&head, &tail, item);

    printf("Insert after which value? ");
    scanf("%d", &val);
    printf("Value to insert: ");
    scanf("%d", &item);
    insertMiddle(&head, &tail, item, val);

    printf("List after insertions:\n");
    display(head);

    deleteBeg(&head, &tail);
    deleteEnd(&head, &tail);

    printf("Delete which value? ");
    scanf("%d", &val);
    deleteMiddle(&head, &tail, val);

    printf("List after deletions:\n");
    display(head);

    deleteEven(&head, &tail);
    printf("List after deleting even values:\n");
    display(head);

    return 0;
}

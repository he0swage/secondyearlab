#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *creation(int item);
void insert_end(struct node **head, struct node **tail, int item);
void transform_circular(struct node **head, struct node **tail);
void display_circular(struct node *head);

// Création d'un nœud
struct node *creation(int item)
{
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = item;
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}

// Insertion à la fin (doubly linked list)
void insert_end(struct node **head, struct node **tail, int item)
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
        newnode->prev = *tail;
        *tail = newnode;
    }
}

// Transformation en liste circulaire
void transform_circular(struct node **head, struct node **tail)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    (*tail)->next = *head;
    (*head)->prev = *tail;
}

// Affichage d'une liste circulaire
void display_circular(struct node *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct node *p = head;
    do
    {
        printf("%d <=> ", p->data);
        p = p->next;
    } while (p != head); // on s'arrête quand on revient au head

    printf("BACK TO HEAD\n");
}

int main()
{
    struct node *head = NULL;
    struct node *tail = NULL;
    int i, n, item;

    printf("Enter number of nodes:\n");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter value: ");
        scanf("%d", &item);
        insert_end(&head, &tail, item);
    }

    printf("\nDoubly list created.\n");

    transform_circular(&head, &tail);

    printf("\nCircular list:\n");
    display_circular(head);

    return 0;
}

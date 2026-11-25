#include <stdio.h>
#include <stdlib.h>

// structure
struct node
{
    int data;
    struct node *next;
};

// prototypes des fonctions
struct node *creation(int item);
void display(struct node *tail);
struct node *insertEnd(struct node *tail, int item);

// créer un nouveau nœud
struct node *creation(int item)
{
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = item;
    newnode->next = NULL;
    return newnode;
}

// insérer à la fin d’une liste circulaire
struct node *insertEnd(struct node *tail, int item)
{
    struct node *newnode = creation(item);

    if (tail == NULL)
    {
        tail = newnode;
        tail->next = tail; // circular
    }
    else
    {
        newnode->next = tail->next; // pointe vers head
        tail->next = newnode;
        tail = newnode; // nouveau tail
    }

    return tail;
}

// afficher une liste circulaire
void display(struct node *tail)
{
    if (tail == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct node *p = tail->next; // head
    do
    {
        printf("%d -> ", p->data);
        p = p->next;
    } while (p != tail->next);

    printf("(back to start)\n");
}

int main()
{
    struct node *tail = NULL;
    int n, item, i;

    printf("Enter number of nodes:\n");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter node %d data: ", i + 1);
        scanf("%d", &item);
        tail = insertEnd(tail, item);
    }

    printf("Here is your circular list:\n");
    display(tail);

    return 0;
}

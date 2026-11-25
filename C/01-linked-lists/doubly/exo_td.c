#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

int main()
{
    int i, n, item, min = 0;
    struct node *head = NULL, *p, *newnode, *temp;

    // size of the ll

    printf("enter the size of the node:\n");
    scanf("%d", &n);

    // creation of the node 0

    printf("enter the element of the node 0:\n");
    scanf("%d", &item);

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = item;
    newnode->next = NULL;
    newnode->prev = NULL;
    // important
    head = newnode;
    p = newnode;
    // enter the element of the list

    printf("enter the element of the new node:\n");
    for (i = 1; i < n; i++)
    {
        scanf("%d", &item);
        newnode = (struct node *)malloc(sizeof(struct node));

        newnode->data = item;
        newnode->next = NULL;
        newnode->prev = p;

        // important
        p->next = newnode;
        p = p->next;
    }
    // list befor deleting
    printf("here is the list before delete the end:\n");

    p = head;
    while (p != NULL)
    {
        printf("%d<->", p->data);

        // important
        p = p->next;
    }
    printf("NULL\n");
    printf("here is the list after deleting all the value <10:\n");

    // Suppression de tous les éléments < 10
    p = head;
    while (p != NULL)
    {
        if (p->data < 10)
        {
            temp = p; // on garde le nœud à supprimer

            if (p->prev == NULL) // cas 1 : premier élément
            {
                head = p->next;
                if (head != NULL)
                    head->prev = NULL;
            }
            else if (p->next == NULL) // cas 2 : dernier élément
            {
                p->prev->next = NULL;
            }
            else // cas 3 : au milieu
            {
                p->prev->next = p->next;
                p->next->prev = p->prev;
            }

            p = p->next; // on avance
            free(temp);  // on libère le nœud supprimé
        }
        else
        {
            p = p->next; // on avance si on ne supprime pas
        }
    }

    // list after deleting

    p = head;
    while (p != NULL)
    {
        printf("%d<->", p->data);

        // important
        p = p->next;
    }
    printf("NULL\n");
    printf("here is the list in asanding order:\n");

    // Tri de la liste en ordre croissant
    struct node *q;
    int tempData;

    for (p = head; p != NULL; p = p->next)
    {
        for (q = p->next; q != NULL; q = q->next)
        {
            if (p->data > q->data)
            {
                tempData = p->data;
                p->data = q->data;
                q->data = tempData;
            }
        }
    }

    // Affichage après tri
    p = head; // <- Très important !
    while (p != NULL)
    {
        printf("%d<->", p->data);
        p = p->next;
    }
    printf("NULL\n");
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ===== PROTOTYPES ===== */
typedef struct Student
{
    int id;
    char *name;
    struct Student *next;
    struct Student *prev;
} Student;

Student *createStudent(int id, const char *name);
void insertAtEnd(Student **head, Student *node);
void displayForward(Student *head);
int deleteByID(Student **head, int id);
void freeList(Student **head);

/* ===== IMPLEMENTATION ===== */

/* Create a new student node dynamically */
Student *createStudent(int id, const char *name)
{
    Student *s = (Student *)malloc(sizeof(Student));
    if (!s)
        return NULL;

    s->id = id;

    s->name = (char *)malloc(strlen(name) + 1);
    strcpy(s->name, name);

    s->next = s->prev = NULL;

    return s;
}

/* Insert node at end of circular doubly linked list */
void insertAtEnd(Student **head, Student *node)
{
    if (*head == NULL)
    {
        node->next = node->prev = node;
        *head = node;
        return;
    }

    Student *tail = (*head)->prev;

    tail->next = node;
    node->prev = tail;
    node->next = *head;
    (*head)->prev = node;
}

/* Display all students forward */
void displayForward(Student *head)
{
    if (!head)
    {
        printf("List is empty.\n");
        return;
    }

    Student *p = head;
    do
    {
        printf("ID: %d, Name: %s\n", p->id, p->name);
        p = p->next;
    } while (p != head);
}

/* Delete student by ID */
int deleteByID(Student **head, int id)
{
    if (*head == NULL)
        return 0;

    Student *p = *head;
    Student *start = p;

    do
    {
        if (p->id == id)
        {
            if (p->next == p)
            {
                /* only one node */
                free(p->name);
                free(p);
                *head = NULL;
                return 1;
            }

            /* more than one node */
            p->prev->next = p->next;
            p->next->prev = p->prev;

            if (p == *head)
                *head = p->next;

            free(p->name);
            free(p);
            return 1;
        }
        p = p->next;
    } while (p != start);

    return 0;
}

/* Free entire list */
void freeList(Student **head)
{
    if (*head == NULL)
        return;

    Student *p = *head;
    Student *start = p;

    do
    {
        Student *next = p->next;
        free(p->name);
        free(p);
        p = next;
    } while (p != start);

    *head = NULL;
}

/* ===== MAIN ===== */

int main()
{
    Student *head = NULL;

    /* creating empty list */
    printf("Creating empty list...\n");

    /* inserting three students */
    insertAtEnd(&head, createStudent(1, "Ali"));
    insertAtEnd(&head, createStudent(2, "Sara"));
    insertAtEnd(&head, createStudent(3, "Nassim"));

    printf("\nList before deletion:\n");
    displayForward(head);

    /* deleting student with ID 2 */
    printf("\nDeleting student with ID 2...\n");
    deleteByID(&head, 2);

    printf("\nList after deletion:\n");
    displayForward(head);

    /* free list */
    freeList(&head);

    return 0;
}

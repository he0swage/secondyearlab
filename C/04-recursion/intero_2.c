void hanoi(int n, char A, char B, char C);
void hanoi(int n, char A, char B, char C)
{
    if (n == 0)
        return;

    hanoi(n - 1, A, C, B);
    printf("Deplacer disque %d de %c vers %c\n", n, A, C);
    hanoi(n - 1, B, A, C);
}
// in the main :
hanoi(3, 'A', 'B', 'C');

//code complet :
------------------------------------------------------------------------------
#include <stdio.h>

/* fonction recursive */
void hanoi(int n, char A, char B, char C)
{
    /* cas de base */
    if (n == 0)
        return;

    /* deplacer n-1 disques de A vers B en utilisant C */
    hanoi(n - 1, A, C, B);

    /* deplacer le disque n de A vers C */
    printf("Deplacer le disque %d de %c vers %c\n", n, A, C);

    /* deplacer n-1 disques de B vers C en utilisant A */
    hanoi(n - 1, B, A, C);
}

int main()
{
    int n;

    printf("Donner le nombre de disques : ");
    scanf("%d", &n);

    /* A = depart, B = auxiliaire, C = arrivee */
    hanoi(n, 'A', 'B', 'C');

    return 0;
}

 -------------------------------------------------------------------------------------------------------
// stack +recursivite
void afficher_stack(stack s)
{
    typeinfo v;

    if (isempty(s))
        return;

    pop(&s, &v);
    printf("%d ", v);
    afficher_stack(s);
}

// queue +recursivite
void afficher_queue(queue q)
{
    typeinfo v;

    if (isemptyq(q))
        return;

    dequeue(&q, &v);
    printf("%d ", v);
    afficher_queue(q);
}

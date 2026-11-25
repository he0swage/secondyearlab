#include <stdio.h>

// Procédure récursive pour résoudre les tours de Hanoï
// n : nombre de disques
// p_source : nom du piquet de départ
// p_destination : nom du piquet d'arrivée
// p_auxiliaire : nom du piquet intermédiaire
void tours_de_hanoi(int n, char p_source, char p_destination, char p_auxiliaire)
{
    // Cas de base : s'il n'y a qu'un seul disque, le déplacer directement
    if (n == 1)
    {
        printf("Déplacer le disque 1 de %c vers %c\n", p_source, p_destination);
        return;
    }

    // Étape 1 : Déplacer les n-1 disques supérieurs de la source vers l'auxiliaire
    tours_de_hanoi(n - 1, p_source, p_auxiliaire, p_destination);

    // Étape 2 : Déplacer le n-ième disque (le plus grand) de la source vers la destination
    printf("Déplacer le disque %d de %c vers %c\n", n, p_source, p_destination);

    // Étape 3 : Déplacer les n-1 disques de l'auxiliaire vers la destination
    tours_de_hanoi(n - 1, p_auxiliaire, p_destination, p_source);
}

int main()
{
    int nombre_disques = 3;                        // Définir le nombre de disques
    tours_de_hanoi(nombre_disques, 'A', 'C', 'B'); // Appeler la fonction pour 3 disques de A vers C
    return 0;
}
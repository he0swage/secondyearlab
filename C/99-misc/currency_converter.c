#include<stdio.h>
#include<stdlib.h>

int main()
{
    float x;
    printf("Entrez la valeur de x en LT : ");
    scanf("%f", &x);

    float z;
    z = x / 53.3;
    printf("La valeur de x en euro est : %.2f\n", z);

    float y = z * 275;
    printf("La valeur de x en DA est : %.2f\n", y);

    return 0;
}
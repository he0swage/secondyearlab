#include <stdio.h>
// exo 7
int occur(int n, int T[], int V)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        if (T[n - 1] == V)
            return 1 + occur(n - 1, T, V);
        else
            return occur(n - 1, T, V);
    }
}

int main()
{
    int n, i, V;
    printf("Enter the size of the array:\n");
    scanf("%d", &n);

    int T[n];
    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &T[i]);
    }

    printf("Enter the value to find:\n");
    scanf("%d", &V);

    printf("The value %d appears %d times.\n", V, occur(n, T, V));
    return 0;
}
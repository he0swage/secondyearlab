#include <stdio.h>
// exo 5
int find(int n, int V, int T[])
{
    if (n == 0)
    {
        return 0;
    }
    else if (T[n - 1] == V)
    {
        return 1;
    }
    else
    {
        return find(n - 1, V, T);
    }
}

int main()
{
    int i, n, V;
    printf("Enter the size of the array:\n");
    scanf("%d", &n);

    int T[n];
    for (i = 0; i < n; i++)
    {
        printf("Enter element %d:\n", i + 1);
        scanf("%d", &T[i]);
    }

    printf("Enter the value you want to find:\n");
    scanf("%d", &V);

    if (find(n, V, T))
        printf("The value %d is found in the array!\n", V);
    else
        printf("The value %d is NOT found in the array.\n", V);

    return 0;
}

#include <stdio.h>
// exo 6
int digit(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        return 1 + digit(n / 10);
    }
}
int main()
{
    int n;
    printf("enter the number you want to find the num of digit of it:\n");
    scanf("%d", &n);
    printf("the number %d have %d digit\n", n, digit(n));
}
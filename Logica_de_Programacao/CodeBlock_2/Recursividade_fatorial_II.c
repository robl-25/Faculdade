#include <stdio.h>
#include <stdlib.h>

int recursao (int n)
{
    if (n == 2)
        return ("%d ", n*1);

    else
        return ("%d ", n*recursao(n-1));
}

void main ()
{
    int i, n;

    printf ("Digite até que número será calculado o fatorial: ");
    scanf ("%d", &n);

    for (i=2; i<=n; i++)
         printf ("\nO fatorial de %d é %d ", i, recursao(i));

    printf ("\n\n");
}

#include <stdio.h>
#include <stdlib.h>

void recursao (int n)
{
    if (n == 1)
        printf ("%d ", n);

    else{
        recursao(n-1);
        if (n%2 == 0)
        printf ("%d ", n);
    }
}

void main ()
{
    int n;

    printf ("Escreva até que número deve ser impresso na tela: ");
    scanf ("%d", &n);

    printf ("Os números ímpares até %d são:\n", n);

    recursao(n);
}


#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int a[9], i, k, j=0;

    printf ("Escreva um conjunto de 9 números inteiros: ");
    for (i=0; i<9; i++)
        scanf ("%d", &a[i]);

    printf ("\nDigite uma chave: ");
    scanf ("%d", &k);

    for (i=0; i<9; i++)
    {
        if (a[i] == k)
        {
            j=i;
            printf ("\nEssa chave se encontra na posição %d", j);
        }
    }
    if (j == 0)
        printf ("\nErro! Essa chave não se encontra na matriz");

    printf ("\n\n");

    return 0;
}

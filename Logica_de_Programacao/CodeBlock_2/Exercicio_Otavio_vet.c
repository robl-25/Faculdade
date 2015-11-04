#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int r[10], s[10], f, x[20], y[10], cont, i, j;

    printf ("Escreva os valores inteiros de r: ");
    for (cont=0; cont<10; cont ++)
        scanf ("%d", &r[cont]);

    printf ("Escreva os valores inteiros de s: ");
    for (cont=0; cont<10; cont ++)
        scanf ("%d", &s[cont]);
    f=0;
    for (cont=0; cont<10; cont ++)
        f = f + (r[cont] + s[cont]);
    for (cont=0; cont<10; cont ++)
        x[cont]=r[cont];
    for (cont=0; cont<10; cont++)
        x[(cont+10)]=s[cont];
    for (i=0; i<10; i ++)
        y[i] = r[i] * s[i];

    printf ("O valor da soma é %d", f);
    printf ("\n\nA união de r e s é: ");
    for (cont=0; cont<10; cont ++)
        printf (" %d", x[cont]);
    printf ("\n\n\nA Multiplicação é: ");
    for (j=0; j<10; j ++)
        printf (" %i", y[j]);
    printf ("\n\n\n");

    return 0;
}

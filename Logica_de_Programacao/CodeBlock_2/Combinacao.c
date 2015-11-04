#include <stdio.h>
#include <stdlib.h>



int fat (int n)
{
    int f=1;
    while (n != 1)
        {
            f= f*n;
            n--;
        }
    return f;
}

int main ()
{
    int n,k,x;
    int aux;
    printf ("Escreva dois números inteiros a para eu calcular a combinação deles: ");
    scanf ("%d %d", &n, &k);
    if (n<k)
        {
            aux=n;
            n=k;
            k=aux;
        }
    x=n-k;

    printf ("O valor dessa combinação é %d", fat(n)/fat(k)*fat(x));
    return 0;
}

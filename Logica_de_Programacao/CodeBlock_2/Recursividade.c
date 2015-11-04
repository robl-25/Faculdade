#include <stdio.h>
#include <stdlib.h>

void recursao (int n)
{
    if (n == 1)
        printf ("%d ", n);

    else{
        recursao(n-1);
        printf ("%d ", n);
    }
}

void main ()
{
    const int n=10;

    printf ("Os números até 10 são:\n");

    recursao(n);
}

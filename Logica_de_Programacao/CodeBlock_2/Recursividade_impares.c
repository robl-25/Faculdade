#include <stdio.h>
#include <stdlib.h>

void recursao (int n)
{
    if (n == 1)
        printf ("%d ", n);

    else{
        recursao(n-1);
        if (n%2 != 0)
        printf ("%d ", n);
    }
}

void main ()
{
    const int n=20;

    printf ("Os números ímpares até 20 são:\n");

    recursao(n);
}

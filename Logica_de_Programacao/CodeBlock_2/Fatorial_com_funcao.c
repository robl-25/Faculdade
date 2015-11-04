#include <stdio.h>
#include <stdlib.h>

int x;

int main ()
{
    printf ("Escreva um número inteiro a para eu calcular o fatorial dele: ");
    scanf ("%d", &x);

    printf ("O valor desse fatorial é %d", fat());
    return 0;
}

int fat ()
{
    int f=1;
    while (x != 1)
        {
            f= f* (x);
            x--;
        }
    return f;
}''

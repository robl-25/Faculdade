#include <stdio.h>

void towers (int n, char from, char to, char aux)
{
    if
    (n==1)
        printf("move disco %d da estaca %c p/ a estaca %c\n", 1, from, to);
    else
    {
        towers(n-1, from, aux, to);
        printf("move disco %d da estaca %c p/ a estaca %c\n", n, from, to);
        towers(n-1, aux, to, from);
    }

}

void main ()
{
    int n;
    char from, to, aux;

    printf ("Escreva o número de discos: ");
    scanf ("%d", &n);

    from = 'A';
    to = 'C';
    aux = 'B';

    towers(n,from,to,aux);
}

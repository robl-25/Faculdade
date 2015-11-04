#include <stdio.h>
#include <stdlib.h>

void main ()
{
    int n, i;
    float m=0;

    printf ("Escreva o número de notas a ser calculada: ");
    scanf ("%d", &n);

    int *p;

    p = (int*) malloc (n*sizeof(int));
    if (p == NULL)
        printf ("Memória Insuficiente!");

    else
        for (i=0; i<n; i++)
            scanf ("%d", &*(p+i));


    for (i=0; i<n; i++)
        m=m+(*p+i);

    m=m/n;

    printf ("A média dessa turma é %f\n", m);

}

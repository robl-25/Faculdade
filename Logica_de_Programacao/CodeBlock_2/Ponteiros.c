#include <stdio.h>
#include <stdlib.h>

const int n=5;

void minimo (int *i, int *j, int v[n])
{
    int k;
    for (k=0; k<n; k++)
    {
        if (*i < v[k])
            *i=v[k];
        if (*j > v[k])
            *j=v[k];
    }
}

void main ()
{

    int v[n], min=50000, max=0, *prt1, *prt2, i;
    printf ("Digite %d números inteiros:\n", n);
    for (i=0; i<n; i++)
        scanf ("%d", &v[i]);
    prt1= &max;
    prt2= &min;
    minimo (prt1,prt2,v);
    printf ("\nO valor máximo do vetor é %d e o minimo é %d\n", *prt1, *prt2);
}

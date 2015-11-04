#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int t1, t2, i, c1, c2, j, k, l;

    printf ("\nDigite o tamanho do vetor pai1 e do pai2: ");
    scanf ("%i %i", &t1, &t2);

    int p1[t1], p2[t2];

    printf ("Escreva os elementos do vetor pai1: ");

    for (i=1; i<t1; i++)
        scanf ("%i", &p1[i]);
    p1[0]=t1;

    printf ("\nDigite os elementos do vetor pai2: ");

    for (i=1; i<t2; i++)
        scanf ("%i", &p2[i]);
    p2[0]=t2;

    printf ("\nDigite a posição do corte do vetor pai1: ");
    scanf ("%i", &c1);
    printf ("\nDigite a posição de corte do vetor pai2: ");
    scanf ("%i", &c2);

    j=t1-c1;
    k=t2-c2-1;

    int f1[c1+k]; //f2[j+c2];

    f1[0]= c1+k;

    for (i=1; i<c1; i++)
        f1[i] = p1[i];

    l=c2+1;
    for (i=c1; i<c1+k; i++)
        {
            f1[i] = p2[l];
            l++;
        }

    printf ("\n\nO valor do vetor filho1 é:");

    for (i=0; i<c1+k; i++)
        printf (" %i", f1[i]);

}

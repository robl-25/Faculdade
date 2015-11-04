#include <stdio.h>
#include "aritmetica.h"
#include "stringmais.h"

int main ()
{
    int a, b, r, i, v[1000], n, j;
    char string1[100], string2[100], o, g, n1;
    float m;

    /*printf ("Digite qual operação será realizada: ");
    scanf ("%c", &o);
    if (o == 's')
    {
        scanf ("%d %d", &a, &b);
        r=soma (a,b);
        printf ("%d", r);
    }

    else if (o == 'm')
    {
        scanf ("%d", &n);

        for (i=0; i<n; i++)
            scanf ("%d", &v[i]);

        m=media (v,n);

        printf ("%f", m);
    }*/

    /*else if (o == 't')
    {*/
    for (i=0; i<100 ; i++)
    {
        scanf ("%c", &string1[i]);
        if (string1[i] == '\n')
        {
            g=string1[i];
            string1[i]=' ';
            break;
        }
    }
    
    for (j=0; j<100 ; j++)
    {
        scanf ("%c", &string2[j]);
        if (string2[j] == '\n')
        {
            g=string2[j];
            string2[j]=' ';
            break;
        }
    }

    /*printf ("\nEscreva qual operação a ser realizada: ");
    scanf ("%c", &n1);
    if (n1=='c')*/
    while (i>0)
    {
        printf ("%c", comparacao(string1,string2));

        /*else if (n1=='v')*/
        printf ("%c", verificacao(string1));

        /*else if (n1=='j')*/
        printf ("%c", juncao(string1,string2));
        i--;
    }

    return 0;
}


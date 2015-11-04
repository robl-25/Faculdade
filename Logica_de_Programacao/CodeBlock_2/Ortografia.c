//Nome do Programa: Ortografia
//Nome: Mariane Coelho Robl   R.A.: 86902
//Version: 1.0       1st august 2013

#include <stdio.h>

char d[1000][20], p[100][20];


void incializador (int n)
{
    int i, j;
    for (i=0; i<n; i++)
        for (j=0; j<20; j++)
            d[i][j]=' ';
}

void incializadorI (int m)
{
    int i, j;
    for (i=0; i<m; i++)
        for (j=0; j<20; j++)
            p[i][j]=' ';
}

void lerd (int n)
{
    scanf ("%s", &d[n][0]);
}

void lerp (int n)
{
    scanf ("%s", &p[n][0]);
}

int main ()
{
    int n, m, i;

    printf ("Escreva o número de palavras do dicionário: ");
    scanf ("%d", &n);
    while ((n<1) || (n>1000))
    {
        printf ("Erro! Esse número de palavras não é aceitável. Por favor, digite novamente: ");
        scanf ("%d", &n);
    }

    incializador (n);
    printf ("\nEscreva as palavras do dicionário:\n");
    for (i=0; i<n; i++)
        lerd (i);

    printf ("Escreva o número de palavras a serem corrigidas: ");
    scanf ("%d", &m);
    while ((m<1) || (m>100))
    {
        printf ("Erro! Esse número de palavras não é aceitável. Por favor, digite novamente: ");
        scanf ("%d", &m);
    }

    incializadorI (m);
    printf ("\nEscreva as palavras a serem corrigidas:\n");
    for (i=0; i<m; i++)
        lerp (i);

    return 0;
}

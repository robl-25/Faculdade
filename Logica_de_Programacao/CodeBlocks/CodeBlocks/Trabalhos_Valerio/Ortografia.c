//Nome do Programa: Ortografia
//Nome: Mariane Coelho Robl   R.A.: 86902
//Version: 1.0       1st august 2013

#include <stdio.h>
#include <string.h>

char d[1000][20], p[100][20], v[26]= {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};


void incializador ()
{
    int i, j;
    for (i=0; i<1000; i++)
        for (j=0; j<20; j++)
            d[i][j]=' ';
}

void incializadorI ()
{
    int i, j;
    for (i=0; i<100; i++)
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

char comparar (char str1[], char str2[])
{
    int k, g, fim, cont, id, e=0, i, b, j;
    char c;
    k = strlen (str1);
    g = strlen (str2);
    if (abs(k-g)>2)
        return (abs(k-g));
    else
    {
        if (k<g)
            fim=k;
        else
            fim=g;
        for (cont=0,id=0; id<fim; id++,e++)
        {
            if (str1[id] != str2[e])
            {
                cont++;
                i=abs(k-id);
                b=i;
                for (j=i; j<k; j++)
                {
                    if (str1[j] == str2[id])
                    {
                        c=str2[j];
                        str2[j]=str1[j];
                        str2[id]=c;
                        break;
                    }
                    else
                        b++;
                }
                if (b==(k-1))
                {
                    if (k == g)
                    {
                        for (j=0; str1[id] != str2[e]; j++)
                            str2[e]=v[j];
                    }
                    else if (k<g)
                            for (j=e; j<g; j++)
                                str2[j+1]=str2[j];
                        else
                            id++;
                }
            }
        }
        return cont;
    }
}

int main ()
{
    int n, m, k, i, j;

    printf ("Escreva o numero de palavras do dicionario: ");
    scanf ("%d", &n);
    while ((n<1) || (n>1000))
    {
        printf ("Erro! Esse numero de palavras nao eh aceitavel. Por favor, digite novamente: ");
        scanf ("%d", &n);
    }

    incializador ();
    printf ("\nEscreva as palavras do dicionario:\n");
    for (i=0; i<n; i++)
        lerd (i);

    printf ("\nEscreva o numero de palavras a serem corrigidas: ");
    scanf ("%d", &m);
    while ((m<1) || (m>100))
    {
        printf ("Erro! Esse numero de palavras nao eh aceitavel. Por favor, digite novamente: ");
        scanf ("%d", &m);
    }

    incializadorI ();
    printf ("\nEscreva as palavras a serem corrigidas:\n");
    for (i=0; i<m; i++)
        lerp (i);

    printf ("\nAs palavras a podem ser: ");
    for (i=0; i<m; i++)
    {
        for (j=0; j<n; j++)
        {
            if (comparar(d[j],p[i])<=2)
                printf ("\n%s", d[j]);
        }
    }
    printf ("\n");
    return 0;
}

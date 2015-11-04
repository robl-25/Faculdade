//Nome do programa: Batalha Naval
//Nome: Mariane Coelho Robl     R.A.: 86.902
//Versão: 1.0       19th Jul 2013

#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int m, n;
    char temp;

    printf ("Escreva o númeor de linhas do tabuleiro do jogo naval: ");
    scanf ("%d", &n);
    while ((n<1) || (n>100))
    {
        printf ("\nErro! Esse número não é aceitável para ser o número de linhas do jogo! \nPor favor digite novamente: ");
        scanf ("%d", &n);
    }

    printf ("\nEscreva o número de colunas: ");
    scanf ("%d", &m);
    while ((m>100) || (m<1))
    {
        printf ("\nErro! Esse número não é aceitável para ser o número de colunas do jogo! \nPor favor digite novamente: ");
        scanf ("%d", &m);
    }
    scanf ("%c", &temp);
    int i, j, k, l, c;
    char t[n][m];

    printf ("\nEscreva os elementos do tabuleiro, sendo que para o local que contiver navios \ndigite # ou . para água, e após cada linha cheia pressione enter:\n");
    for (i=0; i<n; i++)
    {
        for (j=0; j<m; j++)
        {
            scanf ("%c", &t[i][j]);
        }
        scanf ("%c", &temp);
    }
    printf ("\nEscreva o número de disparos a serem realizados: ");
    scanf ("%d", &k);

    while ((k<1) || (k>m*n))
    {
        printf ("\nErro! Esse número de tiros não é aceitável! \nDigite novamente: ");
        scanf ("%d", &k);
    }

    int jc=0;

    printf ("\nNas próximas linhas digite a posição da bomba:\n");
    for (i=0; i<k; i++)
    {
        scanf("%d %d", &l, &c);
        while ((l<1) || (l>n))
        {
            printf ("Erro! Esse nnúmero para a linha não pertence ao tabuleiro! Digite novamente: ");
            scanf ("%d", &l);
        }
        while ((c<1) || (c>m))
        {
            printf ("Erro! Esse nnúmero para a coluna não pertence ao tabuleiro! Digite novamente: ");
            scanf ("%d", &c);
        }
        if (t[l-1][c-1] == '#')
        {
            printf ("Acertou uma bomba\n");
            jc++;
        }
        else
            printf ("Você errou!\n");
    }
    printf ("\nO número de bombas que acertaram um navio foram %d", jc);

    return 0;
}


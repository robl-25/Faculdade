/*
Nome: Mariane COelho Robl
R.A.: 86902
*/
#include <stdio.h>
#include <stdlib.h>
#define Max_Linha 1000

struct me
{
    int val, col;
    struct me *prox;
};

typedef struct me *pme;
typedef pme matriz[Max_Linha];

void inicializa(matriz m, int lin)
{
    int i;
    for (i=0; i<lin; i++)
        m[i] = NULL;
}

void insere (matriz m, int i, int j, int v)
{
    pme novo, p;
    novo = (pme) malloc (sizeof(struct me));
    novo->col = j;
    novo->val = v;
    novo->prox = NULL;
    if (m[i] == NULL)
        m[i] = novo;
    else
    {
        for(p=m[i]; p->prox != NULL; p = p->prox);
        p->prox = novo;
    }
}

void imprime (matriz m, int lin)
{
    pme p;
    int i, j, col;
    col=lin;
    if (lin == 0)
        printf ("\n\t***Matriz Vazia!!!***\n");
    else
    {
        for (i=0; i<lin; i++)
        {
            p = m[i];
            printf ("\n");
            for(j=0; j<col; j++)
                if (p == NULL || p->col != j)
                    printf (" 0 ");
                else
                {
                    printf (" %d ", p->val);
                    p = p->prox;
                }
        }
        printf("\n");
    }
}

void libera (matriz m, int lin)
{
    pme p, q;
    int i;
    for(i=0; i<lin; i++)
        if (m[i] != NULL)
        {
            for(p=m[i]; p!= NULL; p = q)
            {
                q = p->prox;
                free(p);
            }
            m[i] = NULL;
        }
        else
            free(m[i]);

}

void soma (matriz m1, matriz m2, int lin1)
{
    pme p1, p2;
    matriz res;
    int i, j;
    inicializa(res,lin1);
    for(i=0; i<lin1; i++)
    {
        p1 = m1[i];
        p2 = m2[i];
        for(j=0; j<lin1; j++)
        {
            if (p1 == NULL && p2 == NULL)
                j= lin1;

            else if (p1 == NULL)
            {
                if (p2->col == j)
                {
                    insere(res,i,j,p2->val);
                    p2=p2->prox;
                }
            }

            else if (p2 == NULL)
            {
                if (p1->col == j)
                {
                    insere(res,i,j,p1->val);
                    p1=p1->prox;
                }
            }
            else
            {
                if(p1->col == j && p2->col == j)
                {
                    insere(res,i,j,p1->val+p2->val);
                    p1=p1->prox;
                    p2=p2->prox;
                }
                else if (p1->col == j)
                {
                    insere(res,i,j,p1->val);
                    p1=p1->prox;
                }
                else if (p2->col == j)
                {
                    insere(res,i,j,p2->val);
                    p2=p2->prox;
                }
            }
        }

    }
    imprime(res,lin1);
    libera(res,lin1);
}

void subtracao (matriz m1, matriz m2, int lin1)
{
    pme p1, p2;
    matriz res;
    int i, j;
    inicializa(res,lin1);
    for(i=0; i<lin1; i++)
    {
        p1 = m1[i];
        p2 = m2[i];
        for(j=0; j<lin1; j++)
        {
            if (p1 == NULL && p2 == NULL)
                j= lin1;

            else if (p1 == NULL)
            {
                if (p2->col == j)
                {
                    insere(res,i,j,p2->val);
                    p2=p2->prox;
                }
            }

            else if (p2 == NULL)
            {
                if (p1->col == j)
                {
                    insere(res,i,j,p1->val);
                    p1=p1->prox;
                }
            }
            else
            {
                if(p1->col == j && p2->col == j)
                {
                    insere(res,i,j,p1->val-p2->val);
                    p1=p1->prox;
                    p2=p2->prox;
                }
                else if (p1->col == j)
                {
                    insere(res,i,j,p1->val);
                    p1=p1->prox;
                }
                else if (p2->col == j)
                {
                    insere(res,i,j,p2->val);
                    p2=p2->prox;
                }
            }
        }

    }
    imprime(res,lin1);
    libera(res,lin1);
}

int busca (int j, pme p2)
{
    if (p2 == NULL)
        return 0;

    while (p2->prox != NULL)
    {
        if (p2->col == j)
            return (p2->val);

        p2 = p2->prox;
    }
    return 0;
}

void multiplicacao (matriz m1, matriz m2, int lin)
{
    pme p1;
    matriz res;
    int i, j, va=0, c2, c1, k;

    inicializa(res,lin);

    for (i=0; i<lin; i++)
    {
        p1 = m1[i];

        for (k=0; k<lin; k++)
        {
            for (j=0; j<lin; j++)
            {
                c2 = busca(i,m2[j]);

                if (p1 == NULL || p1->col != j)
                    c1 = 0;

                else
                {
                    c1 = p1->val;
                    p1 = p1->prox;
                }

                va += c2 * c1;
            }
            insere(res,i,k,va);
            va=0;
        }
    }

    imprime(res,lin);
    libera(res,lin);
}

int main()
{
    matriz m1, m2;
    int lin1, i, j, val, menu, cont=0;

    do
    {
        printf ("\n\t===Menu===\n");
        printf ("1) Inserir novas matrizes\n");
        printf ("2) Somar matrizes\n");
        printf ("3) Subtrair matrizes\n");
        printf ("4) Multiplicar matrizes\n");
        printf ("5) Sair\n");
        printf ("Escolha um das opcoes acima: ");
        scanf ("%d", &menu);

        if (menu > 5)
            printf ("Opcao invalida!!!");

        switch (menu)
        {
        case 1:
            cont++;
            if(cont != 1)
            {
                libera(m1,lin1);
                libera(m2,lin1);
            }

            printf ("Escreva o numero de linhas das matrizes quadradas: ");
            scanf("%d", &lin1);

            inicializa(m1,lin1);
            inicializa(m2,lin1);

            for(i=0; i<lin1; i++)
            {
                for(j=0; j<lin1; j++)
                {
                    printf("\nDigite o elemento da linha %d e coluna %d da primeira matriz: ", i+1, j+1);
                    scanf("%d", &val);
                    if(val != 0)
                        insere(m1,i,j,val);
                }
            }

            for(i=0; i<lin1; i++)
            {
                for(j=0; j<lin1; j++)
                {
                    printf("\nDigite o elemento da linha %d e coluna %d da segunda matriz: ", i+1, j+1);
                    scanf("%d", &val);
                    if(val != 0)
                        insere(m2,i,j,val);
                }
            }
            break;
        case 2:
            soma(m1,m2,lin1);
            break;
        case 3:
            subtracao(m1,m2,lin1);
            break;
        case 4:
            multiplicacao(m1,m2,lin1);
            break;
        case 5:
            libera(m1,lin1);
            libera(m2,lin1);
            break;
        }
    }
    while(menu != 5);
    return 0;
}

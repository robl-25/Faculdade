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

int valor_medio(matriz m, int lin){
	pme p;
	int i, j, linm;
	float x, maior=0;

	for(i=0; i<lin; i++){
		p = m[i];
		x=0;
		for(j=0; j<lin; j++)
			if(p == NULL)
				j = lin;
			else{
				if(p->col == j){
					x += (p->val)/2;
					p = p->prox;
				}
			}
		if (x > maior){
			maior = x;
			linm = i+1;
		}
	}
	return (linm);
}

pme busca(int j, pme p2){
    if (p2 == NULL)
        return 0;

    while (p2->prox != NULL)
    {
        if (p2->col == j)
            return (p2);

        p2 = p2->prox;
    }
    return NULL;
}

void soma(matriz m, int k, int i){
    pme p;
    for(p=m[i]; p != NULL; p = p->prox)
        p->val += k;
}

int valor_medio_col(matriz m, int lin){
	pme p;
	int i, j, l;
	float x, maior=0;

	for(j=0; j<lin; j++){
		x=0;
		for(i=0; i<lin; i++){
			p = busca(j,m[i]);
            if (p != NULL){
                x += (p->val)/2;
            }
		}
		if (x > maior){
			maior = x;
			printf("\n%f\n", maior);
			l = j+1;
		}
	}
	return l;
}

int main(){

	matriz m1;
	int lin1, m, i, j, val, lin, col,k, y;

	printf ("Escreva o numero de linhas das matrizes quadradas: ");
            scanf("%d", &lin1);

            inicializa(m1,lin1);

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
    lin = valor_medio(m1,lin1);
    col = valor_medio_col(m1,lin1);
	printf("\nA linha com a maior media eh %d e a coluna eh %d\n",lin,col);
	printf("\nDigite o valor a ser soma e depois a linha onde ele sera somado: ");
	scanf("%d %d",&k,&y);
    soma(m1,k,y);
	imprime(m1,lin1);
	libera(m1,lin1);
}

#include <stdio.h>
#include <stdlib.h>

#define M 2
#define MM (2 * M)

typedef int TChave;

typedef struct {
	TChave Chave;
	/* outros compomentes */
} TItem;

typedef int TIndice;

typedef struct SNo *TArvoreB;

typedef struct SNo {
	TItem Item[MM];
    TArvoreB pai;
	TArvoreB Pagina[MM + 1];
	TIndice n;
} TNo;

int EhInterno(TArvoreB No)
{
	return (No != NULL) && (No->Pagina[0] != NULL);
}

int EhExterno(TArvoreB No)
{
	return (No != NULL) && (No->Pagina[0] == NULL);
}

TArvoreB Inicializa()
{
	return NULL;
}

TArvoreB Pesquisa(TArvoreB Raiz, TChave x)
{
	// Implemente o seu metodo aqui!
}

TArvoreB aloca(){
    int i;
    TArvoreB No = (TArvoreB) malloc(sizeof(TNo));
    No->n = 0;
    No->pai = NULL;
    for(i = 0; i < MM + 1; i++){
        No->Pagina[i] = NULL;
    }
    return No;
}

void sort (TItem *A, int n){
	int i, j;
	TItem aux;
	for( i = 0; i < (n - 1); i++ ){
		for ( j = 1; j < (n - i); j++){
			if(A[j].Chave < A[j - 1].Chave){
				aux = A[j];
				A[j] = A[j - 1];
				A[j - 1] = aux;
			}
		}
	}
}

TArvoreB sortPage(TArvoreB *A, int n){
    int i, j;
	TArvoreB aux;
	for( i = 0; i < (n - 1); i++ ){
		for ( j = 1; j < (n - i); j++){
			if(A[j]->Item[0].Chave < A[j - 1]->Item[0].Chave){
				aux = A[j];
				A[j] = A[j - 1];
				A[j - 1] = aux;
			}
		}
	}
}

TArvoreB inserePai(TItem *x, TArvoreB aux){
    if (aux->pai == NULL){
        TArvoreB pai = aloca();
        TArvoreB filho = aloca();
        pai->n = 1;
        pai->Item[0] = x[2];
        pai->Pagina[1] = aux;
        pai->Pagina[0] = filho;
        filho->pai = pai;
        filho->Item[0] = x[0];
        filho->Item[1] = x[1];
        filho->n = 2;
        aux->pai = pai;
        aux->Item[0] = x[3];
        aux->Item[1] = x[4];
        aux->n = 2;
        return pai;
    }
	TArvoreB pai = aux->pai;
    if (pai->n < MM){/*
        TArvoreB filho = aloca();
        filho->Item[0] = x[0];
        filho->Item[1] = x[1];
        filho->pai = pai;
        filho->n = 2;
        pai->Item[pai->n] = x[2];
        pai->n++;
        pai->Pagina[pai->n] = filho;
        sort(pai->Item, pai->n);
        aux->Item[0] = x[3];
        aux->Item[1] = x[4];
        sortPage(pai->Pagina, pai->n+1);
		printf("%d, %d, %d", pai->Pagina[0]->Item[0].Chave, 
		pai->Pagina[1]->Item[0].Chave, pai->Pagina[2]->Item[0].Chave);
		scanf("%d", &x[1].Chave);*/
        return (pai);

    }
}

void Insere(TArvoreB *pRaiz, TItem x)
{
    TArvoreB aux = (*pRaiz);
    //Se a raiz for nula, alocamos ela, e inserimos o primeiro elemento
	if ((*pRaiz) == NULL){
        (*pRaiz) = aloca();
        (*pRaiz)->Item[(*pRaiz)->n] = x;
        (*pRaiz)->n++;
        return;
	}
    else{
    //Se for externo...
        if(EhExterno(aux)){
        	//E a pagina nao estiver cheia...
            if(aux->n < MM){
                aux->Item[aux->n] = x;
                aux->n++;
                sort(aux->Item, aux->n);
            }
            //Se a página estiver cheia, começa os paranauê
            else{
                TItem temp[MM+1];
                int i;
                for(i = 0; i < MM; i++){
                    temp[i] = aux->Item[i];
                }
                temp[MM] = x;
                sort(temp, MM+1);
                (*pRaiz) = inserePai(temp, (*pRaiz));

            }
        }
        else{
            int sucesso = 0;
            TIndice i = 0;
            while(sucesso == 0){
                if(i == MM){
                    Insere(&aux->Pagina[MM], x);
					sucesso = 1;
                }
				else if(i == aux->n){
                    Insere(&aux->Pagina[i], x);
                    sucesso = 1;
                }
                else if(x.Chave < aux->Item[i].Chave){
                    Insere(&aux->Pagina[i], x);
                    sucesso = 1;
                }
                i++;
			
            }
			//printf("\n%d\n", aux->Item[i].Chave);
        }
    }
}

void Carrega(TArvoreB *pNo)
{
	int i, n;
	TItem x;

	scanf("%d", &n);
	for (i = 0; i < n ; i++) {
		scanf("%d", &x.Chave);
		Insere(pNo, x);
	}
}

void Libera(TArvoreB *pNo)
{
	TArvoreB No;
	TIndice i;

	No = *pNo;
	if (No != NULL) {
		for (i = 0; i <= No->n; i++)
			Libera(&No->Pagina[i]);
		free(No);
		(*pNo) = NULL;
	}
}

void Imprime(TArvoreB No)
{
	TIndice i;
	char c;
	if (No != NULL) {
		printf("(");
		for (i = 0; i < No->n; i++) {
			//printf("**%d**", No->n);
			//scanf("%c", &c);
			Imprime(No->Pagina[i]);
			printf("C%d", No->Item[i].Chave);
		}
		Imprime(No->Pagina[No->n]);
		printf(")");
	}
	else
		printf("()");
}

int main()
{
	TArvoreB Raiz;
	TItem x;

	Raiz = Inicializa();
	Carrega(&Raiz);
	scanf("%d", &x.Chave);
	if (Pesquisa(Raiz, x.Chave) == NULL)
		Insere(&Raiz, x);
	Imprime(Raiz);
	Libera(&Raiz);

	return 0;
}



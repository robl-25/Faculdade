#include <stdio.h>
#include <stdlib.h>

typedef int TChave;

typedef struct {
	TChave Chave;
	/* outros compomentes */
} TItem; 

typedef int TIndice;

typedef struct {
	TItem *Item;
	//n=quantidade de itens da tabela e 
	//max=quantos elementos eu tenho disponivel para colocar na tabela
	TIndice n, max;
} TTabela;

/* inicializa uma tabela */
TTabela *Inicializa()
{
	TTabela *T;
	T = (TTabela *) malloc(sizeof(TTabela));
	T->n = 0;
	T->max = 10;
	T->Item = (TItem *) malloc(T->max * sizeof(TItem));
	return T;
}

/* encontra e retorna o indice da chave x na tabela */
TIndice Pesquisa(TTabela *T, TChave x)
{
	TIndice i;
	
	for(i=0; i < T->n; i++)//Pesquisa o elemento
		if(T->Item[i].Chave == x)
			return i;
	//Caso chega-se nesse ponto, eh porque a pesquisa foi sem sucesso
	return -1;
}

/* insere um registro na tabela */
void Insere(TTabela *T, TItem x)
{
	//verifico se eu tenho espaco disponivel na tabela, 
	//e se n for igual a max a tabela esta cheia
	if (T->n == T->max)
	{
		T->max += 2;
		T->Item = (TItem *)realloc(T->Item, T->max * sizeof(TItem));
	}
	//insiro um elemento na posicao n, 
	//pois quando chegar aqui eh certeza que tem espaco, e depois soma-se +1
	T->Item[T->n++] = x;
}

void Carrega(TTabela *T)
{
	int i, n;
	TItem x; 
	
	scanf("%d", &n);
	for (i = 0; i < n ; i++) {
		scanf("%d", &x.Chave);
		Insere(T, x);
	}
}

void Libera(TTabela **T)
{
	TTabela *aux;
	
	aux = *T;
	if (aux != NULL) {
		if (aux->Item != NULL) free(aux->Item);
		free(aux);
		(*T) = NULL;
	}
}

void Imprime(TTabela *T)
{
	int i;
	if (T->n > 0) {
		printf("%d", T->Item[0].Chave);
		for (i = 1; i < T->n; i++)
			printf(" %d", T->Item[i].Chave);
		printf("\n");
	}
}

int main()
{
	TTabela *T;
	TIndice i;
	TChave x;

	T = Inicializa();
	Carrega(T);
	scanf("%d", &x);
	i = Pesquisa(T, x);
	//if (i != -1)
		printf("%d\n", i);
	//else
		//printf("Pesquisa sem sucesso");
	Libera(&T);
		
	return 0;
}

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


TIndice Binaria (TTabela *T, TIndice esq, TIndice dir, TChave x)
{
	TIndice meio;
	
	meio = (esq + dir) / 2;
	
	if((x != T->Item[meio].Chave) && (esq == dir))
		return -1;

	else if (x < T->Item[meio].Chave)
		return Binaria(T, esq, meio-1, x);

	else if(x > T->Item[meio].Chave)
		return Binaria(T, meio+1, dir, x);
	else
		return meio;

}

/* encontra e retorna o indice da chave x na tabela */
TIndice Pesquisa(TTabela *T, TChave x)
{
	return Binaria(T, 0, T->n-1, x);
}

void Metodo(TTabela *T)
{
	TItem aux;
	int i, j;
	for(i=1; i<T->n; i++)
	{
		aux = T->Item[i];
		j = i-1;
	while((j>=0) && (T->Item[j].Chave > aux.Chave))
	{
		T->Item[j+1] = T->Item[j];
		j--;
	}

	T->Item[j+1] = aux;

	}
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
	Metodo(T);//Ordena o vetor
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
	printf("%d\n", i);
	Libera(&T);
		
	return 0;
}


#include <stdio.h>
#include <stdlib.h>

typedef int TChave;

typedef struct {
	TChave Chave;
	/* outros compomentes */
} TItem;

int Carrega(TItem **A)
{
	int i, n;

	scanf("%d", &n);

	if (n > 0) {
		(*A) = (TItem *) malloc(n * sizeof(TItem));
		for (i = 0; i < n ; i++)
			scanf("%d", &(*A)[i].Chave);
	}
	else
		(*A) = NULL;

	return n;
}

void Libera(TItem **A)
{
	if ((*A) != NULL) {
		free(*A);
		(*A) = NULL;
	}
}

void Imprime(TItem *A, int n)
{
	int i;
	if (n > 0) {
		printf("%d", A[0].Chave);
		for (i = 1; i < n; i++)
			printf(" %d", A[i].Chave);
		printf("\n");
	}
}

int quickSort_particao(TItem *A, int p, int r)//faz as trocas de cada particao
{
	TItem aux, x;
	int i, j;

	//o pivo e retirado do vetor para as comparacoes
	x = A[r];
	//So anda para os menores que o pivo,
	//e comeca uma casa antes do primeiro elemento da particao
	i = p - 1;
	//Vai andar todos os elementos
	for (j = p; j <= r - 1; j++)
		//Se o elemento da posicao j for menor que o pivo,
		//ira trocar para o lado esquerdo do pivo, ou seja,
		//menos ou iguais ao pivo ficarao no lado esquerdo dele e
		//maiores no direito
		if (A[j].Chave <= x.Chave)
		{
			i++;
			aux = A[i];
			A[i] = A[j];
			A[j] = aux;
		}

	//i ira parar no local onde a proxima posicao deve ser o insercao do pivo
	aux = A[i+1];
	A[i+1] = A[r];
	A[r] = aux;

	return i+1;
}

void quickSort_ordena(TItem *A, int p, int r)
{
	int q;

	if(p < r)//Se p > r eh porque o vetor ja esta ordenado
	{
		q = quickSort_particao(A,p,r);
		quickSort_ordena(A,p,q-1);
		quickSort_ordena(A,q+1,r);
	}

}

void quickSort(TItem *A, int n){
	quickSort_ordena(A,0,n-1);
}

int main()
{
	TItem *A;
	int n;

	n = Carrega(&A);
	quickSort_particao(A, 0, n-1);
	Imprime(A, n);
	quickSort(A, n);
	Imprime(A, n);
	Libera(&A);

	return 0;
}

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

void heapRefaz(TItem *A, int esq, int dir)
{
	TItem aux;
	int i, j;

	i = esq;
	aux = A[esq];//Recebe o local que nao respeita o heap
	j = i * 2 + 1;
	/*Recebe o filho, por exemplo, o primeiro nó sempre igual a 0,
	logo o primeiro filho sera 2*0+1=1*/

	while(j <= dir)
	{
		//faz o j apontar para o maior filho
		if((j < dir) && (A[j].Chave < A[j+1].Chave))
			j++;
		/*Caso, o maior filho for menor que o aux acaba o while e
		 o aux fica como pai dele*/
		if (aux.Chave >= A[j].Chave)
			break;
		//Caso, ainda nao tenha achado o lugar do aux
		A[i] = A[j];
		i = j;
		j = i * 2 + 1;
	}
	//Coloca o aux no local que respeite o heap
	//(o pai sempre maior que os filhos, caso eles existam)
	A[i] = aux;
}

//O pai sempre tem que ser maior que os filhos, caso eles existam!!!!
void heapConstroi(TItem *A, int n)
{
	int esq;
	esq = (n/2) -1;
	//Começa de traz para frente
	//(obs.: transforma um vetor em um vetor que satisfaz as condicoes de heap)
	while(esq >= 0)
	{
		//Vai verificando se o vetor forma uma subavore
		// que satisfaz a condicao de heap ate chegar na arvore
		heapRefaz(A, esq, n-1);
		//Vai decrementando
		esq--;
	}
}

//Ordena o heap de forma crescente
void heapSort(TItem *A, int n)
{
	TItem aux;
	int m;

	//Constroi primeiramente o heap
	heapConstroi(A,n);

	m = n-1;

	while(m > 0)
	{
		//Troca de lugar o maior com o menor, para o maior ficar por ultimo
		aux = A[m];
		A[m] = A[0];
		A[0] = aux;
		m--;
		//Agora ordena o heap sem contar com o maior
		heapRefaz(A,0,m);
	}
}

int main()
{
	TItem *A;
	int n;

	n = Carrega(&A);
	//heapRefaz(A, 0, n-1);
	//Imprime(A, n);
	//heapConstroi(A, n);
	//Imprime(A, n);	
	heapSort(A, n);
	Imprime(A, n);
	Libera(&A);

	return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef int TChave;

//struct dos elementos
typedef struct {
	TChave Chave;
	/* outros compomentes */
} TItem; 

void Imprime(TItem *A, int n)//funcao imprime
{
	int i;
	if (n > 0) {
		printf("%d", A[0].Chave);
		for (i = 1; i < n; i++)
			printf(" %d", A[i].Chave);
		printf("\n");
	}
}

void Metodo(TItem *A, int n)
{
	TItem aux;	
	int i, j;
	
	for(i=1; i<n; i++)
	{
		aux = A[i];
		j = i-1;
		while((j>=0) && (A[j].Chave > aux.Chave))
		{
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = aux;
		Imprime(A,n);
	}
}

int main()
{
	TItem *A;
	int i, n;

	scanf("%d", &n);//numero de entrada
	A = (TItem *) malloc(n * sizeof(TItem));
	for (i = 0; i < n ; i++)
		scanf("%d", &A[i].Chave);//entradas
		
	Metodo(A, n);
		
	return 0;
}

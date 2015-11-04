#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef int TChave;

typedef struct {
	TChave Chave;
	/* outros compomentes */
} TItem; 

TItem *Aloca(int n)
{
	return ((n > 0) ? ((TItem *) malloc(n * sizeof(TItem))) : (NULL));
}

int Carrega(TItem **A)
{
	int i, n;
	
	scanf("%d", &n);
	
	(*A) = Aloca(n);
	for (i = 0; i < n ; i++)
		scanf("%d", &(*A)[i].Chave);

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

TChave maiorChave(TItem *A, int n)
{
	TChave max;
	int i;
	
	max = 0;
	for (i = 0; i < n; i++)
		if (A[i].Chave > max)
			max = A[i].Chave;

	return max;
}

int numeroDigitos(TChave numero)
{
	return (int)ceil(log(numero));
}

int retornaDigito(TChave numero, int indice)
{
	return (numero / (int)pow(10, indice)) % 10;
}

void Ordena(TItem *A, int n, int k)
{
	TItem *B;
	TChave *C;
	int i, j;

	B = (TItem *) malloc(sizeof(TItem)*n);
	C = (TChave *) malloc(sizeof(TChave)*(k+1));

	for(i=0; i <= k; i++)
		C[i] = 0;
		
	for(j=0; j<n; j++)//Vai acessar o conteudo de A e incrementa 1
		C[A[j].Chave]++;//Pega o numero da posicao j de A e 
		//coloca 1 nessa posicao em C, por exemplo, o 0 fica na posicao 1, 
		//logo sera armazenado em C o valor 1, que o local da posicao.

	for(i=1; i <= k; i++)
		C[i] += C[i-1];

	for(j = n-1; j >= 0; j--)
		B[--C[A[j].Chave]] = A[j];
	/*	Pega o valor de A[j] e 
		coloca no local correto, que sera indicado pelo vetor C.
		
		Isso sera: 
		chave recebe o A[j].Chave, c[chave] recebe C[chave] - 1, 
		indice recebe C[chave] e B[indice] recebe A[j].
		
		Melhor representacao disso seria:
		chave = A[j].Chave;
		C[chave] = C[chave] - 1;
		indice = C[chave];
		B[indice] = A[j];
	*/

	for(j = 0; j < n; j++)
		A[j] = B[j];
	
	free(B);
	free(C);
}

int main()
{
	int d, k, n;
	TItem *A;

	n = Carrega(&A);
	k = maiorChave(A, n);
	d = numeroDigitos(k);
	Ordena(A, n, k); // Ajuste o parametro do seu metodo aqui!
	Imprime(A, n);
	Libera(&A);
		
	return 0;
}


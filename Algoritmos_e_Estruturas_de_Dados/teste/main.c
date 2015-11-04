#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int maiorvalor(int v[], int indice, int maior, int n)
{
	if(indice == n)
		return maior;

	if(v[indice] > maior)
		maior = v[indice];

	return maiorvalor(v, indice+1, maior, n);
}

int menorvalor(int v[], int indice, int menor, int n)
{
    if (indice == n)
        return menor;

    if (v[indice] < menor)
        menor = v[menor];

    return menorvalor(v, indice+1, menor, n);
}

void main()
{
	int *v, i, n, menor;

	printf ("Escreva o tamanho do vetor: ");
	scanf ("%d", &n);

	v = (int *) malloc(sizeof(int)*n);

    printf ("Escreva os elementos do vetor:\n");
	for(i=0; i<n; i++){
		scanf ("%d", &v[i]);
		//printf("v[%d]: %d\n", i, v[i]);
	}
    menor = v[0];
	printf("\n%d\n", maiorvalor(v, 0, 0, n));
	printf("\n%d\n", menorvalor(v, 0, menor, n));
}

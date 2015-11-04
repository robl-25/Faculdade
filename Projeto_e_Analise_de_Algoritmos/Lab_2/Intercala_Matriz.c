#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct{
  int linha;
}info;

typedef struct{
    int N;
    int coluna;
    int* v;
}vetor;

int compare (const void * a, const void * b){
  return ( *(int*)a - *(int*)b );
}

void ImprimeVetor(int vetor[], int K){
  int j;
  for(j=0; j<K; j++){
      if(vetor[j] < INT_MAX){
        printf("%d ", vetor[j]);
      }
  }
}

void heapRefaz(info* A, vetor* entrada, int esq, int dir){
  info aux;
	int i, j;

	i = esq;
	aux = A[esq];//Recebe o local que nao respeita o heap
	j = i * 2 + 1;
	/*Recebe o filho, por exemplo, o primeiro nó sempre igual a 0,
	logo o primeiro filho sera 2*0+1=1*/

	while(j <= dir){
		//faz o j apontar para o maior filho
		if((j < dir) &&
       (entrada[A[j].linha].v[entrada[A[j].linha].coluna]
         > entrada[A[j+1].linha].v[entrada[A[j+1].linha].coluna]))
			j++;

		/*Caso, o menor filho for menor que o aux acaba o while e
		 o aux fica como pai dele*/
		if(entrada[aux.linha].v[entrada[aux.linha].coluna]
       <= entrada[A[j].linha].v[entrada[A[j].linha].coluna])
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

//O pai sempre tem que ser menor que os filhos, caso eles existam!!!!
void heapConstroi(info* res, vetor* v, int n){
	int esq;
	esq = (n/2) -1;
	//Começa de traz para frente
	//(obs.: transforma um vetor em um vetor que satisfaz as condicoes de heap)
	while(esq >= 0){
		//Vai verificando se o vetor forma uma subavore
		// que satisfaz a condicao de heap ate chegar na arvore
		heapRefaz(res, v, esq, n-1);
		//Vai decrementando
		esq--;
	}
}

int main(){
    int K, i, m;
    int j, a, min, linha;

    info aux;

    scanf("%d", &K);
    scanf("%d", &i);

    vetor entrada[K];
    info res[K];
    int resultado[K];

    for(j=0; j<K; j++){
        scanf("%d",&entrada[j].N);
        if(entrada[j].N <= 0){
            entrada[j].v = (int*) malloc(sizeof(int));
            entrada[j].v[0] = INT_MAX;
        }
        else{
            entrada[j].v = (int*) malloc(sizeof(int)*entrada[j].N);
            for(a=0; a<entrada[j].N; a++){
                scanf("%d", &entrada[j].v[a]);
            }
        }
        res[j].linha = j;
        entrada[j].coluna = 0;
    }

    heapConstroi(res, entrada, K);

    for(j=1; j<i; j++){
        a = res[0].linha;
        entrada[a].coluna++;
        entrada[a].N--;
        if(entrada[a].N <= 0){
            entrada[a].v[entrada[a].coluna] = INT_MAX;
        }
        heapRefaz(res, entrada, 0, K-1);
    }

    for(j=0; j<K; j++){
        if(entrada[res[j].linha].N > 0){
            resultado[j] = entrada[res[j].linha].v[entrada[res[j].linha].coluna];
        }
        else{
            resultado[j] = INT_MAX;
        }
    }

    qsort(resultado, K, sizeof(int), compare);

    ImprimeVetor(resultado, K);

    return 0;
}

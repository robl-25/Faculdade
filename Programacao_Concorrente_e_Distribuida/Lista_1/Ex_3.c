#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#include <omp.h>
#include <time.h>
#include <string.h>

typedef struct{
    double** matriz1;
    double** matriz2;
    int inicio, fim;
    double** matriz3;
}inf;

void le_entrada(char** args, double* N, int* Tam_Thread){
	*N =  (double) strtol(args[1], (char**) NULL, 10);
	*Tam_Thread =  (int) strtol(args[2], (char**) NULL, 10);

	*N = pow(10, *N);
}

void* Media(void* v){
    int i, j;
    inf* informacao = (inf*) v;

    for(i = informacao->inicio; i < informacao->fim; i++){
        //informacao->vetor[i] = rand_r(&informacao->inicio);
        for(j=0; j<N; j++){
            informacao->matriz3[i][j] = informacao->matriz1[i][j] +
                                          informacao->matriz2[i][j];
        }
    }
}

void main(int x, char** args){
    int Tam_Thread;
    double N;

    le_entrada(args, &N, &Tam_Thread);

    inf informacao[Tam_Thread];
    double soma_total;
    double** matriz1;
    double** matriz2;
    double** matriz3;
    int i, j;
    double tempo, expoente;
    pthread_t t[Tam_Thread];

    srand(time(NULL));

    matriz1 = (double**) malloc(sizeof(double*)*N);
    matriz2 = (double**) malloc(sizeof(double*)*N);
    matriz3 = (double**) malloc(sizeof(double*)*N);

    tempo = omp_get_wtime();

    for(i=0; i<N; i++){
        matriz1[i] = (double*) malloc(sizeof(double)*N);
        matriz2[i] = (double*) malloc(sizeof(double)*N);
        matriz3[i] = (double*) malloc(sizeof(double)*N);

        for(j=0; j<N; j++){
            matriz1[i][j] = i;
            matriz2[i][j] = j;
        }
    }
    tempo = omp_get_wtime() - tempo;
    expoente = log10(N);
	fprintf(stderr, "\nTempo de preenchimendo do vetor de %lf: %.3lfs \n", expoente, tempo);

    tempo = omp_get_wtime();
    for(i=0; i<Tam_Thread; i++){
        informacao[i].inicio = i*N/Tam_Thread;
        informacao[i].fim = informacao[i].inicio + (N/Tam_Thread);
        informacao[i].matriz1 = matriz1;
        informacao[i].matriz2 = matriz2;
        informacao[i].matriz3 = matriz3;
        pthread_create(&t[i], NULL, Media, (void*) &informacao[i]);
    }

    for(i=0; i<Tam_Thread; i++){
        pthread_join(t[i], NULL);
    }

    tempo = omp_get_wtime() - tempo;
	printf("%.3lf ", tempo);
}

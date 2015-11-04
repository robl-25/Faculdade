#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#include <omp.h>
#include <time.h>
#include <string.h>

typedef struct{
    double* vetor;
    int inicio, fim;
    double soma_parcial;
}inf;

void le_entrada(char** args, double* N, int* Tam_Thread){
	*N =  (double) strtol(args[1], (char**) NULL, 10);
	*Tam_Thread =  (double) strtol(args[2], (char**) NULL, 10);

	*N = pow(10, *N);
}

void* Media(void* v){
    int i;
    inf* informacao = (inf*) v;

    for(i = informacao->inicio; i < informacao->fim; i++){
        //informacao->vetor[i] = rand_r(&informacao->inicio);
        informacao->vetor[i] = i;
        informacao->soma_parcial += informacao->vetor[i];
    }
}

void main(int x, char** args){
    int Tam_Thread;
    double N;

    le_entrada(args, &N, &Tam_Thread);

    inf informacao[Tam_Thread];
    double soma_total, tempo;
    double* vetor;
    int i;
    pthread_t t[Tam_Thread];

    vetor = (double*) malloc(sizeof(double)*N);

    tempo = omp_get_wtime();

    for(i=0; i<Tam_Thread; i++){
        informacao[i].inicio = i*N/Tam_Thread;
        informacao[i].fim = informacao[i].inicio + (N/Tam_Thread);
        informacao[i].soma_parcial = 0;
        informacao[i].vetor = vetor;
        pthread_create(&t[i], NULL, Media, (void*) &informacao[i]);
    }

    for(i=0; i<Tam_Thread; i++){
        pthread_join(t[i], NULL);
    }

    for(i=0; i<Tam_Thread; i++){
        soma_total += informacao[i].soma_parcial;
    }

    soma_total = soma_total/N;

    tempo = omp_get_wtime() - tempo;
	printf("%.3lf ", tempo);
}

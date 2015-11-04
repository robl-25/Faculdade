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

double media;

void le_entrada(char** args, double* N, int* Tam_Thread){
	*N =  (double) strtol(args[1], (char**) NULL, 10);
	*Tam_Thread =  (double) strtol(args[2], (char**) NULL, 10);

	*N = pow(10, *N);
}

void* Media(void* v){
    int i;
    inf* informacao = (inf*) v;

    for(i = informacao->inicio; i < informacao->fim; i++){
        informacao->soma_parcial += informacao->vetor[i];
    }
}

void* Desvio(void* v){
    int i;
    inf* informacao = (inf*) v;

    for(i = informacao->inicio; i < informacao->fim; i++){
        informacao->soma_parcial += pow((informacao->vetor[i] - media),2);
    }
}

void main(int x, char** args){
    int Tam_Thread;
    double N;

    le_entrada(args, &N, &Tam_Thread);

    inf informacao[Tam_Thread];
    double* vetor;
    int i;
    double desvio = 0;
    double soma_parcial = 0, tempo, expoente;
    pthread_t t[Tam_Thread];

    srand(time(NULL));

    vetor = (double*) malloc(sizeof(double)*N);
    informacao[i].vetor = vetor;

    tempo = omp_get_wtime();
    for(i=0; i<N; i++){
        informacao->vetor[i] = i;
    }
    tempo = omp_get_wtime() - tempo;
    expoente = log10(N);
	fprintf(stderr, "\nTempo de preenchimendo do vetor de %lf: %.3lfs \n", expoente, tempo);

    tempo = omp_get_wtime();

    for(i=0; i<Tam_Thread; i++){
        informacao[i].inicio = i*N/Tam_Thread;
        informacao[i].fim = informacao[i].inicio + (N/Tam_Thread);
        informacao[i].soma_parcial = 0;
        informacao[i].vetor = vetor;
        pthread_create(&t[i], NULL, Media, (void*) &informacao[i]);
    }

    media = 0;

    for(i=0; i<Tam_Thread; i++){
        pthread_join(t[i], NULL);
        media += informacao[i].soma_parcial;
    }

    media = media/N;

    for(i=0; i<Tam_Thread; i++){
        informacao[i].inicio = i*N/Tam_Thread;
        informacao[i].fim = informacao[i].inicio + (N/Tam_Thread);
        informacao[i].soma_parcial = 0;
        informacao[i].vetor = vetor;
        pthread_create(&t[i], NULL, Desvio, (void*) &informacao[i]);
    }

    for(i=0; i<Tam_Thread; i++){
        pthread_join(t[i], NULL);
        soma_parcial += informacao[i].soma_parcial;
    }

    desvio = sqrt(soma_parcial/(N-1));

    tempo = omp_get_wtime() - tempo;
	printf("%.3lf ", tempo);
}

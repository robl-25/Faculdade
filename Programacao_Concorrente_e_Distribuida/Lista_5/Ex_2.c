#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>
#include <time.h>
#include <string.h>
//#define N 100000000 //10**8

void le_entrada(char** args, long int* N, int* threads){
	*N =  (long int) strtol(args[1], (char**) NULL, 10);
	*threads =  (int) strtol(args[2], (char**) NULL, 10);

	*N = (long int) pow(10, *N);
}

void main(int x, char** args){
    double* vetor;
    int i, threads;
	unsigned long int N;
    double desvio, tempo;
    double media = 0;
    double soma_parcial=0;


	le_entrada(args, &N, &threads);

    srand(time(NULL));

    vetor = (double*) malloc(sizeof(double)*N);

	tempo = omp_get_wtime();

	omp_set_num_threads(threads);
	#pragma parallel
	{
        #pragma omp shared(vetor,media) for
        for(i=0; i<N; i++){
            vetor[i] = i;
            media += vetor[i];
        }

	    #pragma omp single
        media = media/N;
	    #pragma omp barrier

        #pragma omp shared(vetor, soma_parcial) for
        for(i=0; i<N; i++){
            soma_parcial += pow((vetor[i] - media),2);
        }
	}

	desvio = sqrt(soma_parcial/(N-1));

	tempo = omp_get_wtime() - tempo;
	printf("%.3lf ", tempo);

    //printf("\nDesvio = %.2lf\n", desvio);
}

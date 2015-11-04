#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>
#include <string.h>
#define u 2

void le_entrada(char** args, double* N, int* threads){
	*N =  (double) strtol(args[1], (char**) NULL, 10);
	*threads =  (double) strtol(args[2], (char**) NULL, 10);

	*N = pow(10, *N);
}

void main(int a, char** args){
    int i, threads;
    double tempo, N;
    double soma=0, x, passo, ln;

	le_entrada(args, &N, &threads);

	tempo = omp_get_wtime();

	passo = (u-1) / (double) N;

	omp_set_num_threads(threads);

	#pragma omp parallel for private(x,i) shared(passo) reduction(+:soma)
    for(i=0; i<N; i++){
			x = 1 + i*passo;
			soma += 0.5*(1/x+1/(x+passo));
    }

	ln = soma*passo;
	tempo = omp_get_wtime() - tempo;
	printf("%.3lf ", tempo);
}

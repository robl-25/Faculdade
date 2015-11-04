#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>
#include <time.h>
#include <string.h>

void le_entrada(char** args, long int* N, int* threads){
	*N =  (long int) strtol(args[1], (char**) NULL, 10);
	*threads =  (int) strtol(args[2], (char**) NULL, 10);

	//*N = (long int) pow(10, *N);
}


void main(int a, char** args){
  int i, threads, j;
  double tempo;
	long int N;
	double** matriz;
	double* vetor;
	double* res;

	srand(time(NULL));

	le_entrada(args, &N, &threads);

	matriz = (double**) malloc(sizeof(double*)*N);
	vetor = (double*) malloc(sizeof(double)*N);
	res = (double*) malloc(sizeof(double)*N);

	for(i=0; i<N; i++){
		matriz[i] = (double*) malloc(sizeof(double)*N);
	}

	tempo = omp_get_wtime();

	omp_set_num_threads(threads);
	#pragma omp parallel shared(vetor,matriz,res) private(j,i)
	{
		#pragma omp for
		for(i=0; i<N; i++){
			vetor[i] = i+1;
			res[i] = 0;

			for(j=0; j<N; j++){
					matriz[i][j] = i+1;
			}
		}

		#pragma omp for
		for(i=0; i<N; i++){
			for(j=0; j<N; j++){
				res[i] += matriz[i][j]*vetor[j];
			}
		}
	}

	tempo = omp_get_wtime() - tempo;
	printf("%.3lf ", tempo);

	/* Liberando a memoria, concorrentemente */
    omp_set_num_threads(threads);
    #pragma omp parallel private(i, j) shared(matriz)
    {
        #pragma omp for
        for(i=0; i<N; i++){
            free(matriz[i]);
        }
    }

    free(vetor);
    free(res);

}

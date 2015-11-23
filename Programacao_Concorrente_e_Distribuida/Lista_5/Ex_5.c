#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <omp.h>
#include <pthread.h>

int cont = 1;
pthread_cond_t gate;
pthread_cond_t S;
pthread_mutex_t cont_mutex;
int a = 0;

void le_entrada(char** args, long int* N, int* threads){
	*N =  (long int) strtol(args[1], (char**) NULL, 10);
	*threads =  (int) strtol(args[2], (char**) NULL, 10);

	//*N = (long int) pow(10, *N);
}

void *Semaphoro(void *v){
    int id = (int) v;
    
    pthread_mutex_lock(&cont_mutex);
    pthread_cond_wait(&gate, &cont_mutex);
    pthread_cond_wait(&S, &cont_mutex);
    
    cont--;
    
    if(cont > 0){
        pthread_cond_signal(&gate);
    }
    pthread_cond_signal(&S);
    pthread_mutex_unlock(&cont_mutex);
    
    //Secao Critica
    a += (id + 1);
    
    pthread_mutex_lock(&cont_mutex);
    pthread_cond_wait(&S, &cont_mutex);
    
    cont++;
    
    if(cont == 1){
        pthread_cond_signal(&gate);
    }
    pthread_cond_signal(&S);
    pthread_mutex_unlock(&cont_mutex);
}

void main(int x, char** args){
    long int N;
    int threads, i;
    double tempo;
    double* vetor;
    
    le_entrada(args, &N, &threads);
    
    pthread_t t[threads];
    pthread_cond_init(&gate, NULL);
    pthread_cond_init(&S, NULL);
    pthread_mutex_init(&cont_mutex, NULL);
    
    srand(time(NULL));

    vetor = (double*) malloc(sizeof(double)*N);

	tempo = omp_get_wtime();

	omp_set_num_threads(threads);
	
	for(i=0; i<threads; i++){
	    pthread_create(&t[i], NULL, Semaphoro, (void *) i);
	}
	
	for(i=0; i<threads; i++){
	    pthread_join(t[i], NULL);
	}
	
	tempo = omp_get_wtime() - tempo;
	//printf("%.3lf ", tempo);
	
	printf("%d\n", a);
	
	pthread_cond_destroy(&gate);
	pthread_cond_destroy(&S);
    pthread_exit (NULL);
}

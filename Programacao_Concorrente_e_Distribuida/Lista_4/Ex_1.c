#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t sb1, sb2, sb3;

void* Thread1(void* v){
    pthread_mutex_lock(&sb1);
    printf("C");
	pthread_mutex_unlock(&sb2);
	pthread_mutex_lock(&sb3);
	printf("E");
	pthread_mutex_unlock(&sb3);
	pthread_mutex_unlock(&sb1);
}

void* Thread2(void* v){
    printf("A");
	pthread_mutex_unlock(&sb1);
    pthread_mutex_lock(&sb2);
    printf("R");
	pthread_mutex_unlock(&sb3);
	pthread_mutex_unlock(&sb2);
	pthread_mutex_lock(&sb1);
    printf("O");
	pthread_mutex_unlock(&sb1);
}

void main(int x, char** args){
    int i;
    pthread_t t1, t2;

	pthread_mutex_lock(&sb1);
	pthread_mutex_lock(&sb2);
	pthread_mutex_lock(&sb3);

	pthread_create(&t1, NULL, Thread1, NULL);
    pthread_create(&t2, NULL, Thread2, NULL);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	printf("\n");
}

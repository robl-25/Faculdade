#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

int request = 0;
int respond = 0;
int cont_T, VarComp=0;

void le_entrada(char** args, int* Tam_Thread){
	*Tam_Thread =  (int) strtol(args[1], (char**) NULL, 10);
}

void* Client(void* i){
    int* id = (int*) i;

	//Pre-Protocolo
    while(respond != (*id)){
        request = (*id);
    }

	//Secao Critica
    VarComp += (*id);
    cont_T--;

	//Pos-Protocolo
    respond = 0;
}

void* Server(void* v){
    while(cont_T>0){
        while(request==0);
        respond = request;
        while(respond!=0);
        request = 0;
    }
}

void main(int x, char** args){
    int Tam_Thread;
    int i;

    le_entrada(args, &Tam_Thread);

    cont_T = Tam_Thread;
    pthread_t t[Tam_Thread+1];
    int vetor[Tam_Thread];

    pthread_create(&t[0], NULL, Server, NULL);

    for(i=1; i<=Tam_Thread; i++){
        vetor[i] = i;
        pthread_create(&t[i], NULL, Client, (void*) &vetor[i]);
    }

    pthread_join(t[0], NULL);

    printf("%d\n", VarComp);
}

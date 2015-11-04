#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <stdbool.h>

void le_entrada(char** args, int* Tam_Thread){
	*Tam_Thread =  (int) strtol(args[1], (char**) NULL, 10);
}

void main(int x, char** args){
    int Tam_Thread = 2;
    int turn = 1, VarComp = 0, i;
    bool wantp = false, wantq = false;

    le_entrada(args, &Tam_Thread);

	omp_set_num_threads(Tam_Thread);
	#pragma omp private(VarComp)
    #pragma omp sections
    {
        #pragma omp section
        {
            for(i=0; i<100; i++){
                //Pre-Protocolo
                wantp = true;
                while(wantq){
                    if(turn == 2){
                        wantp = false;
                        while(turn == 1){}
                        wantp = true;
                    }
                }
                VarComp++;
                //Pos-Protocolo
                #pragma omp atomic
                turn++;
                wantp = false;
            }
        }
        #pragma omp section
        {
            for(i=0; i<100; i++){
                //Pre-Protocolo
                wantq = true;
                while(wantp){
                    if(turn == 1){
                        wantq = false;
                        while(turn == 2){}
                        wantq = true;
                    }
                }
                VarComp += 10;
                //Pos-Protocolo
                #pragma omp atomic
                turn--;
                wantq = false;
            }
        }
    }
    printf("%d\n", VarComp);

}

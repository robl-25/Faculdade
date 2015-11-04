#include <stdio.h>
#include <stdlib.h>

int* linha;
int* lin;
int N, M;

int IsSafe(int i){
    int j;
    for(j=1; j<=N; j++){
        if(linha[j] == i){
            return 0;
        }
    }
    return 1;
}
 
void Vig(int i){
    int j;
  
    if(i<=N){
        //Se esta vazio a posicao i
        if(linha[i] == 0){
            //qual j-esimo vigilante colocar na posicao i
            for(j=1;j<=N;j++){
                //verifica se o j-esimo vigilante ja nao foi colocado
                if(IsSafe(j)){
                    linha[i]=j;
                    Vig(i+1);
                    linha[i]=0;
                }
            }
        }
        else{
            Vig(i+1);
        }
    }
     else{
        printf("%d",linha[1]);
        for(j=2;j<=N;j++){
            printf(" %d",linha[j]);
        }
        printf("\n");
     }
}
 
int main(){
    scanf("%d", &N);
    scanf("%d", &M);

    linha = (int*) malloc(sizeof(int)*(N+1));
    lin = (int*) malloc(sizeof(int)*(M));
    
    int i, col;

    for(i=0; i<=N; i++){
        linha[i] = 0;
    }

    for(i=0; i<M; i++){
        scanf("%d", &lin[i]);
        scanf("%d", &col);
        
        linha[col] = lin[i];
    }

    Vig(1);
    return 0;
}

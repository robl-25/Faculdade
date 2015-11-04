#include <stdlib.h>
#include <stdio.h>

void troco(int n, int D[], int tam){
    int j, max=0, i;
    if(n>0){
        for(j=tam; j>(-1); j--){
            if(D[j]<=n && max<D[j]){
                max = D[j];
                i = j;
            }
        }
        if(max > 0){
            printf("%d ", max);
            troco(n-max,D,tam);
        }
    }
}

void main(){
    int n, i;
    int tam;

    scanf("%d", &tam);

    int D[tam];

    for(i=0; i<tam; i++){
        scanf("%d", &D[i]);
    }
    scanf("%d", &n);

    troco(n,D,tam-1);
}

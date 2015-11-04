#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void main(){
    int n, i;
    bool heap = true;

    scanf("%d",&n);

    int vetor[n];

    for(i=0; i<n; i++){
        scanf("%d",&vetor[i]);
    }

    if(vetor[1] > vetor[0] || vetor[2] > vetor[0]){
        heap = false;
    }

    for(i=1; (i<(n/2) && heap!=false); i++){
        if(vetor[2*i]>vetor[i] || vetor[2*i+1]>vetor[i]){
            heap = false;
        }
    }

    if(heap){
        printf("True\n");
    }
    else{
        printf("False\n");
    }
}

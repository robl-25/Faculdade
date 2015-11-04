#include <stdlib.h>
#include <stdio.h>

int Particao(int v[], int p, int r){
    int i, j=p-1;
    int aux, x;

    x = v[r];

    for(i=p; i<=(r-1); i++){
        if(v[i]<=x){
            j++;
            aux = v[j];
            v[j] = v[i];
            v[i] = aux;
        }
    }

    aux = v[j+1];
    v[j+1] = v[r];
    v[r] = aux;

    return j+1;
}

void Mediana(int v[], int p, int r, int k){
    int q;
    q = Particao(v,p,r);

    if(q > k){
        Mediana(v,p,q-1,k);
    }
    else if(q < k){
        Mediana(v,q+1,r,k);
    }
}

void main(){
    int n, i;
    float m;

    scanf("%d", &n);

    int v[n];

    for(i=0; i<n; i++){
        scanf("%d", &v[i]);
    }

    Mediana(v,0,n-1,n/2);

    if(n%2 == 0){
        Mediana(v,n/2,n-1,n/2+1);
        m = (v[n/2]+ v[n/2-1])/2.;
    }
    else{
        m = v[n/2];
    }

    for(i=0; i<n; i++){
        printf("%d ", v[i]);
    }

    printf("%f\n", m);
}

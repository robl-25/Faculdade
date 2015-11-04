#include "stdio.h"

int main(){
	int T, N, p, i, cont;
	char a[11];

	while(scanf("%d %d", &T, &N)>0){
		cont=0;
		for (i=0;i<T;i++){
			scanf("%s %d", &a, &p);
			cont += p;
		}
		printf("%d\n", N*3-cont);
	}

	return 0;
}

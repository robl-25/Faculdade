#include <iostream>
#include <map>
#include <list>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

void remove_elemento(map<int, int >& grafo, vector<int>& amigos, int k, int indice){
	int pos;
    
	amigos[indice] = -1;
	
	pos = grafo[indice];
    
    /* Decrementa a quantidade de amigos de `it` */
    amigos[pos]--;

    /* Se pos ficou com menos que `k` amigos
     * removemos ele tambem */
    if(amigos[pos] == 0){
	    remove_elemento(grafo, amigos, k, pos);
    }
}

inline void fastRead_int(int &x){
	register int c = getchar();
	x = 0;
	int neg = 0;

	for(; ((c < 48 || c > 57) && c != '-'); c = getchar());

	if(c == '-')
	{
		neg = 1;
		c = getchar();
	}

	for(; c > 47 && c < 58 ; c = getchar())
	{
		x = (x << 1) + (x << 3) + c - 48;
	}

	if(neg)
		x = -x;
}

int main(){

	bool alguem_foi_impresso = false;

	int n, a, b;
	int i, j;
	int k = 1;

	cin >> n;

	vector<int> amigos(n, 0);
	map<int, int> grafo;

	for(i=0; i<n; i++){
		fastRead_int(a);
		fastRead_int(b);

		grafo[a - 1] = b - 1;

		amigos[b - 1]++;
	}

	/* Remove os elementos com mais de 0 e menos de k amigos */
	for(i=0; i<n; i++){
		if(amigos[i] == 0){
			remove_elemento(grafo, amigos, k, i);
		}
	}

	/* Busca o indice do ultimo elemento que sera impresso */
	for(i=1, j=0; i<n; i++){
		if(amigos[i] > 0){
			j = i;
		}
	}

	/* Imprime todos que tem mais de 0 amigos */
	for(i=0; i<j; i++){
		if(amigos[i] > 0){
			cout << i+1 << " ";
			alguem_foi_impresso = true;
		}
	}

	/* Imprime o ultimo elemento, se pudermos */
	if(amigos[i] > 0){
		cout << i+1 << endl;
		alguem_foi_impresso = true;
	}

	return 0;
}

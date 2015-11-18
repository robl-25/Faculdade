#include <iostream>
#include <map>
#include <list>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

void remove_elemento(vector< vector<int> >& grafo, vector<int>& amigos, int k, int indice){
	int pos;
	int i;
    
	amigos[indice] = 0;
	
	for(i=0; i<grafo[indice].size(); i++){
	    
	    if(grafo[indice][i] != 0){
	    
	        grafo[indice][i] = 0;
	        grafo[i][indice] = 0;
	        
            /* Decrementa a quantidade de amigos de `it` */
            amigos[i]--;

            /* Se pos ficou com menos que `k` amigos
             * removemos ele tambem */
            if(amigos[i] > 0 && amigos[i] < k){
                remove_elemento(grafo, amigos, k, i);
            }
        }
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
	int k, m;

	vector<int> amigos;
	vector<vector<int> > grafo;
	
	while(cin >> n){
        
        cin >> m;
        cin >> k;
        
        amigos.resize(n);
        fill(amigos.begin(), amigos.end(), 0);
        grafo.resize(n);
        
        for(i=0; i<n; i++){
            grafo[i].resize(n);
            fill(grafo[i].begin(), grafo[i].end(), 0);
        }
        
        alguem_foi_impresso = false;
        
	    for(i=0; i<m; i++){
		    fastRead_int(a);
		    fastRead_int(b);

		    grafo[a - 1][b - 1] = 1;
		    grafo[b - 1][a - 1] = 1;

		    amigos[b - 1]++;
		    amigos[a - 1]++;
	    }
	    
	    
        if(k == 0){
            for(i = 0; i < n-1; i++){
                cout << i+1 << " ";
                alguem_foi_impresso = true;
            }
            cout << i+1 << endl;
        }
        
        else{

	        /* Remove os elementos com mais de 0 e menos de k amigos */
	        for(i=0; i<n; i++){
		        if(amigos[i] > 0 && amigos[i] < k){
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
	    }
	    
	    if(!alguem_foi_impresso){
	            cout << 0 << endl;
	        }
	}

	return 0;
}

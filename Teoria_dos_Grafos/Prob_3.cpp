#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cstdio>
#include <climits>
#include <numeric>

using namespace std;

inline void fastRead_int(int &x){
    register int c = getchar();
    x = 0;
    int neg = 0;

    for(; ((c < 48 || c > 57) && c != '-'); c = getchar());

    if(c == '-'){
        neg = 1;
        c = getchar();
    }

    for(; c > 47 && c < 58 ; c = getchar()){
        x = (x << 1) + (x << 3) + c - 48;
    }

    if(neg)
        x = -x;
}

inline void ajuste_pesos(vector< list< pair<int, int> > >& arestas,
                         vector<bool>& S, vector<int>& pes, int v){

  list< pair<int, int> >::iterator it;
  int i = 0, j = 0;
  pair<int, int> u;

  for(it = arestas[v].begin(); it != arestas[v].end(); it++){
    u = *it;
    i = u.first;
    j = u.second;

    if(S[i] == false && pes[i] > j){
        pes[i] = j;
    }

  }
}

inline int min_pos(vector<int>& pes, vector<bool>& S){
    int i , n = pes.size();
    int min = INT_MAX;
    int pos = -1;
    
    for(i=0; i<n; i++){
        if(S[i] == false && min > pes[i]){
            min = pes[i];
            pos = i;
        }
    }
    
    return pos;
}

inline void procura_min(vector< list< pair<int, int> > >& arestas,
                        int n, vector<int>& pes,
                        vector<bool>& S){

  int v = 0, fim=0;

  while(fim < n-1){
      v = min_pos(pes, S);
      fim++;

      /* Para cada vertice que for processado marque visitado */
      S[v] = true;

      ajuste_pesos(arestas, S, pes, v);

  }
}

/* Funcao para ver qual a arvore geradora minima */
inline int procura_camin_min(int n, vector< list< pair<int, int> > >& arestas){

    int res=0, fim=0;
    int i = 0, v = 0;
    vector<int> pes(n, INT_MAX);
    vector<bool> S(n, false);


    pes[0] = 0;

    procura_min(arestas, n, pes, S);
    
    for(i=0; i<pes.size(); i++){
        res += pes[i];
    }

    return res;
}

int main(){
    int n = 0, m = 0, a = 0, b = 0, c = 0, i = 0, somaP = 0;
    vector< list< pair<int, int> > > arestas;
    int somaT=0;
    pair<int, int> aux;
    pair<int, int> aux3;

    cin >> n;
    cin >> m;

    for(i=0; i<n; i++){
        list< pair<int, int> > aux2;

        arestas.push_back(aux2);
    }

    for(i=0; i<m; i++){

        fastRead_int(a);
        fastRead_int(b);
        fastRead_int(c);
        
        aux = make_pair(b, c);
        aux3 = make_pair(a, c);

        arestas[a].push_back(aux);
        arestas[b].push_back(aux3);

        somaT += c;
    }

    somaP = procura_camin_min(n, arestas);

    cout << somaT - somaP;

    return 0;
}

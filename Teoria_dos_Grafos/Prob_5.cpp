#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <cstdio>
#include <climits>
#include <utility>

#define MY_MAX 100000

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

inline int ret_v(vector<bool>& S){
    int i, n = S.size(), pos = -1;

    for(i=0; i<n; i++){
        if(S[i] == true){
            pos = i;
            i = n;
        }
    }

    return pos;
}

inline int Dijkstra(vector< list< pair<int, int> > >& grafol, int n){

    int v, s=0, vertice, peso;
    vector<bool> S(n, false);
    list<pair<int, int> >::iterator it;
    pair<int, int> aux;
    vector<int> pes(n, MY_MAX);

    pes[s] = 0;
    S[s] = true;
    v = s;

    while(v != -1){

        S[v] = false;

        for(it = grafol[v].begin(); it != grafol[v].end(); it++){
            aux = *it;
            vertice = aux.first;
            peso = aux.second;

            if(pes[vertice] > (pes[v] + peso)){
                S[vertice] = true;
                pes[vertice] = pes[v] + peso;
            }

        }

        v = ret_v(S);

    }


    return pes[n-1];
}

inline void reducao(vector< list< pair<int, int> > >& grafo, int n,
                    vector< list< pair<int, int> > >& grafol){
    int a, b, c, b2, c2;
    list<pair<int, int> >::iterator it;
    list<pair<int, int> >::iterator it2;
    pair<int, int> aux;
    pair<int, int> aux2;

    for(a=0; a<n; a++){
        for(it = grafo[a].begin(); it!= grafo[a].end(); it++){
            aux = *it;
            b  = aux.first;
            c = aux.second;

            for(it2=grafo[b].begin(); it2 != grafo[b].end(); it2++){
                aux = *it2;
                b2 = aux.first;
                c2 = aux.second;

                if(b2 != a){
                    grafol[a].push_back(make_pair(b2, c2 + c));
                }
            }

        }
    }
}

int main(){
    vector< list< pair<int, int> > > grafol;
    vector< list< pair<int, int> > > grafo;
    int n, m, i, a, b, c, soma;
    list<pair<int, int> > aux;

    fastRead_int(n);
    fastRead_int(m);

    for(i=0; i<n; i++){
        grafol.push_back(aux);
        grafo.push_back(aux);
    }

    /*for(i=n; i<n*2; i++){
        grafol.push_back(aux);
    }*/

    for(i=0; i<m; i++){
        fastRead_int(a);
        fastRead_int(b);
        fastRead_int(c);

        a--;
        b--;

        grafo[a].push_back(make_pair(b, c));
        grafo[b].push_back(make_pair(a, c));

        /*grafol[(a*2)+1].push_back(make_pair((b*2), c));
        grafol[a*2].push_back(make_pair((b*2)+1, c));

        grafol[(b*2)+1].push_back(make_pair((a*2), c));
        grafol[b*2].push_back(make_pair((a*2)+1, c));*/
    }

    reducao(grafo, n, grafol);

    soma = Dijkstra(grafol, n);

    if(soma == MY_MAX){
        soma = -1;
    }

    cout << soma << endl;

    return 0;
}

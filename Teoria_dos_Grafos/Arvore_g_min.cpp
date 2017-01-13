#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

#define MAX_INT 1000000

using namespace std;

void insert(list<int>& Q, int ver, int valor, vector<int>& d){
    Q.push_back(ver);
    d.push_back(valor);
}

int extractMin(vector<vector<int> > grafo, int n, list<int>& S, int s){

    int i, min = MAX_INT, v = 0;
    list<int>::iterator it;

    for(it = S.begin(); it != S.end(); it++){
        i = *it;

        if(s != i && grafo[s][i] < min && grafo[s][i] != -1){
            min = grafo[s][i];
            v = i;
        }
    }

    return v;

}

list<int> arv_ger_min(vector<vector<int> >& grafo, int n,
                      vector<int>& d){

    int i, s=0, v, u, valor;
    list<int> Q;
    list<int> S;
    list<int>::iterator it;
    vector<bool> mark(n, false);

    Q.push_back(s);
    d[s] = 0;

    for(i=1; i<n; i++){
        S.push_back(i);
    }

    while(S.size() > 0){

        v = extractMin(grafo, n, S, s);

        Q.push_back(v);

        if(v == 0){
            v = S.front();
        }

        else{
            d[v] = grafo[s][v];
        }

        S.remove(v);

        for(u=0; u<n; u++){
            if(grafo[v][u] != -1){
                valor = min(d[u], d[v] + grafo[v][u]);
                if(valor != d[u] && u < v){
                    S.push_front(u);
                }
                d[u] = valor;
            }
        }
    }

    return Q;

}

int main(){
    vector<vector<int> > grafo;
    list<int>::iterator it;
    vector<int> d;
    list<int> Q;
    int n, i, a, b, peso, j;

    cin >> n;

    for(i=0; i<n; i++){
        vector<int> aux(n,-1);

        grafo.push_back(aux);

        d.push_back(MAX_INT);
    }

    while(cin >> a && cin >> b && cin >> peso){
        grafo[a][b] = peso;
    }

    Q = arv_ger_min(grafo, n, d);

    for(i=0; i<n; i++){
        cout << d[i] << endl;
    }

    return 0;
}

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
 
inline int procura_camin_min(int n, vector< list< pair<int, int> > >& grafo){
    int ini = 0, fim = n-1, i, v;
    vector<int> d(n, INT_MAX);
    list<int> Q;
    list<int> S;
    
    for(i=0; i<n; i++){
        S.push_back();
    }
    
    while(S.size() > 0){
        
    }
    
}
 
int main(){
    int n = 0, m = 0, a = 0, b = 0, c = 0, i = 0, somaP = 0;
    vector< list< pair<int, int> > > grafo;
    int somaT=0;
    pair<int, int> aux;
    pair<int, int> aux3;
 
    cin >> n;
    cin >> m;
 
    for(i=0; i<n; i++){
        list< pair<int, int> > aux2;

        grafo.push_back(aux2);
    }
 
    for(i=0; i<m; i++){
 
        fastRead_int(a);
        fastRead_int(b);
        fastRead_int(c);
        
        aux = make_pair(b-1, c);
        aux3 = make_pair(a-1, c);
 
        grafo[a-1].push_back(aux);
        grafo[b-1].push_back(aux3);
    }
 
    somaP = procura_camin_min(n, grafo);
 
    cout << somaP << endl;
 
    return 0;
}

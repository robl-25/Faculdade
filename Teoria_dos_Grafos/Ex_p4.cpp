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

inline bool residuo(vector<vector<int> >& grafoR, int s, int t, 
                    vector<int>& parent, int n){

    vector<bool> visitado(n, false);
    list<int> q;
    int u, v;

    q.push_back(s);
    visitado[s] = true;
    parent[s] = -1;
 
    while(!q.empty()){

        u = q.front();
        q.pop_front();
 
        for(v=0; v<n; v++){

            if(visitado[v] == false && grafoR[u][v] > 0){

                q.push_back(v);
                parent[v] = u;
                visitado[v] = true;

            }
        }
    }
 
    return (visitado[t] == true);
}
 

inline int Ford_Fulkerson(vector<vector<int> >& grafo, int n){

    int u, v, s=0, t=n-1;
    vector< vector<int> > grafoR;
    vector<int> parent(n, -1);
 
    int sum_max = 0;
    int cam_fluxo = INT_MAX;

    for (u = 0; u < n; u++){

        vector<int> aux(n, 0);
        grafoR.push_back(aux);

        for (v = 0; v < n; v++){
            grafoR[u][v] = grafo[u][v];
        }
             
    }
 
    
    while(residuo(grafoR, s, t, parent, n)){
        
        cam_fluxo = INT_MAX;

        for (v=t; v!=s; v=parent[v]){

            u = parent[v];
            cam_fluxo = min(cam_fluxo, grafoR[u][v]);
        }
 
        for (v=t; v != s; v=parent[v]){

            u = parent[v];
            grafoR[u][v] -= cam_fluxo;
            grafoR[v][u] += cam_fluxo;

        }
 
        sum_max += cam_fluxo;
    }
 
    return sum_max;
}
 

int main(){

    vector< vector< int > > grafo;
    int a, b, c, n, m, i;

    fastRead_int(n);
    fastRead_int(m);

    for(i=0; i<n; i++){

        vector<int> aux(n, 0);
    
        grafo.push_back(aux);

    }

    for(i=0; i<m; i++){

        fastRead_int(a);
        fastRead_int(b);
        fastRead_int(c);

        grafo[a][b] = c;
    }
    
    cout << Ford_Fulkerson(grafo, n) << endl;
 
    return 0;
}

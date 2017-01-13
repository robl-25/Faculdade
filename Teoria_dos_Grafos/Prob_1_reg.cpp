#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <cstdio>

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

void PontosCorte(int i, int d, vector<bool>& mark, vector<int>& depth,
                vector<int>& low, vector<int>& res, vector< list<int> >& grafo,
                vector<int>& parent, int n){
    int childCount = 0;
    int j;
    bool isArticulation = false;
    list<int>::iterator p;
    mark[i] = true;
    depth[i] = d;
    low[i] = d;

    for(p = grafo[i].begin(); p != grafo[i].end(); p++){
		j = *p;
        if(mark[j] == false){
            parent[j] = i;
            PontosCorte(j, d+1, mark, depth, low, res, grafo, parent, n);
            childCount++;
            if(low[j] >= depth[i]){
                isArticulation = true;
            }
            low[i] = min(low[i], low[j]);
        }
        else if(j != parent[i]){
            low[i] = min(low[i], depth[j]);
        }
    }
    if((parent[i] != -1 && isArticulation) || (parent[i] == -1 && childCount > 1)){
        res.push_back(i);
    }
}

int main(){
    vector< list<int> > grafo;
    int n, i, m, a, b, t = 0;
    vector<int> res;
    vector<bool> mark;
    vector<int> depth, low, parent;
    list<int>::iterator it;

    fastRead_int(n);
    fastRead_int(m);

    depth.clear();
    low.clear();
    low.clear();
    mark.clear();
    grafo.clear();

    for(i=0; i<n; i++){
        list<int> aux;
        grafo.push_back(aux);
        depth.push_back(0);
        low.push_back(0);
        parent.push_back(-1);
        mark.push_back(false);
    }
    res.clear();

    for(i=0; i<m; i++){
        fastRead_int(a);
        fastRead_int(b);
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }

    PontosCorte(0, 0, mark, depth, low, res, grafo, parent, n);

    sort(res.begin(), res.end());

    for(i=0; i<res.size(); i++){
        cout << res[i] << endl;
    }



    return 0;
}

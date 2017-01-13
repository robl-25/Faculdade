#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

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

    for(j=0; j<n; j++){
        p = find(grafo[i].begin(), grafo[i].end(), j);
        if(p != grafo[i].end()){
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
    }
    if((parent[i] != -1 && isArticulation) || (parent[i] == -1 && childCount > 1)){
        res.push_back(i);
    }
}

int main(){
    vector< list<int> > grafo;
    int n, i, m, a, b;
    vector<int> res;
    vector<bool> mark;
    vector<int> depth, low, parent;
    list<int>::iterator it;

    while(cin >> n && cin >> m){
        if(n != 0 && m!= 0){
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
                cin >> a;
                cin >> b;
                grafo[a-1].push_back(b-1);
                grafo[b-1].push_back(a-1);
            }

            PontosCorte(0, 0, mark, depth, low, res, grafo, parent, n);

            sort(res.begin(), res.end());

            for(i=0; i<res.size(); i++){
                cout << res[i] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}

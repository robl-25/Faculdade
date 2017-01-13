#include <iostream>
#include <vector>
#include <list>
#include <map>

using namespace std;

void Busca_Largura(vector< vector<int> > grafo){
    list<int> busca;
    int tam = grafo[0].size();
    int i;
    list<int>::iterator it;
    map<int, char> mark;

    for(i=0; i<tam; i++){
        mark[i] = 'N';
    }

    busca.push_back(0);
    mark[0] = 'S';

    while(busca.size() > 0){
        for(i=0; i<tam; i++){
            if(grafo[busca.front()][i] == 1 && mark[i] == 'N'){
                busca.push_back(i);
                mark[i] = 'S';
            }
        }

        for(it = busca.begin(); it != busca.end(); it++){
            cout << *it+1 << " ";
        }
        cout << "\n";

        busca.pop_front();
    }
}

void Busca_Profundidade(vector< vector<int> >grafo){
    list<int> busca;
    int tam = grafo[0].size();
    int i;
    list<int>::iterator it;
    map<int, char> mark;
    bool remover;

    for(i=0; i<tam; i++){
        mark[i] = 'N';
    }

    busca.push_back(0);
    mark[0] = 'S';

    while(busca.size() > 0){

        remover = true;

        for(i=0; i<tam; i++){
            if(grafo[busca.back()][i] == 1 && mark[i] == 'N'){
                busca.push_back(i);
                mark[i] = 'S';
                remover = false;
                i=tam;
            }
        }

        if(remover){
            busca.pop_back();
        }

        for(it = busca.begin(); it != busca.end(); it++){
            cout << *it+1 << " ";
        }
        cout << "\n";
    }
}

int main(){
    vector< vector<int> > grafo;
    int n, i, a, b, j;

    cin >> n;

    for(i=0; i<n; i++){
        vector<int> aux(n, 0);
        grafo.push_back(aux);
    }

    while(cin >> a && cin >> b){
        grafo[a-1][b-1] = 1;
        grafo[b-1][a-1] = 1;
    }

    cout << "\nBusca em Largura\n";
    Busca_Largura(grafo);

    cout << "\nBusca em Profundidade\n";
    Busca_Profundidade(grafo);

    return 0;
}

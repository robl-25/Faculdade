#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <map>
#include <algorithm>
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
 
void Conexo(vector< list<int> >& grafo, int inicio, int fim, bool& EhConexo,
            vector<bool> visitado, vector<int>& caminho){
 
    if(inicio == fim){
        EhConexo = true;
        caminho.push_back(fim);
    }
 
    else if(EhConexo == false){
        list<int>::iterator it;
        vector<int>::iterator it2;
 
        visitado[inicio] = true;
        caminho.push_back(inicio);
 
        for(it=grafo[inicio].begin(); it != grafo[inicio].end() && EhConexo == false; it++){
            if(visitado[*it] == false){
                //visitado[*it] = true;

                //caminho.push_back(*it);
                
                Conexo(grafo, *it, fim, EhConexo, visitado, caminho);
                if(EhConexo == false){
                    caminho.pop_back();
                }
            }
        }
    }
}
 

 
int main(){
    int n, m, a, b, i, inicio, fim;
    vector< list<int> > grafo;
    vector<int> caminho;
    bool EhConexo = false, ret;
 
    cin >> n;
    cin >> m;

    vector<bool> visitado(n, false);

    for(i=0; i<n; i++){
        list<int> aux;
 
        grafo.push_back(aux);
    }
 
    for(i=0; i<m; i++){
 
        fastRead_int(a);
        fastRead_int(b);
 
        grafo[a].push_back(b);
        //grafo[b].push_back(a);
    }
    
    fastRead_int(inicio);
    fastRead_int(fim);
    
    //caminho.push_back(inicio);
 
    Conexo(grafo, inicio, fim, EhConexo, visitado, caminho);
    
    if(EhConexo){
        for(i=0; i<caminho.size(); i++){
            cout << caminho[i] << " ";
        }
    }
    
    else{
        cout << "NULL";
    }
    
    cout << endl;
 
    return 0;
}

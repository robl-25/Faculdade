#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <set>

using namespace std;

int n, m , k, cont = 0;
vector< int > conv;
vector< int> temp;
vector< list<int> > relacoes;

bool Is_Safe(int x){
    int i;
    
    if(relacoes[x].size() >= k){
        for(i=0; i<cont; i++){
            if(temp[i] == x){
                return false;
            }
        }
        return true;
    }
    return false;
}

bool Is_Safe_L(int x){
    int i, a=0, j;
    list<int>::iterator it;
    
    if(Is_Safe(x)){
        for(i=0; i<cont; i++){
            j = temp[i];
            it = find(relacoes[j].begin(),relacoes[j].end(), x);
            
            if(it != relacoes[j].end()){
                a++;
                //cout << "J = " << j << " e a = " << a << endl;
            }
        }
    }
    
    cout << "a final = " << a << " " << x << endl;
    
    if(a >= k){
        return true;
    }
    return false;
}

void Convidados(int x){
    int i, j;
    vector<int>::iterator it;

    for(i=x; i<=n; i++){
        if(cont<k){
            if(Is_Safe(i)){
                temp[cont] = i;
                cont++;
                Convidados(i+1);
                temp[cont] = 0;
                cont--;
            }
        }
        else if(Is_Safe_L(i)){
            temp[cont] = i;
            cont++;
        }
    }
    if(temp.size() > conv.size()){
        conv = temp;
    }
    for(j=k; j<cont; j++){
        temp[i] = 0;
    }
    
    cont=k;
}

int main(){
    int i, j, a;
    
    while(cin >> n){
        cin >> m;
        cin >> k;
        
        relacoes.resize(n+1);
        relacoes.clear();
        temp.resize(n);
        temp.clear();
        
        for(i=0; i<m; i++){
            cin >> j;
            cin >> a;
            
            relacoes[j].push_back(a);
            relacoes[a].push_back(j);
            
        }
        
        Convidados(1);
        
        sort(conv.begin(),conv.end());
        
        for(i=0; i<(conv.size()-1); i++){
            if(conv[i] != 0)
                cout << conv[i] << " ";
        }
        
        if(conv[i] != 0)
            cout << conv[i] << endl;
    }
    
    return 0;
}

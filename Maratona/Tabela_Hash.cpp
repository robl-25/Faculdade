#include <iostream>
#include <vector>
#include <map>
#include <list>

using namespace std;

int main(){
    int i, n, j, aux;
    int m, c, h;
    map<int, list<int> > hash;
    list<int>::iterator it;
    
    cin >> n;
    
    for(i=0; i<n; i++){
        cin >> m;
        cin >> c;
        
        hash.clear();
        
        for(j=0; j<c; j++){
            cin >> aux;
            h = aux%m;
            hash[h].push_back(aux);
        }
        
        for(j=0; j<m; j++){
            if(hash.find(j) == hash.end()){
                hash[j] = list<int>();
            }
        }
        
        for(j=0; j<m; j++){
            cout << j;
            for(it = hash[j].begin(); it != hash[j].end(); it++){
                cout << " -> " << *it;
                   
             }
             cout << " -> \\";
             cout << "\n";
        }
        if(i != (n-1)){
            cout << "\n";
        }
    }
    
    return 0;
}

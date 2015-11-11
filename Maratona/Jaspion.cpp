#include <iostream>
#include <map>
#include <string>
#include <sstream>

using namespace std;

int main(){
    int i, j;
    map<string, string> dic;
    string musica;
    string aux, tra, lixo, pa;
    int t, m, n;
    map<string, string>::iterator it;
    bool linha;
    
    cin >> t;
    
    for(i=0; i<t; i++){
        dic.clear();
        cin >> m;
        cin >> n;
        for(j=0; j<m; j++){
            cin >> pa;
            getline(cin, lixo);
            getline(cin, tra);
            
            dic[pa] = tra;
            //cout << "dic[" << aux << "] = " << dic[aux] << endl;
        }
        
        for(j=0; j<n; j++){
            getline(cin, musica);
            stringstream string_stream(musica);

			linha = false;
			while(string_stream >> aux){
				if(linha){
					cout << " ";
				}
				if(dic.find(aux) != dic.end()){
					cout << dic[aux];
				}
				else{
					cout << aux;
				}
				linha = true;
			}

            
            
            
            cout << "\n";
        }
        
        cout << "\n";
    }
    
    return 0;
}

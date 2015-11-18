#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

int main(){
    int a, b;
    vector<int> res;
    
    int i, j, cont, cont1, cont2;
    int aux1, aux2, aux3;
    
    res.resize(10);
    fill(res.begin(),res.end(),0);
    
    cin >> a;
    cin >> b;
    
    //if(i == j){
        do{
            i = log10(a);
            j = log10(b);
            aux1 = a;
            aux2 = b;
            
            fill(res.begin(),res.end(),0);
            if(a == 0){
                res[0]--;
            }
                
            for(cont1=i; cont1>0; cont1--){
                aux3 = (aux1/pow(10,cont1));
                res[aux3]++;
                aux1 -= aux3*(pow(10,cont1));
                if(aux1 == 0 && cont1 != 0){
                    res[0]+=cont1;
                    cont1=0;
                }
            }
            
            cont1 = 1;
            cont2 = 0;
            
            for(cont=a; cont<=b; cont++){
                if(aux1 == 10){
                    aux1 = 0;
                    cont1 *= 10;
                }
                
                res[aux1]+=cont1;
                aux1++;
            }
            
            for(cont=0; cont<10; cont++){
                cout << res[cont] << " ";
            }
            cout << endl;
            cin >> a;
            cin >> b;
            
        }while(a != 0 || b != 0);
    //}
    
    return 0;
}

#include <iostream>
#include <algorithm>

using namespace std;

int Pos_Vivo(int n,int k){
    int a=1;
    int i;
    
    for(i=1;i<=n;i++){
        a = (a+k-1)%i+1;
    }
    return a;
}

int main(){
    int nc, n, k;
    int i, j;
    
    cin >> nc;
    
    for(i=0; i<nc; i++){
        cin >> n;    
        cin >> k;
        
        j = Pos_Vivo(n, k);
        
        cout << "Case " << i+1 << ": " << j << endl;
    }
    
    return 0;
}

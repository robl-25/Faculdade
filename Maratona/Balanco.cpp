#include <iostream>
#include <string>

using namespace std;

int main(){
    string expre;
    int n, i, count=0;
    bool acabou = false;

    while(cin >> expre){
        n = expre.size();
        for(i=0; i<n; i++){
            if(expre[i] == '('){
                count++;
            }
            else if(expre[i] == ')'){
                count--;
            }
            if(count < 0){
                cout << "incorrect" << endl;
                i = n;
                acabou = true;
            }
        }
        if(count != 0 && acabou == false){
            cout << "incorrect" << endl;
        }
        else if(acabou == false){
            cout << "correct" << endl;
        }
        count = 0;
        acabou = false;
    }
    return 0;
}

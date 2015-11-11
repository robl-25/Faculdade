#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>

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

int main(){
    int nc, n, i, j, aux;
    vector<int> alturas;
    vector<int>::iterator it;
    
    fastRead_int(nc);
    
    for(i=0; i<nc; i++){
        fastRead_int(n);
        
        alturas.clear();
        for(j=0; j<n; j++){
            fastRead_int(aux);
            alturas.push_back(aux);
        }
        sort(alturas.begin(), alturas.end());
        
        for(it=alturas.begin(); it!=(alturas.end()-1); it++){
            printf("%d ", *it);
        }
        printf("%d", *it);
        printf("\n");
    }

    return 0;
}

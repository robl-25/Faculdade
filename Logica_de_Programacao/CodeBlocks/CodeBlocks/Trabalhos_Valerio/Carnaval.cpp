//Programa: Carnaval
//Autora: Mariane; RA: 86.902
//Versio: 5.1, date 20th Jun 2013

#include <iostream>
#include <iomanip>
using namespace std;

int main ()
{
    float n[5], nf, maior, menor;
    cout << "\nEscreva as notas da escola de samba com somente uma casa decimal: \n";
    cin >> n[1] >> n[2] >> n[3] >> n[4] >> n[5];

    maior= n[1];
    menor= n[1];

    for(int i=2; i<=5; i++)
    {
        if(n[i]>maior)
            maior=i;
        if(n[i]<menor)
            menor=i;
    }

    n[(int)maior]=0;
    n[(int)menor]=0;
    nf = n[1] + n[2] + n[3] + n[4] + n[5];

    cout << "\n" << setprecision (2) << nf << endl;
    //printf("\n%.1f",nf);
    //cout << "\n" << nf <<endl;

    return 0;
}

//Programa: Média Anual
//Autora: Mariane; RA: 86.902
//Versio: 1.0, date 13th Jun 2013

#include <iostream>

using namespace std;

int main()
{
    int n1, n2, n3, n4;//Notas Bimestrais
    float media;//Media Anual
    //Entrada
    cin >>n1 >>n2 >>n3 >>n4;
    //Processamneto
    media=(n1+n2+n3+n4)/4;
    //Saída
    cout << media << endl;
    return 0;
}

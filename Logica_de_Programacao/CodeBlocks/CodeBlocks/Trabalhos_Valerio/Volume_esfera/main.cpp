//Programa:Hello World
//Autora: Mariane; RA: 86.902
//Versio: 1.0, date 13th Jun 2013

#include <iostream>

using namespace std;

int main()// Bloco Pricipal do Programa
{//Entrada

    //Declaração de Constatntes
    const float pi=3.14;//pi = constante pi.

    //Declaração de Variáveis
    float r, v;//v = volume da esfera, r = raio.

    cin >> r;

    //Processamento
    v=(4*pi*(r*r*r))/3;

    //Saída
    cout << v << endl;

    return 0;

}//Fim

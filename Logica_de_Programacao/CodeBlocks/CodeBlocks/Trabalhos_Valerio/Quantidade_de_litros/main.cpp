//Programa:Hello World
//Autora: Mariane; RA: 86.902
//Versio: 1.0, date 13th Jun 2013

#include <iostream>

using namespace std;

int main()// Bloco Pricipal do Programa
{//Entrada
    //Declaração de Constantes
    const float pi=3.14;//pi= constante pi.
    //Declaração de Variáveis
    float h, r, q, c, ac, ab, al;//h=altura, r=raio, q=quantidade, c=custo, ac= area do cilindro, ab=area da base, al= area lateral.
    cout << "\nEscreva o raio do cilndro: ";
    cin >> r;
    cout << "\nEcreva a altura do cilndro: ";
    cin >> h;
    //Processamento
    ab=pi*r*r;
    al=2*pi*r*h;
    ac=2*ab+al;
    q=ac/3;
    c=(q)*10;
    //Saída
    cout << "\nA quantidade de litros foi de " << q << " litros" <<endl;
    cout << "\nO custo para pintar o tanque foi de " << c << " reais" << endl;
    return 0;

}//Fim

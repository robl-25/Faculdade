//Programa:Hello World
//Autora: Mariane; RA: 86.902
//Versio: 1.0, date 17th Jun 2013

#include <iostream>
#include <cmath>

using namespace std;

int main()// Bloco Pricipal do Programa
{//Entrada
    float x2, x1, delta, a , b, c;
    cout << "Escreva o valor de a: ";
    cin >> a;
    cout << "\nEscreva o valor b: ";
    cin >> b;
    cout << "\nEscreva o valor de c: ";
    cin >> c;
    delta = pow(b,2)-(4*a*c);
    if (delta < 0 )
    cout << "Nâo há raízes reais" <<endl;
    else
    {
        x1 = (-b - delta)/2*a;
        x2 = (-b + delta)/2*a;
        cout << "\nAs raízes reais são " << x1 << " e " << x2 <<endl;
    }

    return 0;
}//Fim

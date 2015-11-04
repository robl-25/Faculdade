#include <iostream>

using namespace std;

int main()
{
    int  i,k=4;
    double soma=0, fat=2, a, x, n;

    cout << "\nEscreva o valor de X: ";
    cin >> x;

    cout << "\nEscreva o valor de termos a ser calculado: ";
    cin >> n;
    soma = (x*x*x)/fat;
    a=x*x*x*(-1);
    for (i=2; i<=n; i++)
        {
            a=a*x*x*(-1);
            fat=fat*k*(k-1);
            k=k+2;
            soma=soma+(a/fat);
        }
    cout << "\nO valor do somatorio eh: " << soma <<endl;

    return 0;
}

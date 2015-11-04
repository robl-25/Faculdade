#include <iostream>
#include <string.h>

using namespace std;

int main ()
{
    float p1, p2, p3, m;
    char mr[3];
    cout << "\nEscreva as três primeiras letras da matéria a ser calculada a média: ";
    cin >> mr;
    if (strcmp(mr,"mat")==0)
    {
        cout << "\nEscreva a nota da primeira prova: ";
        cin >> p1;
        cout << "\nEscreva a nota da segunda prova: ";
        cin >> p2;
        cout << "\nEscreva a nota da terceira prova: ";
        cin >> p3;
        m = (p1 + p2 + p3)/3;
        cout << "\nSua média é: " << m;
        cout <<" e você foi ";
        if (m >= 7)
            cout << "aprovado" <<endl;
        else
            cout << "reprovado" <<endl;
    }
    else if (strcmp(mr,"por")==0)
    {
        cout << "\nEscreva a nota da primeira prova: ";
        cin >> p1;
        cout << "\nEscreva a nota da segunda prova: ";
        cin >> p2;
        cout << "\nEscreva a nota da terceira prova: ";
        cin >> p3;
        m = (0.3*p1+0.2*p2+0.5*p3);
        cout << "\nSua média é: " << m;
        cout <<" e você foi ";
        if (m >= 7)
            cout << "aprovado" <<endl;
        else
            cout << "reprovado" <<endl;
    }
    else if (strcmp(mr,"his")==0)
    {
        cout << "\nEscreva a nota da primeira prova: ";
        cin >> p1;
        cout << "\nEscreva a nota da segunda prova: ";
        cin >> p2;
        cout << "\nEscreva a nota da terceira prova: ";
        cin >> p3;
        m = (0.25*p1+0.3*p2+0.45*p3);
        cout << "\nSua média é: " << m;
        cout <<" e você foi ";
        if (m >= 7)
            cout << "aprovado" <<endl;
        else
            cout << "reprovado" <<endl;
    }
    else
        cout << "\nErro";

    return 0;
}

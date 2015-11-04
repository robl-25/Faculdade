#include <iostream>

using namespace std;

int main ()
{
    int n, i, a[100000], soma=0, k=0;

    cout << "\nEscreva o numero de secoes do territorio: ";
    cin >> n;

    cout << "\n\nEscreva o comprimento das secoes: ";
    for (i=0; i<n; i++)
        cin >> a[i];
    for (i=0; i<n; i++)
        soma=soma+a[i];

    soma = soma/2;

    for (i=0; k<soma; i++)
        k=k+a[i];

    if (k>soma)
        cout << "\n\n-1" << endl;
    else
        cout << "\n\nA secao do territorio onde ocorrera a divisao eh: " << i << endl;
}

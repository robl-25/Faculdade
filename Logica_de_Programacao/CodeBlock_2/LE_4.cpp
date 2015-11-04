#include <iostream>

using namespace std;

int main ()
{
    int m, n, i, j, k, g=1;
    cout << "Escreva quantas linhas a matriz terá: ";
    cin >>n;
    cout << "\nEscreva quantas colunas a matriz terá: ";
    cin >>m;

    char matriz [n][m];

    cout << "\nEscreva os elementos da matriz NXM:\n";
    for (i=0; i<n; i++)
        for (j=0; j<m; j++)
            cin >> matriz[i][j];

    cout << "\nEscreva um caracter: ";
    cin >>k;

     for (i=0; i<n; i++)
        for (j=0; j<m; j++)
        {
            if (matriz[i][j] == k)
                {
                    g=0;
                    break;
                }
        }

    if ( g == 1)
        cout << "\nA posição em que esse caracter está é linha " << i << " coluna " << j;

    else
        cout << "\nEsse caracter não foi encontrado!\n\n";


    return 0;
}

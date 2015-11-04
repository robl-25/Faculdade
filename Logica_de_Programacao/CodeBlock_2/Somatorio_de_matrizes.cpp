#include <iostream>

using namespace std;

int main ()
{
    int a[3][3], b[3][3], i, j, soma[3][3];

    cout << "\nEscreva os valores da matriz 3X3 de inteiros A:\n";
    for (i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
            cin >> a[i][j];
    }

    cout << "\nEscreva os valores da matriz 3X3 de inteiros B:\n";
    for (i=0; i<3; i++)
    {
        for (j=0; j<3; j++)
         cin >> b[i][j];
    }

    for (i=0; i<3; i++)
    {
        for (j=0; j<3; j++)
            soma[i][j]= a[i][j] + b[i][j];
    }

    cout << "\nA soma das duas matrizes é a seguinte matriz 3X3:\n";
    for (i=0; i<3; i++)
    {
        for (j=0; j<3; j++)
            cout << "  " << soma[i][j];
        cout << "\n";
    }

    return 0;
}

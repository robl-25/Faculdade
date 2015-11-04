#include <iostream>

using namespace std;

int main ()
{
    int a[3][3], b[3][3], i, j, k, m[3][3] = {
                                    {0, 0, 0},
                                    {0, 0, 0},
                                    {0, 0, 0}
                                };

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

    cout << "O resultaqdo da multiplicação das duas matrizes 3X3 é:\n";
    for (i=0; i<3; i++)
    {
        for (j=0; j<3; j++)
            {
                for (k=0; k<3; k++)
                    m[i][j] = m[i][j] + a[i][k]*b[k][j];
            }
    }

    for (i=0; i<3; i++)
    {
        for (j=0; j<3; j++)
            cout << "  " << m[i][j];
        cout << "\n";
    }

    return 0;
}

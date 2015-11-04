#include <iostream>

using namespace std;

int main ()
{
    int matriz [3][3], i,j;

    cout << "\nEscreva uma matriz 3X3 de inteiros:\n";
    for (i=0; i<3; i++)
        {
            for (j=0; j<3; j++)
                cin >> matriz [i][j];
        }

    cout << "\n\nA matriz escrita foi:\n";
    for(i=0; i<3; i++)
        {
            for(j=0; j<3; j++)
                cout << " " <<matriz [i][j];
            cout << "\n";
        }

    return 0;
}

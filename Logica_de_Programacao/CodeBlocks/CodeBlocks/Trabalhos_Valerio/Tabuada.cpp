#include <iostream>

using namespace std;

int main ()
{
    int n, cont;
    cout << "\nEscreva o número da tabuada a ser calculada: ";
    cin >> n;
    if ((n>10) || (n<1))
    cout << "\nEssa tabuada não pode ser calculada!\n";
    else
    {
        cout << "\nA tabuada desse número é:\n\n";

        for (cont=1; cont<=10; cont ++)
        {
            cout << n << " x " << cont << " = " << cont*n <<endl;
        }
    }


    return 0;
}

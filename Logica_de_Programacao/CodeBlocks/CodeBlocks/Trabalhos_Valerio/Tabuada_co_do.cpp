#include <iostream>

using namespace std;

int main ()
{
    int n, cont;
    cout << "\nEscreva o número da tabuada a ser calculada: ";
    cin >> n;
    cont=1;
    if ((n>10) || (n<1))
    cout << "Essa tabuada não pode ser calculada!";
    else
    {
        cout << "\nA tabuada desse número é:\n\n";

        do
        {
            cout << n << " x " << cont << " = " << cont*n <<endl;
            cont ++;
        }
        while (cont<=10);
    }


    return 0;
}

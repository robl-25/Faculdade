#include <iostream>

using namespace std;

int main()
{
    int n, cont, fat=1;
    cout << "\nEscreva o número para calcular o fatorial: ";
    cin >> n;
    if (n>1)
    {
        for (cont=n; cont>1; cont--)
            fat=fat*cont;
        cout << "\nO resuldado do fatorial é " << fat << endl;
    }
    else if (n<0)
        cout << "Não existe fatorial" <<endl;

    return 0;
}

#include <iostream>

using namespace std;

int main ()
{
    int a[1000], i, cont, j, maior;
    cout << "Digite o número de pessoas na fila: ";
    cin >> i;
    if ((i<0) || (i>1000))
        cout << "Não é possivel ordenar essa número de pessoas!" << endl;
    else
    {
        cout << "\nEscreva as idades das pessoas:\n";
        for (cont=0; cont<i; cont++)
            cin >> a[cont];
        for (cont=0; cont<i; cont ++)
            {




            }
    }

    return 0;
}




for( x = 0; x < TAM; x++ )
{
for( y = x + 1; y < TAM; y++ ) // sempre 1 elemento à frente
{
if ( vetor[y] > vetor[x] )
{
aux = vetor[y];
vetor[y] = vetor[x];
vetor[x] = aux;
}
}

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n,f;
    cout << "Escreva tres numeros: ";
    cin >> n;
    while (n!=0)
    {
        f=n%10;
        n=n/10;
        cout << f << " ";
    }
    return 0;
}

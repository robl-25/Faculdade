#include <iostream>

using namespace std;

int main ()
{
    int v[5], i, soma=0;

    for (i=0; i<5; i++)
        cin >> v[i];

    for (i=0; i<5; i++)
        soma=soma+v[i];

    cout << soma/5;

    return 0;
}

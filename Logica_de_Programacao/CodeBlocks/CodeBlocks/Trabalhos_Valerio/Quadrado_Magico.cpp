//Programa: Quadrado Mágico
//Autora: Mariane; RA: 86.902
//Versio: 5.1, date 20th Jun 2013

#include <iostream>

using namespace std;

int main ()
{
    int a,b,c,d,e,f,g,h,i,x;
    cout << "\nEscreva a matriz: \n";
    cin >> a >> b >> c;
    cin >> d >> e >> f;
    cin >> g >> h >> i;

    if ((a>0) && (a<1000) && (b>0) && (b<1000) && (c>0) && (c<1000) && (d>0) && (d<1000) && (e>0) && (e<1000) && (f>0) && (f<1000) && (g>0) && (g<1000) && (h>0) && (h<1000) && (i>0) && (i<1000))
    {
        if ((b+c+a==d+e+f) && (e+f+d==g+h+i) && (a+d+g==b+e+h) && (c+f+i==a+d+g) && (a+e+i==c+e+g))
        {
            x=a+b+c;
            cout << "\nÉ um quadrado mágico e o valor da somatória é ";
        }

        else
            x=-1;

        cout << "\nx = " << x <<endl;
    }
    else
        cout << "\nErro" <<endl;

    return 0;
}

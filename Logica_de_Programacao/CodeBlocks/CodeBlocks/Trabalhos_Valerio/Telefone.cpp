//Programa: Telefone
//Autora: Mariane; RA: 86.902
//Versio: 1.0, date 29th Jun 2013

#include <iostream>
#include <conio.h>

using namespace std;

int main ()
{
    int cont;
    char t;
    cout << "\nEscreva o numero de telefone a ser traduzido:\n\n";

    for (cont=0,t=' '; cont<15 && t!=13; cont++)
        {
            //cin >> t;
            t = getch();
            if ( (t== 'a') || (t=='b') || (t=='c') )
                t='2';
            else if ( (t=='d') || (t=='e') || (t=='f'))
                    t='3';
                else if ( (t=='g') || (t=='h') || (t=='i'))
                        t='4';
                    else if ( (t=='j') || (t=='k') || (t=='l'))
                            t='5';
                        else if ( (t=='m') || (t=='n') || (t=='o'))
                                t='6';
                            else if ( (t=='p') || (t=='q') || (t=='r') || (t=='s'))
                                    t='7';
                                else if ( (t=='t') || (t=='u') || (t=='v'))
                                        t='8';
                                    else if ( (t=='w') || (t=='x') || (t=='y') || (t=='z'))
                                            t='9';
            cout << t;

        }
    cout << "\n";

    return 0;
}

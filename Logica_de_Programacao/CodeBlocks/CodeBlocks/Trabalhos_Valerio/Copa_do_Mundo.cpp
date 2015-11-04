//Programa: Copa do Mundo
//Autora: Mariane; RA: 86.902
//Versio: 1.0, date 27th Jun 2013
#include <iostream>

using namespace std;

int main ()
{
    int m, n, i;
    char j1, j2, j3, j4, j5, j6, j7, j8, j9, j10, j11, j12, j13, j14, j15;

    for (i=1; i<16; i++)
    {
        cout << "\nDigite o resultado do jogo " << i << " :" << endl;
        cin>>m>>n;

        switch (i)
            {
                case 1: if (m>n) j1='A'; else j1='B';
                case 2: if (m>n) j2='C'; else j2='D';
                case 3: if (m>n) j3='E'; else j3='F';
                case 4: if (m>n) j4='G'; else j4='H';
                case 5: if (m>n) j5='I'; else j5='J';
                case 6: if (m>n) j6='K'; else j6='L';
                case 7: if (m>n) j7='M'; else j7='N';
                case 8: if (m>n) j8='O'; else j8='P';
                case 9: if (m>n) j9=j1;  else j9=j2;
                case 10: if (m>n) j10=j3; else j10=j4;
                case 11: if (m>n) j11=j5; else j11=j6;
                case 12: if (m>n) j12=j7; else j12=j8;
                case 13: if (m>n) j13=j9; else j13=j10;
                case 14: if (m>n) j14=j11; else j14=j12;
                case 15: if (m>n) j15=j13; else j15=j14;

            }



    }

    cout << "\nA equipe campeã é a " << j15 <<endl;


    return 0;
}

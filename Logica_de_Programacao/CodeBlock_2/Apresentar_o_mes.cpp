#include <iostream>

using namespace std;

int main ()
{
    int m;
    cout << "\nEscreva o número de um mês do calendário: ";
    cin >> m;

     if(m<1 || m>12)
        cout << "\nMês inválido";
    else
    {
        if (m==1)
            cout << "\nO mês correspondente é Janeiro\n\n" <<endl;
        else if (m==2)
            cout << "\nO mês correspondente é Fevereiro\n\n" <<endl;
            else if (m==3)
            cout << "\nO mês correspondente é Março\n\n" <<endl;
                else if (m==4)
                    cout << "\nO mês correspondente é Abril\n\n" <<endl;
                    else if (m==5)
                            cout << "\nO mês correspondente é Maio\n\n" <<endl;
                            else if (m==6)
                                    cout << "\nO mês correspondente é Junho\n\n" <<endl;
                                    else if (m==7)
                                            cout << "\nO mês correspondente é Julho\n\n" <<endl;
                                            else if (m==8)
                                                    cout << "\nO mês correspondente é Agosto\n\n" <<endl;
                                                    else if (m==9)
                                                            cout << "\nO mês correspondente é Setembro\n\n" <<endl;
                                                            else if (m==10)
                                                                    cout << "\nO mês correspondente é Outubro\n\n" <<endl;
                                                                    else if (m==11)
                                                                            cout << "\nO mês correspondente é Novembro\n\n" <<endl;
                                                                            else if (m==12)
                                                                                    cout << "\nO mês correspondente é Dezembro\n\n" <<endl;
    }

    return 0;
}

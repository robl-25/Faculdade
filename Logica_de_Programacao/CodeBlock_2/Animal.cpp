#include <iostream>

using namespace std;

int main ()
{
    char r;
    cout << "Escolha um animal dentre os animais abaixo e responda as perguntas com s ou n, para o computador adivinhar qual animal foi escolhido:\n";
    cout << "Leão, Cavalo, Morcego, Baleia, Avestruz, Pinguim, Pato, Águia, Tartaruga, Crocodilo e Cobra";

    cout << "\n\nO animal escolhido é mamífero? ";
    cin >> r;
    if (r == 's')
        {
            cout << "\nO animal é quadrupede? ";
            cin >> r;
            if (r == 's')
            {
                cout << "\nO animal é carnívoro? ";
                cin >> r;
                if (r == 's')
                cout << "\nO animal escolhido é o Leão!";
                else
                cout << "\nO animal escolhido é o Cavalo!";
            }
            else
            {
                cout << "\nO animal é voador? ";
                cin >> r;
                if (r == 's')
                    cout << "\nO animal escolhido foi o Morcego!";
                else
                    cout << "\nO animal escolhido foi a Baleia!";
            }


        }
    else
    {
        cout << "\nO animal escolhido é uma ave? ";
        cin >> r;
        if (r == 's')
        {
            cout << "\nO animal é um Não-Voador? ";
            cin >> r;
            if (r == 's')
            {
                cout << "\nO animal é de ambiente tropical? ";
                cin >> r;
                if (r == 's')
                    cout << "\nO animal escolhido é o Avestruz!";
                else
                    cout << "\nO animal escolhido é o Pinguim!";
            }
            else
            {
                cout << "\nO animal é um nadador? ";
                cin >> r;
                if (r == 's')
                    cout << "\nO animal escolhido é o Pato";
                else
                    cout << "\nO animal escolhido é a Águia";
            }
        }
        else
        {
            cout << "\nO animal escolhido possui casco? ";
            cin >> r;
            if (r == 's')
                cout << "\nO animal escolhido é a tartaruga!";
            else
            {
                cout << "\nO animal escolhido é carnivoro? ";
                cin >> r;
                if (r == 's')
                    cout << "\nO animal escolhido é o Crocodilo!";
                else
                    cout << "\nO animal escolhido é a Cobra!";
            }
        }

    }

    cout << "\n\n";

    return 0;
}

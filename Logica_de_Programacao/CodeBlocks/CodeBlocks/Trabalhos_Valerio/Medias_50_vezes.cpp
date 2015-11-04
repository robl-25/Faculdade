#include <iostream>

using namespace std;

int main()
{
    float p1, p2, p3, p4, md, cont;
    char nome[50];

    for (cont=1; cont<=50; cont++)
    {
        cout << "\nEscreva as notas das provas do(a) aluno(a):\n";
        cin >> p1 >> p2 >> p3 >> p4;
        md=(p1+p2+p3+p4)/4;
        cout << "\nEscreva seu nome: ";
        cin >> nome;
        cout << "\nA média do(a) aluno(a) " << nome << " é " << md <<endl;
    }

    return 0;
}

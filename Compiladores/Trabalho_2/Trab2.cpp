/*
* Nome: Mariane Coelho Robl
* R.A.: 86902

* Descricao: Implementa um AFD q le símbolos, identificadores e números
*
* Observacoes:
* 1 - Devido a forma como foi populada a matriz de estados esse programa
* necessita ser compilado com o c++11 (no terminal somente acrescentar a
* linha de compilacao -std=c++11)
*
* 2 - Os estados sao: q0 -> estado inicial
*                     q1 -> estado de aceitacao de numeros
*                     q2 -> estado de aceitacao de simbolos
*                     q3 -> estado de aceitacao de identificadores
* */

#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

ifstream arq("teste.txt");

inline char proximoChar(){
    char ch;
    arq.get(ch);
    return(ch);
}

inline int Pertence(char ch, vector<char>& numeros,
                    vector<char>& identificadores, vector<char>& simbolos){

    vector<char>::iterator it;

    it = find(numeros.begin(), numeros.end(), ch);

    if(it != numeros.end()){
        return 0;
    }

    it = find(identificadores.begin(), identificadores.end(), ch);

    if(it != identificadores.end()){
        return 1;
    }

    it = find(simbolos.begin(), simbolos.end(), ch);

    if(it != simbolos.end()){
        return 2;
    }
}

int main(){
    char ch, chAnt;
    int i, estado = 0, estadoChar;

    /* Matriz de estados */
    vector< vector<int> > matriz;

    for(i=0; i<4; i++){
        vector<int> aux(3, 0);

        matriz.push_back(aux);
    }

    /* Preenche a matriz de estados
    * Uma melhor representacao dessa matrix pode ser:
    * {  , numeros, identificadores, simbolos}
    * {q0,   1    ,      3         ,     2   }
    * {q1,   1    ,      3         ,     2   }
    * {q2,   1    ,      3         ,     2   }
    * {q3,   1    ,      3         ,     2   }
    */

    matriz = {
        {1, 3, 2},
        {1, 3, 2},
        {1, 3, 2},
        {1, 3, 2}
    };

    /* Armazena o alfabeto de cada caracter */
    vector<char> numeros;
    vector<char> identificadores;
    vector<char> simbolos;

    /* Tratar os espacos */
    char espaco = (char) 32;

    for(i=48; i<58; i++){
        numeros.push_back( (char) i);
    }

    for(i=65; i<91; i++){
        identificadores.push_back( (char) i);
    }

    for(i=97; i<123; i++){
        identificadores.push_back( (char) i);
    }

    /* Simbolo - */
    simbolos.push_back((char) 45);

    /* Simbolo < */
    simbolos.push_back((char) 60);

    /* Simbolo > */
    simbolos.push_back((char) 62);

    /* Simbolo * */
    simbolos.push_back((char) 42);

    /* Simbolo + */
    simbolos.push_back((char) 43);

    /* Simbolo = */
    simbolos.push_back((char) 61);

    /* Simbolo & */
    simbolos.push_back((char) 38);

    /* Simbolo % */
    simbolos.push_back((char) 37);

    /* Simbolo / */
    simbolos.push_back((char) 47);

    /* Simbolo ^ */
    simbolos.push_back((char) 94);

    chAnt = espaco;

    while(!arq.eof()){
        ch = proximoChar();

        /* Espacos e quebra de linha nao sao processados */
        if(ch != espaco && ch != (char) 10){
            estadoChar = Pertence(ch, numeros, identificadores, simbolos);

            /* Caso nao pertenca aos conjuntos */
            if(estadoChar == -1 ){
                printf("Nao Aceita, devido ao caracter %c \n", ch);
                arq.close();
                return -1;
            }

            else{
                estado = matriz[estado][estadoChar];
            }

        }

        /* Fim de uma entrada */
        if(ch == (char) 10 && ch != chAnt){
            /* Para nao aceitar uma entrada vazia */
            if(estado != 0){
                printf("Aceita, com o estado q%d \n", estado);
            }

            else{
                printf("Nao Aceita, devido a entrada vazia \n");
            }
        }

        else if(ch == chAnt && ch == (char) 10){
            printf("Nao Aceita, devido a entrada vazia \n");
        }

        chAnt = ch;

    }

    return 0;
}

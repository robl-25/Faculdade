#include <stdio.h>
#include <stdlib.h>

void Achar_lucro(int *inicio, int *fim, int *lucroT, int C, int R[], int comeca,
                 int termina){
    int meio = (comeca+termina)/2;
    int i;
    int retorno=0, lucro_maxD=0, lucro_maxE=0, lucro=0;
    int custoD=0, custoE=0;

    for(i=meio; i>=comeca; i--){
        //Excluindo o primeiros
        retorno+=R[i];
        custoE += C;
        lucro = retorno - custoE;

        if(lucro > lucro_maxE){
          lucro_maxE = lucro;
          *inicio = i;
        }
    }

    retorno = 0;

    for(i=meio+1; i<=termina; i++){
        //Excluindo o primeiros
        retorno+=R[i];
        custoD += C;
        lucro = retorno - custoD;

        if(lucro > lucro_maxD){
          lucro_maxD = lucro;
          *fim = i;
        }
    }

    *lucroT = lucro_maxE + lucro_maxD;
}

void Achar_Maior_lucro(int R[], int C, int *inicio, int *fim,
                       int *lucroT, int comeca, int termino){
    int inicioD, fimD, lucroTD;
    int inicioE, fimE, lucroTE;
    int inicioCross, fimCross, lucroTCross;
    int meio;

    if(comeca == termino){
        *inicio = comeca;
        *fim = termino;
        *lucroT = R[comeca] - C;
    }
    else{
        meio = (comeca+termino)/2;
        Achar_Maior_lucro(R, C, &inicioE, &fimE, &lucroTE, comeca, meio);
        Achar_Maior_lucro(R, C, &inicioD, &fimD, &lucroTD, meio+1, termino);
        Achar_lucro(&inicioCross, &fimCross, &lucroTCross, C, R, comeca, termino);
        if(lucroTD > lucroTE && lucroTD > lucroTCross){
            *inicio = inicioD;
            *fim = fimD;
            *lucroT = lucroTD;
        }
        else if(lucroTE > lucroTD && lucroTE > lucroTCross){
            *inicio = inicioE;
            *fim = fimE;
            *lucroT = lucroTE;
        }
        else{
            *inicio = inicioCross;
            *fim = fimCross;
            *lucroT = lucroTCross;
        }

    }
}

int main(){
    int N, C, i;
    int lucroT, inicio, fim;

    scanf("%d", &N);
    scanf("%d", &C);

    int R[N];

    for(i=0; i<N; i++){
        scanf("%d", &R[i]);
    }

    Achar_Maior_lucro(R, C, &inicio, &fim, &lucroT, 0, N-1);

    if(lucroT < 0){
        printf("0");
    }
    else{
        printf("%d", lucroT);
    }
    return 0;
}

//Nome do Programa: Estacionamento
//Mariane Coelho Robl        R.A.: 86902
//Versão:1.0                 23th agost 2013

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct registro
{
    char placadeveiculo[7];
    char nome[100];
    int dia;
    int mes;
    int ano;
    float tempo;
};

void main ()
{
    struct registro pessoa [100];
    int i=0, j;
    float f = 0.0;
    char l,c;
    while(c != '1'){
        printf ("Escreva a placa do veículo: ");
        gets (pessoa[i].placadeveiculo);
        printf ("Escreva do dono do veiculo: ");
        gets (pessoa[i].nome);
        printf ("Escreva a data separando-a por espaços: ");
        scanf ("%d %d %d", &pessoa[i].dia, &pessoa[i].mes, &pessoa[i].ano);
        printf ("Digite o tempo (em minutos) em que a pessoa ficou no estacionamento: ");
        scanf ("%f", &pessoa[i].tempo);
        pessoa[i].tempo = ceil(pessoa[i].tempo/60);
        scanf ("%c", &l);
        printf ("Digite 1 para finalizar, caso contrário digite 0: ");
        scanf ("%s", &c);
        scanf ("%c", &l);
        i++;
    }

    for (j=0; j<i; j++)
    {
        if (pessoa[j].tempo > 0.25)
            f=f+(pessoa[j].tempo*3);
    }
    printf ("\nO faturamento foi de %f reais", f);

    printf ("\nDeseja imprimir as pessoas que passaram pelo estacionamento? (y/n) ");
    scanf ("%c", &l);

    if (l == 'y')
    {
        for (j=0; j<i; j++)
            printf ("%s\n", pessoa[j].nome);
    }
}

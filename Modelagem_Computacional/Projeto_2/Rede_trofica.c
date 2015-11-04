//27.03.2015
//Projeto 2 Modelagem Computacional
//Integrantes: Alex Monteiro
//             Daniel Alves
//             Mariane Robl

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define dt 0.01
#define l 10.0 //Limitante do crescimento do mato

float alphaM = 1.0;//aumento do MATO
float betaM = 0.250;//queda do MATO por causa da VACA
float gamaM = 0.200;//queda do MATO por causa do CAVALO

float alphaV = 0.200;//queda natural da VACA
float betaV = 0.005;//queda da VACA por causa do HUMANO
float gamaV = 0.007;//queda da VACA por causa do LEAO
float sigmaV = 0.03;//queda da VACA por causa do FUNGO
float miV = 0.08;//aumento da VACA por causa do MATO

float alphaC = 0.200;//queda natural do CAVALO
float gamaC = 0.008;//queda do CAVALO por causa do LEAO
float sigmaC = 0.03;//queda do CAVALO por causa do FUNGO
float miC = 0.08;//aumento do CAVALO por causa do MATO

float alphaH = 0.150;//queda natural do humano
float betaH = 0.02;//queda do HUMANO por causa do LEAO
float sigmaH = 0.009;//queda do HUMANO por causa do FUNGO
float gamaH = 0.2;//aumento do HUMANO por causa da VACA

float alphaL = 0.200;//queda natural do LEAO
float sigmaL = 0.01;//queda do LEAO por causa do FUNGO
float betaL = 0.09;//aumento do LEAO por causa da VACA
float gamaL = 0.08;//aumento do LEAO por causa do CAVALO
float miL = 0.03;//aumento do LEAO por causa do HUMANO

float alphaF = 0.300;//queda natural do FUNGO
float betaF = 0.06;//aumento do FUNGO por causa da VACA
float gamaF = 0.05;//aumento do FUNGO por causa do CAVALO
float miF = 0.04;//aumento do FUNGO por causa do HUMANO
float sigmaF = 0.05;//aumento do FUNGO por causa do LEAO

//Funcao que calcula a populacao de cada especie com ou sem agente externo
void Calcula(int a){
    double M = 4;//Vegetacao, eh ajudada a crescer pelo fungo
    double V = 1;//Vaca, predador do mato
    double C = 1;//Cavalo, predador do mato
    double H = 1;//Humano, predador da vaca e do cavalo
    double L = 1;//Leao, predador da vaca, cavalo e humano
    double F = 1;//Fungo, predador do cavalo, vaca, humano e leao
    double dm;//Taxa de crescimento do mato
    double dv;//Taxa de crescimento da vaca
    double dc;//Taxa de crescimento do cavalo
    double dh;//Taxa de crescimento do humano
    double dl;//Taxa de crescimento do leao
    double df;//Taxa de crescimento do fungo
    double t = dt;//Variavel de controle de tempo
    int i;//Controla o tempo de integracao
    //Arquivos das graficos
    char impr_mato[] = "mato.txt";
    char impr_vaca[] = "vaca.txt";
    char impr_cavalo[] = "cavalo.txt";
    char impr_humano[] = "humano.txt";
    char impr_leao[] = "leao.txt";
    char impr_fungo[] = "fungo.txt";

    FILE *arq;
    FILE *arq_I;
    FILE *arq_II;
    FILE *arq_III;
    FILE *arq_IV;
    FILE *arq_V;

    //Abertura dos arquivos
    arq = fopen(impr_mato, "w");
    arq_I = fopen(impr_vaca, "w");
    arq_II = fopen(impr_cavalo, "w");
    arq_III = fopen(impr_humano, "w");
    arq_IV = fopen(impr_leao, "w");
    arq_V = fopen(impr_fungo, "w");

    if(arq == NULL || arq_I == NULL || arq_II == NULL || arq_IV == NULL || arq_V == NULL)
    {
        printf("Erro, nao foi possivel abrir o arquivo\n");
        return ;
    }

    if(a == 4)
        V = V*1.5;
    if(a == 6)
        C = C*1.5;
    if(a == 9)
        H = H*1.5;
    if(a == 11)
        L = L*1.5;
    if(a == 14)
        F = F*1.5;

    for(i=0; i<500000; i++)
            {
                //escreve as variaveis da posicao no arquivo
                fprintf(arq,"%lf\t",t);
                fprintf(arq,"%lf\n",M);
                fprintf(arq_V, "%lf\t", t);
                fprintf(arq_V, "%lf\n", F);
                fprintf(arq_I, "%lf\t",t);
                fprintf(arq_I, "%lf\n",V);
                fprintf(arq_II, "%lf\t",t);
                fprintf(arq_II, "%lf\n",C);
                fprintf(arq_III, "%lf\t",t);
                fprintf(arq_III, "%lf\n",H);
                fprintf(arq_IV, "%lf\t", t);
                fprintf(arq_IV, "%lf\n", L);

                //Calculos do crescimento
                dm = M*(alphaM - alphaM*M/l- betaM*V - gamaM*C)*dt;//Calculo do crescimento do mato
                dv = V*(-alphaV + miV*M - betaV*H - gamaV*L - sigmaV*F)*dt;//Calculo do crescimento da vaca
                dc = C*(-alphaC + miC*M - gamaC*L - sigmaC*F)*dt;//Calculo do crescimento do cavalo
                dh = H*(-alphaH + gamaH*V - betaH*L - sigmaH*F)*dt;//Calculo do crescimento do humano
                dl = L*(-alphaL + betaL*V + gamaL*C + miL*H - sigmaL*F)*dt;//Calculo do crescimento do leao
                df = F*(-alphaF + betaF*V + gamaF*C + miF*H + sigmaF*L)*dt;//Calculo do crescimento do fungo

                //Acrescimo em cada variavel
                M += dm;
                V += dv;
                C += dc;
                H += dh;
                L += dl;
                F += df;
                t+=dt;
            }
            //A partir desse tempo ocorre o agente externo
            if(a == 1)
                M = M*0.5;
            if(a == 2)
                M = M*5;
            if(a == 3)
                V = V*0.5;
            if(a == 5)
                C = C*0.5;
            if(a == 7)
                H = H*0.5;
            if(a == 8)
                H = 0;
            if(a == 10)
                L = L*0.8;
            if(a == 12)
                L = L*0.5;
            if(a == 13)
                F = F*0.5;
            if(a == 15)
                F = 0;

            for(i=0; i<500000; i++)
            {
                //escreve as variaveis da posicao no arquivo
                fprintf(arq,"%lf\t",t);
                fprintf(arq,"%lf\n",M);
                fprintf(arq_V, "%lf\t", t);
                fprintf(arq_V, "%lf\n", F);
                fprintf(arq_I, "%lf\t",t);
                fprintf(arq_I, "%lf\n",V);
                fprintf(arq_II, "%lf\t",t);
                fprintf(arq_II, "%lf\n",C);
                fprintf(arq_III, "%lf\t",t);
                fprintf(arq_III, "%lf\n",H);
                fprintf(arq_IV, "%lf\t", t);
                fprintf(arq_IV, "%lf\n", L);

                //Calculos do crescimento
                dm = M*(alphaM - alphaM*M/l- betaM*V - gamaM*C)*dt;//Calculo do crescimento do mato
                dv = V*(-alphaV + miV*M - betaV*H - gamaV*L - sigmaV*F)*dt;//Calculo do crescimento da vaca
                dc = C*(-alphaC + miC*M - gamaC*L - sigmaC*F)*dt;//Calculo do crescimento do cavalo
                dh = H*(-alphaH + gamaH*V - betaH*L - sigmaH*F)*dt;//Calculo do crescimento do humano
                dl = L*(-alphaL + betaL*V + gamaL*C + miL*H - sigmaL*F)*dt;//Calculo do crescimento do leao
                df = F*(-alphaF + betaF*V + gamaF*C + miF*H + sigmaF*L)*dt;//Calculo do crescimento do fungo

                //Acrescimo em cada variavel
                M += dm;
                V += dv;
                C += dc;
                H += dh;
                L += dl;
                F += df;
                t+=dt;
            }
}

int main()
{
    int escolha = 0;//Variavel que controla a pertubacao a ser aplicada

    printf("\n\tProjeto voltado para analise de uma rede trófica pre-definida\n");
    while(escolha < 1 || escolha > 16){
    printf("Digite o número correspondente a pertubação desejada:\n");
    printf("1 - Seca, comprometendo parte da plantacao\n");
    printf("2 - Chuva, aumentando a populacao da plantacao\n");
    printf("3 - Morte repentina de vacas\n");
    printf("4 - Migração de vacas, aumentando a populacao inicial\n");
    printf("5 - Morte repentina de cavalos\n");
    printf("6 - Migração de cavalos, aumentando a populacao inicial\n");
    printf("7 - Morte repentina de humanos\n");
    printf("8 - Doenca que extingue 100 por cento da populacao de humanos\n");
    printf("9 - Migracao de humanos, aumentando a populacao inicial\n");
    printf("10 - Caca aos leos\n");
    printf("11 - Migracao de leos, aumentando a populacao inicial\n");
    printf("12 - Morte repentina de leos\n");
    printf("13 - Morte repentina dos fungos\n");
    printf("14 - Maior migracao da populacao inicial de fungos\n");
    printf("15 - Dispercao de inseticidadas, matando 100 por cento da populacao de fungos\n");
    printf("16 - Nenhum fator externo\n");
    scanf("%d",&escolha);
    if(escolha < 1 || escolha > 16)
        printf("\nValor invalido\n");
    }
    switch(escolha){
        case 1:
            Calcula(1);
            break;
        case 2:
            Calcula(2);
            break;
        case 3:
            Calcula(3);
            break;
	    case 4:
            Calcula(4);
            break;
        case 5:
            Calcula(5);
            break;
        case 6:
            Calcula(6);
            break;
        case 7:
            Calcula(7);
            break;
        case 8:
            Calcula(8);
            break;
        case 9:
            Calcula(9);
            break;
        case 10:
            Calcula(10);
            break;
        case 11:
            Calcula(11);
            break;
        case 12:
            Calcula(12);
            break;
        case 13:
            Calcula(13);
            break;
        case 14:
            Calcula(14);
            break;
        case 15:
            Calcula(15);
            break;
        case 16:
            Calcula(16);
            break;
    }

    return 0;
}

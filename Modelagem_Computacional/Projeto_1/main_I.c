//15.03.2015
//Projeto 1 Modelagem Computacional
//Integrantes: Alex Monteiro
//             Daniel Alves
//             Mariane Robl
//O programa tem como objetvo descrever a trajetoria
//do lancamento de projeteis

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    //Declaracao de variaveis
    double v0 = 50;
    double vx;
    double vy;
    double t = 0.0;
    double dt = 0.01;
    double g = -10.0;
    double m = 0.5;
    double x = 0.0;
    double y = 0.0;
    double theta = M_PI_4;
    double k = 0.4;
    double ec = 0.0;
    double ecx = 0.0;
    double ecy = 0.0;
    double ep = 0.0;
    double calor = 0.0;
    double v = 0.0;
    double dx;
    double dy;
    double ds;
    double et;
    //Arquivos das graficos
    char impr_posicao[] = "posicao.txt";
    char impr_deslocamento[] = "deslocamento.txt";
    char impr_velocidade[] = "velocidade.txt";
    char impr_energiaC[] = "energiaC.txt";
    char impr_energiaG[] = "energiaG.txt";
    char impr_energiaT[] = "energiaT.txt";
    char impr_calor[] = "calor.txt";
    char impr_velocidadex[] = "velocidadex.txt";
    char impr_velocidadey[] = "velocidadey.txt";

    //ponteiro para abertura de arquivos
    FILE *arq;
    FILE *arq_I;
    FILE *arq_II;
    FILE *arq_III;
    FILE *arq_IV;
    FILE *arq_V;
    FILE *arq_VI;
    FILE *arq_VII;
    FILE *arq_VIII;

    //divisao do movimento nos eixos
    vx = v0*cos(theta);
    vy = v0*sin(theta);
    ecx = (m*(pow(vx,2)))/2;
    ecy = (m*(pow(vy,2)))/2;
    ec = ecx + ecy;
    ep = m*(-g)*y;
    et = ec + ep + calor;
    v = v0;

    arq = fopen(impr_posicao, "w");
    arq_I = fopen(impr_velocidade, "w");
    arq_II = fopen(impr_energiaC, "w");
    arq_III = fopen(impr_energiaG, "w");
    arq_IV = fopen(impr_energiaT, "w");
    arq_V = fopen(impr_deslocamento, "w");
    arq_VI = fopen(impr_calor, "w");
    arq_VII = fopen(impr_velocidadex, "w");
    arq_VIII = fopen(impr_velocidadey, "w");

    if(arq == NULL || arq_I == NULL || arq_II == NULL || arq_IV == NULL || arq_V == NULL){
        printf("Erro, nao foi possivel abrir o arquivo\n");
        return 0;
    }

    //calculo do movimento no tempo
    do{
        //escreve as variaveis da posicao no arquivo
        fprintf(arq,"%.2lf\t",t);
        fprintf(arq,"%.2lf\n",y);
        fprintf(arq_V, "%.2lf\t", t);
        fprintf(arq_V, "%.2lf\n", x);
        fprintf(arq_I, "%.2lf\t",t);
        fprintf(arq_I, "%.2lf\n",v);
        fprintf(arq_II, "%.2lf\t",t);
        fprintf(arq_II, "%.2lf\n",ec);
        fprintf(arq_III, "%.2lf\t",t);
        fprintf(arq_III, "%.2lf\n",ep);
        fprintf(arq_IV, "%.2lf\t", t);
        fprintf(arq_IV, "%.2lf\n", et);
        fprintf(arq_VI, "%.2lf\t", t);
        fprintf(arq_VI, "%.2lf\n", calor);
        fprintf(arq_VII, "%.2lf\t",t);
        fprintf(arq_VII, "%.2lf\n",vx);
        fprintf(arq_VIII, "%.2lf\t",t);
        fprintf(arq_VIII, "%.2lf\n",vy);

        //calcula os novos valores da velocidade e posicao
        vx = vx/(1+(k/m));
        vy = ((g*dt)+vy)/(1+((k/m)*dt));
        x += (vx*dt);
        y += (vy*dt);
        dx = (vx*dt);
        dy = (vy*dt);
        ds = sqrt(pow(dx,2) + pow(dy,2));
        v = sqrt(pow(vx,2) + pow(vy,2));
        ecx += -(k*vx*dx);
        ecy += ((m*g) - (k*vy))*dy;
        ec = ecx + ecy;
        ep = m*(-g)*y;
        calor += (k*pow(ds,2))/dt;
        et = ec + ep + calor;
        t += dt;

    }while(y>=0.0);


    return 0;
}

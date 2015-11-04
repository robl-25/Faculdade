#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define N 7
#define tmax 1000.
#define dt 0.01

//Constantes
#define lambda 0.005555556
#define beta 0.071428571
#define zeta 0.166666667
#define alfa 0.1
#define mu 1.309
#define sigma 0.1309
#define omega_1 0.00654
#define omega_2 0.1

typedef struct{

    /* Populacoes do continente */
    long double S;
    long double I;
    long double E;
    long double R;
    long double V;

    /* Coeficientes migratorios */
    long double saida;
    long double entrada;

    /* Coeficientes da forca de infeccao */
    long double aumenta = 0;
    long double diminui = 0;
    
} Continente;

Continente cont[N];


void le_entrada(char** args, double* gamaT, double* delta, double* I, int *pos){
    *gamaT =  (double) strtod(args[1], (char**) NULL);
    *delta =  (double) strtod(args[2], (char**) NULL);
    *I =  (double) strtod(args[3], (char**) NULL);
    *pos = (int) strtol(args[4], (char**) NULL, 10);

}

void Doenca(double delta, double gamaT, double psiT){
    double dS, dE, dI, dR, dV, gama=0, psi=0;
    double t;
    int j;

    //Arquivo para o grafico
    char impr_doenca[] = "doenca.txt";
    FILE *arq;
    //Abertura do arquivo
    arq = fopen(impr_doenca, "w");

    if(arq == NULL){
        printf("Erro, nao foi possivel abrir o arquivo\n");
        return ;
    }

    for(t=dt; t<tmax; t+=dt){
    
        for(j=0; j<N; j++){
            //Verifica o quanto de populacao que ira nascer
            gama = (omega_1*(cont[j]->S+cont[j]->E+cont[j]->R+cont[j]->V) + 
                    omega_2*cont[j]->I)*gamaT;
            psi = (omega_1*(cont[j]->S+cont[j]->E+cont[j]->R+cont[j]->V) + 
                    omega_2*cont[j]->I)*psiT;

            //Taxa de variacao da populacao sucetivel
            dS = (lambda*cont[j]->R + gama - (mu + cont[j]->aumenta - 
                    cont[j]->diminui)*cont[j]->I*cont[j]->S - 
                    omega_1*cont[j]->S - delta*cont[j]->S - 
                    sigma*cont[j]->E*cont[j]->S)*dt;

            //Taxa de variacao da populacao exposta
            dE = ((mu + cont[j]->aumenta - cont[j]->diminui)*cont[j]->I*
                    cont[j]->S + alfa*cont[j]->I + sigma*cont[j]->E*cont[j]->S
                    - omega_1*cont[j]->E - beta*cont[j]->E - 
                    zeta*cont[j]->E)*dt;

            //Taxa de variacao da populacao infectada
            dI = (zeta*cont[j]->E - omega_2*cont[j]->I - alfa*cont[j]->I)*dt;

            //Taxa variacao da populacao recuperada
            dR = (beta*cont[j]->E - lambda*cont[j]->R - omega_1*cont[j]->R)*dt;

            //Taxa de variacao da populacao vacinada
            dV = (delta*cont[j]->S + psi - omega_1*cont[j]->V)*dt;

            /*if((fabs(dS) <= 0.00001 && fabs(dE) <= 0.00001) &&
               (fabs(dI) <= 0.00001 && fabs(dR) <= 0.00001) &&
                fabs(dV) <= 0.00001){
                NP[j] = 0;
            }*/

            //Somente ira crescentar se algum incremento for diferente de zero
            else{

                //Acrescenta a taxa na populacao correspondente
                cont[j]->S += dS;
                cont[j]->E += dE;
                cont[j]->I += dI;
                cont[j]->R += dR;
                cont[j]->V += dV;

                fprintf(arq,"%f\t%f\t%f\t%f\t%f\t%.2f\n", S, E, I, R, V, t);
            }   
        }
    }
}

void main(int a, char** args){
    double gamaT; //Porcentagem de pessoas que nascem e nao sao vacinadas
    double delta; //Porcentagem de pessoas que sao vacinas adultas
    double psiT;
    double I;
    int pos, i;

    le_entrada(args, &gamaT, &delta, &I, &pos);
    psiT = 1 - gamaT;
    cont[po]->S = 1 - I;
    cont[pos]->I = I;
    
    for(i=0; i<N; i++){
        cont[i]->E = 0;
        cont[i]->R = 0;
        cont[i]->V = 0;
        if(i != pos){
            cont[i]->I = 0;
            cont[i]->S = 1;
        }
    }

    Doenca(delta,gamaT,psiT);
}

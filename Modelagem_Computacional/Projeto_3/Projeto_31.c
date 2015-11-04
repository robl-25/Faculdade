//22.05.2015
//Projeto 3 Modelagem Computacional
//Integrantes: Alex Monteiro
//             Daniel Alves
//             Mariane Robl

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define w_ij 0.02
#define Theta 0.5
#define Alpha 6.0
#define Epsilon 0.02
#define Beta 0.1
#define N 500
#define k 4
#define dt 0.1
#define tmax 1000

int ligacoes[N][N];

typedef struct a{
    float x, y, I, Si;
}neuronio;

neuronio vet[N];

//Inicializa a matriz com as ligacoes
void Inicializa(){
    int i, j;

    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            ligacoes[i][j] = 0;
        }
    }
}

//Incializa o vetor com os neuronios inativos
void InicializaVet(){
    int i;

    for(i=0; i<N; i++){
        vet[i].x = (((float)(rand()%100)/1000.0)*4.0)-2.0;
        vet[i].y = (((float)(rand()%100)/1000.0)*10.0);
        vet[i].I = -0.02;
    }
}

void Rede_Regular(){
    int i, j, pos;

    for(i=0; i<N; i++){
        for (j=0 ; j<(k/2) ; j++)
        {
            pos = (i+j+1)%N;
            ligacoes[i][pos] = 1;
            ligacoes[pos][i] = 1;
        }
    }
}

void Rede_Livre_Escala(){
    int i, r, var, comp;
    int prop[N];
    int soma_prop = 2;

    ligacoes[0][1] = 1;
    ligacoes[1][0] = 1;
    prop[0] = 1;
    prop[1] = 1;
    srand(time(NULL));
    for(i=2; i<N; i++){
        for(r=0; r<5; r++){
            var = rand()%soma_prop;
        }
        comp = 0;
        for(r=0; r<i; r++){
            comp += prop[r];
            if(var<comp){
                ligacoes[i][r] = 1;
                ligacoes[r][i] = 1;
                prop[i] += 1;
                prop[r] += 1;
                break;
            }
        }
        soma_prop += 2;
    }
}

void Rede_Aleatoria(){
    int cont=k*N;
    int i, j;

    srand(time(NULL));
    while (cont>0){
        i = rand()%N;
        j = rand()%N;
        if(i!=j){
            if(ligacoes[i][j]==0){
                ligacoes[i][j]=1;
                ligacoes[j][i]=1;
                cont--;
            }
        }
    }
}

void aleatoria(float p){
    int qt;//Variavel que controla a quantidade de neuronios que serao ativados
    int pos;//Variavel que "decide" qual neuronio sera ativado
    int passo, deslocar, joker;
    int local[N];

    for(passo=0; passo<N; passo++){
        local[passo] = passo;
    }

    qt = N*p;
    srand(time(NULL));
    for(passo=0; passo<qt; passo++){
        joker = rand()%(N-passo);
        pos = local[joker];
        vet[pos].I = 0.2;
        for(deslocar=joker; deslocar<(N-1); deslocar++){
            local[deslocar] = local[(deslocar+1)];
        }
    }
}

int graumax(){
    int i, pos, maior=0;
    pos = 0;
    maior = ligacoes[0][0];
    for(i=1; i<N; i++){
       if (maior < ligacoes[i][i]){
            maior = ligacoes[i][i];
            pos = i;
        }
    }
    return pos;
}

void guiada(float p){
    int i,j, pos, qt;
    
    qt = ceil(N*p);
    
    for(i=0;i<N;i++){
        ligacoes[i][i] = 0;
        for (j=0;j<N;j++)
            //Armazena a quantidade de ligacoes de cada neuronio
            ligacoes[i][i]+=ligacoes[i][j];
    }
    for(i=0.0;i<qt;i++){
        pos = graumax();
        //Ativa o neuronio na posicao de maior grau
        vet[pos].I = 0.02;
        ligacoes[pos][pos]=0.0;
    }
}

void OsciladorRelaxamento(){

    float t;
    int i, j;
    float dx = 0, dy = 0;

    //Arquivo para o grafico
    char impr_neuronio[] = "neuronio.txt";
    FILE *arq;
    //Abertura do arquivo
    arq = fopen(impr_neuronio, "w");

    if(arq == NULL){
        printf("Erro, nao foi possivel abrir o arquivo\n");
        return ;
    }

    for(t=0.00; t<tmax; t+=dt){
        for(i = 0; i<N; i++){//Atualiza o valor de acoplamento de cada neuronio
            vet[i].Si = 0;
            for(j = 0; j<N; j++){
                if(i!=j){
                    if(vet[j].x>0 && ligacoes[i][j] > 0){
                        vet[i].Si += w_ij;
                    }
                }
            }
        }

        for(i=0; i<N; i++){//escreve as variaveis no arquivo

            fprintf(arq,"%lf\t",vet[i].x);

            dx = (3*vet[i].x-pow(vet[i].x,3)+2-vet[i].y+vet[i].I+vet[i].Si)*dt;
            dy = (Epsilon*(Alpha*(1+tanh(vet[i].x/Beta)) - vet[i].y))*dt;
            vet[i].x += dx;
            vet[i].y += dy;
        }
	fprintf(arq,"%f\n",t);

    }
    fclose(arq);
}

void main(){
    int op = 0;
    float p;

    Inicializa();

    while(op <= 0 || op > 3){//Pergunta a rede a utilizar
        printf("\n\tEscolha uma topologia\n");
        printf("1 - Rede Regular\n");
        printf("2 - Rede Aleatoria\n");
        printf("3 - Rede Livre Escala\n");
        scanf("%d", &op);
    }

    switch(op){//Chama a rede escolhida
        case 1:
            Rede_Regular();
            break;
        case 2:
            Rede_Aleatoria();
            break;
        case 3:
            Rede_Livre_Escala();
            break;
    }
    op = 0;
    do{//Pergunta a sincronizacao
        printf("\n\tEscolha a sincronizacao\n");
        printf("1 - Selecao aleatoria\n");
        printf("2 - Selecao guiada\n");
        scanf("%d", &op);
    }while(op > 2 || op < 1);

    InicializaVet();

    do{//Pergunta para percentual ativo
        printf("\n\tInforme o percentual (0.01 a 1.00) de neuronios ativos para a sincronizacao\n");
        scanf("%f", &p);
    }while(p < 0.01 || p > 1.00);

    switch(op){
        case 1:
            aleatoria(p);
            break;
        case 2:
            guiada(p);
            break;
    }

    OsciladorRelaxamento();
}

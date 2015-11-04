//04.07.2015
//Projeto 5 Modelagem Computacional
//Integrantes: Alex Monteiro
//             Daniel Alves
//             Mariane Robl

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define N 1000
#define tmax 122
#define dt 1

typedef struct{
    char candidato;
    float resistencia;
} pessoa;

pessoa vet[N];

int ligacoes[N][N];

void Inicia_Matriz()
{
    int i, j;

    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            ligacoes[i][j] = 0;
        }
    }
}

void InicializaVet(){
    int i;

    for(i=0; i<N; i++){
        vet[i].candidato = 'N';
        vet[i].resistencia = ((rand()%11)/10.0);
    }
}

void Rede_Livre_Escala(gm)
{
    int i, r, var, comp, step;
    int prop[N];
    int soma_prop = 0;
    prop[0] = gm/2;
    for(i=(gm/2); i>0; i--)
    {
        prop[i] = gm/2;
        for(r=(i-1); r>=0; r--)
        {
            ligacoes[i][r] = 1;
            ligacoes[r][i] = 1;
            soma_prop += 2;
        }
    }
    srand(time(NULL));
    for(i=((gm/2)+1); i<N; i++)
    {
        step = 0;
        while(step<(gm/2))
        {
            for(r=0; r<5; r++)
            {
                var = rand()%soma_prop;
            }
            comp = 0;
            for(r=0; r<i; r++)
            {
                comp += prop[r];
                if(var<comp && ligacoes[i][r]==0)
                {
                    ligacoes[i][r] = 1;
                    ligacoes[r][i] = 1;
                    prop[i] += 1;
                    prop[r] += 1;
                    soma_prop += 2;
                    step += 1;
                    break;
                }
            }
        }
    }
}

void aleatoria(float p, char candidato){
    int qt;//Variavel que controla a quantidade de neuronios que serao ativados
    int pos;//Variavel que "decide" qual neuronio sera ativado
    int passo, deslocar, joker;
    int local[N];

    for(passo=0; passo<N; passo++){
        local[passo] = passo;
    }

    qt = ceil(N*p);
    srand(time(NULL));
    for(passo=0; passo<qt; passo++){
        joker = rand()%(N-passo);
        pos = local[joker];
        vet[pos].candidato = candidato;
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
    ligacoes[pos][pos] = -1;
    return pos;
}

int graumin(){
    int i, pos, menor=N;
    pos = 0;

    for(i=0; i<N; i++){
       if(ligacoes[i][i] != -1 && menor > ligacoes[i][i]){
            menor = ligacoes[i][i];
            pos = i;
        }
    }
    ligacoes[pos][pos] = -1;
    return pos;
}

void guiada(float p, int tipo, char candidato){
    int i,j, pos, qt;

    qt = ceil(N*p);

    for(i=0;i<N;i++){
        ligacoes[i][i] = 0;
        for (j=0;j<N;j++){
            //Armazena a quantidade de ligacoes de cada neuronio
            ligacoes[i][i]+=ligacoes[i][j];
        }
    }
    for(i=0;i<qt;i++){
        if(tipo == 2){
            pos = graumax();
        }
        else if(tipo == 3){
            pos = graumin();
        }
        if(vet[pos].candidato == 'N'){
            vet[pos].candidato = candidato;
        }
        else{
            i--;
        }
    }
}

void Segundo_Turno(char fora){
    int i,j, k, vizinhos, pessoas,l, escolha;
    float verifica, prob;
    char candidatos;
    float candidato, candidato_A, candidato_B, candidato_C, candidato_Nulo;
    float verifica_A, verifica_B, verifica_C, verifica_Nulo;
    pessoa vet1[N];

    for(j=0; j<N; j++)
    {
        vet1[j].candidato = vet[j].candidato;
    }
    //Arquivo para o grafico
    FILE *arq;
    FILE *arq_I;
    FILE *arq_II;
    FILE *arq_III;
    //Abertura do arquivo
    arq = fopen("A.txt", "a");
    arq_I = fopen("B.txt", "a");
    arq_II = fopen("C.txt", "a");
    arq_III = fopen("Nulo.txt", "a");

    if(arq == NULL || arq_I == NULL || arq_II == NULL || arq_III == NULL)
    {
        printf("Erro, nao foi possivel abrir o arquivo\n");
        return ;
    }

    for(i=tmax; i<(tmax+22); i+=dt){
        candidato = 0;
        for(l=0; l<N; l++){
            if(vet[l].candidato == 'A'){
                candidato++;
            }
        }
        fprintf(arq,"%d\t%f\n", i, (candidato));

        candidato = 0;
        for(l=0; l<N; l++){
            if(vet[l].candidato == 'B'){
                candidato++;
            }
        }
        fprintf(arq_I,"%d\t%f\n", i, (candidato));

        for(l=0; l<N; l++){
            if(vet[l].candidato == 'C'){
                candidato++;
            }
        }
        fprintf(arq_II,"%d\t%f\n", i, (candidato));

        candidato = 0;
        for(l=0; l<N; l++){
            if(vet[l].candidato == 'N'){
                candidato++;
            }
        }
        fprintf(arq_III,"%d\t%f\n", i, (candidato));

        for(j=0; j<N; j++)
        {
            candidato_A = 0;
            candidato_B = 0;
            candidato_C = 0;
            candidato_Nulo = 0;
            vizinhos = 0;

            for(k=0; k<N; k++){
                if(k!=j && ligacoes[j][k]){
                    if(vet[k].candidato == 'A'){
                        candidato_A++;
                    }
                    else if(vet[k].candidato == 'B'){
                        candidato_B++;
                    }
                    else if(vet[k].candidato == 'C'){
                        candidato_C++;
                    }
                    else{
                        candidato_Nulo++;
                    }
                    vizinhos++;
                }
            }

            verifica_A = (1 - vet[j].resistencia)*candidato_A;
            verifica_B = (1 - vet[j].resistencia)*candidato_B;
            verifica_C = (1 - vet[j].resistencia)*candidato_C;
            verifica_Nulo = (1 - vet[j].resistencia)*candidato_Nulo;
            escolha = rand()%3;
            prob = (((rand()%10)+1)/10.0);

            if(fora == 'C'){
                if(escolha == 0){
                    if(verifica_A >= prob){
                        vet1[j].candidato = 'A';
                    }
                }
                else if(escolha == 1){
                    if(verifica_B >= prob){
                        vet1[j].candidato = 'B';
                    }
                }
                else{
                    if(verifica_Nulo >= prob){
                        vet1[j].candidato = 'N';
                    }
                }
            }
            else if(fora == 'A'){
                if(escolha == 0){
                    if(verifica_C >= prob){
                            vet1[j].candidato = 'C';
                        }
                    }
                else if(escolha == 1){
                    if(verifica_B >= prob){
                        vet1[j].candidato = 'B';
                    }
                }
                else{
                    if(verifica_Nulo >= prob){
                        vet1[j].candidato = 'N';
                    }
                }
            }
            else{
                if(escolha == 0){
                    if(verifica_C >= prob){
                            vet1[j].candidato = 'C';
                        }
                    }
                else if(escolha == 1){
                    if(verifica_A >= prob){
                        vet1[j].candidato = 'A';
                    }
                }
                else{
                    if(verifica_Nulo >= prob){
                        vet1[j].candidato = 'N';
                    }
                }
            }
        }
    for(j=0; j<N; j++){
            vet[j].candidato = vet1[j].candidato;
    }
}
}
void Doenca(){
    int i,j, k, vizinhos, pessoas,l, escolha;
    float verifica, prob;
    char candidatos;
    float candidato, candidato_A, candidato_B, candidato_C, candidato_Nulo;
    float verifica_A, verifica_B, verifica_C, verifica_Nulo;
    pessoa vet1[N];

    for(j=0; j<N; j++)
    {
        vet1[j].candidato = vet[j].candidato;
    }

    //Arquivo para o grafico
    FILE *arq;
    FILE *arq_I;
    FILE *arq_II;
    FILE *arq_III;
    //Abertura do arquivo
    arq = fopen("A.txt", "w");
    arq_I = fopen("B.txt", "w");
    arq_II = fopen("C.txt", "w");
    arq_III = fopen("Nulo.txt", "w");

    if(arq == NULL || arq_I == NULL || arq_II == NULL || arq_III == NULL)
    {
        printf("Erro, nao foi possivel abrir o arquivo\n");
        return ;
    }

    for(i=0; i<tmax; i+=dt)
    {
        candidato = 0;
        for(l=0; l<N; l++){
            if(vet[l].candidato == 'A'){
                candidato++;
            }
        }
        fprintf(arq,"%d\t%f\n", i, (candidato));

        candidato = 0;
        for(l=0; l<N; l++){
            if(vet[l].candidato == 'B'){
                candidato++;
            }
        }
        fprintf(arq_I,"%d\t%f\n", i, (candidato));

        candidato = 0;
        for(l=0; l<N; l++){
            if(vet[l].candidato == 'C'){
                candidato++;
            }
        }
        fprintf(arq_II,"%d\t%f\n", i, (candidato));

        candidato = 0;
        for(l=0; l<N; l++){
            if(vet[l].candidato == 'N'){
                candidato++;
            }
        }
        fprintf(arq_III,"%d\t%f\n", i, (candidato));

        for(j=0; j<N; j++)
        {
            candidato_A = 0;
            candidato_B = 0;
            candidato_C = 0;
            candidato_Nulo = 0;
            vizinhos = 0;

            for(k=0; k<N; k++){
                if(k!=j && ligacoes[j][k]){
                    if(vet[k].candidato == 'A'){
                        candidato_A++;
                    }
                    else if(vet[k].candidato == 'B'){
                        candidato_B++;
                    }
                    else if(vet[k].candidato == 'C'){
                        candidato_C++;
                    }
                    else{
                        candidato_Nulo++;
                    }
                    vizinhos++;
                }
            }

            verifica_A = (1 - vet[j].resistencia)*candidato_A;
            verifica_B = (1 - vet[j].resistencia)*candidato_B;
            verifica_C = (1 - vet[j].resistencia)*candidato_C;
            verifica_Nulo = (1 - vet[j].resistencia)*candidato_Nulo;
            escolha = rand()%4;
            prob = (((rand()%10)+1)/10.0);

            if(escolha == 0){
                if(verifica_A >= prob){
                    vet1[j].candidato = 'A';
                }
            }
            else if(escolha == 1){
                if(verifica_B >= prob){
                    vet1[j].candidato = 'B';
                }
            }
            else if(escolha == 2){
                if(verifica_C >= prob){
                    vet1[j].candidato = 'C';
                }
            }
            else{
                if(verifica_Nulo >= prob){
                    vet1[j].candidato = 'N';
                }
            }
        }

        for(j=0; j<N; j++){
                vet[j].candidato = vet1[j].candidato;
        }
    }

    candidato_A = 0;
    candidato_B = 0;
    candidato_C = 0;
    candidato_Nulo = 0;
    
    for(i=0; i<N; i++){
        if(vet[i].candidato == 'A'){
            candidato_A++;
        }
        else if(vet[i].candidato == 'B'){
            candidato_B++;
        }
        else if(vet[i].candidato == 'C'){
            candidato_C++;
        }
    }
    float metade = (N/2) + 1;

    if(candidato_A <= metade && candidato_B <= metade && candidato_C <= metade){
        if(candidato_C<candidato_A && candidato_B > candidato_C){
            for(i=0; i<N; i++){
                if(vet[i].candidato == 'C'){
                    vet[i].candidato = 'N';
                }
            }
            Segundo_Turno('C');
        }
        else if(candidato_B<candidato_A && candidato_B<candidato_C){
            for(i=0; i<N; i++){
                if(vet[i].candidato == 'B'){
                    vet[i].candidato = 'N';
                }
            }
            Segundo_Turno('B');
        }
        else if(candidato_B>candidato_A && candidato_A<candidato_C){
            for(i=0; i<N; i++){
                if(vet[i].candidato == 'A'){
                    vet[i].candidato = 'N';
                }
            }
            Segundo_Turno('A');
        }
    }

    fclose(arq);
    fclose(arq_I);
    fclose(arq_II);
    fclose(arq_III);
}

void main(){
    int op = 4,tipo, i;
    float po;
    char candidato;
    float re = 1;
    srand(time(NULL));

    Inicia_Matriz();

    Rede_Livre_Escala(op);

    InicializaVet();

    for(i=0; i<3; i++){
        if(i==0){
            candidato = 'A';
        }
        else if(i == 1){
            candidato = 'B';
        }
        else{
            candidato = 'C';
        }
        printf("A porcentagem de pessoas que aderem ao candidato");
        printf(" %c: ", candidato);
        scanf("%f",&po);
        re -= po;
        while(re < 0 || po > 1 || po < 0){
            printf("Valor para a porcentagem invalido!! ");
            printf("Por favor digite novamente: ");
            scanf("%f",&po);
        }
        
        printf("Qual o tipo de forma que esse candidato ira ser ");
        printf("disseminado?\n");
        printf("1 - Para disseminar de forma aleatoria\n");
        printf("2 - Para disseminar pelas redes mais populares\n");
        printf("3 - Para disseminar pelas redes menos populares\n");
        scanf("%d",&tipo);
        while(tipo > 3 || tipo < 1){
            printf("Valor para o tipo invalido!! ");
            printf("Por favor digite novamente: ");
            scanf("%d",&tipo);
        }
        switch(tipo){
            case 1:
                aleatoria(po,candidato);
                break;
            case 2:
                guiada(po,tipo,candidato);
                break;
            case 3:
                guiada(po,tipo,candidato);
                break;
        }
    }

    Doenca();
}






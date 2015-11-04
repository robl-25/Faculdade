//22.05.2015
//Projeto 4 Modelagem Computacional
//Integrantes: Alex Monteiro
//             Daniel Alves
//             Mariane Robl

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define N 5000
#define tmax 365
#define dt 1

typedef struct
{
    int doenca;
    float resistencia;
    int tempo_doenca;
    int cont_doenca;
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

void InicializaVet()
{
    int i;

    for(i=0; i<N; i++)
    {
        vet[i].doenca = 0;
        vet[i].resistencia = ((rand()%11)/10.0);
        vet[i].tempo_doenca = ((rand()%(tmax-6))+7);
        vet[i].cont_doenca = 0;
    }
}

void Rede_Regular(int grau)
{
    int i, j;
    if (grau==2)
    {
        for(i=0; i<N; i++)
        {
            if(i == (N-1))
            {
                ligacoes[i][0] = 1;
                ligacoes[0][i] = 1;
            }
            else
            {
                ligacoes[i][i+1] = 1;
                ligacoes[i+1][i] = 1;
            }
        }
    }
    else if (grau==4)
    {
        for(i=0; i<N; i++)
        {
            if(i == (N-1))
            {
                ligacoes[i][0] = 1;
                ligacoes[0][i] = 1;
                ligacoes[i][1] = 1;
                ligacoes[1][i] = 1;
            }
            else
            {
                if (i==(N-2))
                {
                    ligacoes[i][i+1] = 1;
                    ligacoes[i+1][i] = 1;
                    ligacoes[i][0] = 1;
                    ligacoes[0][i] = 1;
                }
                else
                {
                    ligacoes[i][i+1] = 1;
                    ligacoes[i+1][i] = 1;
                    ligacoes[i][i+2] = 1;
                    ligacoes[i+2][i] = 1;
                }
            }
        }
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

void Rede_Aleatoria(int k)
{
    int cont=(k*N)/2;
    int i, j;

    while (cont>0)
    {
        i = rand()%N;
        j = rand()%N;
        if(i!=j)
        {
            if(ligacoes[i][j]==0)
            {
                ligacoes[i][j]=1;
                ligacoes[j][i]=1;
                cont--;
            }
        }
    }
}

void aleatoria(float p)
{
    int qt;//Variavel que controla a quantidade de neuronios que serao ativados
    int pos;//Variavel que "decide" qual neuronio sera ativado
    int passo, deslocar, joker;
    int local[N];

    for(passo=0; passo<N; passo++)
    {
        local[passo] = passo;
    }

    qt = N*p;
    srand(time(NULL));
    for(passo=0; passo<qt; passo++)
    {
        joker = rand()%(N-passo);
        pos = local[joker];
        vet[pos].doenca = 1;
        for(deslocar=joker; deslocar<(N-1); deslocar++)
        {
            local[deslocar] = local[(deslocar+1)];
        }
    }
}

void Doenca()
{
    int i,j, k;
    float verifica, prob;
    int doentes;
    pessoa vet1[N];

    for(j=0; j<N; j++)
    {
        vet1[j].doenca = vet[j].doenca;
        vet1[j].cont_doenca = vet[j].cont_doenca;
    }

    //Arquivo para o grafico
    char impr_doenca[] = "doenca.txt";
    FILE *arq;
    //Abertura do arquivo
    arq = fopen(impr_doenca, "w");

    if(arq == NULL)
    {
        printf("Erro, nao foi possivel abrir o arquivo\n");
        return ;
    }

    for(i=0; i<tmax; i+=dt)
    {
        doentes = 0;

        for(k=0; k<N; k++)
        {
            doentes+=vet[k].doenca;
        }

        fprintf(arq,"%d\t%d\n", i, (doentes));

        for(j=0; j<N; j++)
        {
            doentes = 0;
            if(vet[j].doenca == 1)
            {
                if(vet[j].cont_doenca == vet[j].tempo_doenca)
                {
                    vet1[j].doenca = 0;
                    vet1[j].cont_doenca = 0;
                }
                else
                {
                    vet1[j].cont_doenca++;
                }
            }
            else
            {
                for(k=0; k<N; k++)
                {
                    if(k!=j && ligacoes[j][k])
                    {
                        doentes += vet[k].doenca;
                    }
                }
                verifica = (1 - vet[j].resistencia)*doentes;
                prob = (((rand()%10)+1)/10.0);

                if(verifica >= prob)
                {
                    vet1[j].doenca = 1;
                }
            }
        }
        for(j=0; j<N; j++)
        {
            vet[j].doenca = vet1[j].doenca;
            vet[j].cont_doenca = vet1[j].cont_doenca;
        }
    }
    fclose(arq);
}

void main()
{
    int op;
    float po;
    int rede;
    srand(time(NULL));

    Inicia_Matriz();

    printf("\nDigite o grau medio (ele so pode ser 2 ou 4): ");
    scanf("%d",&op);
    while(op != 2 && op != 4)
    {
        printf("\nGrau medio invalido!! Digite novamente: ");
        scanf("%d",&op);
    }

    printf("\nEscolha o tipo de rede a ser utilizada:");
    printf("\n[1] Rede Regular");
    printf("\n[2] Rede Aleatoria");
    printf("\n[3] Rede Livre Escala\n");
    scanf("%d",&rede);
    while(rede < 1 || rede > 3)
    {
        printf("\nRede nao definida!! Digite novamente: ");
        printf("\n[1] Rede Regular");
        printf("\n[2] Rede Aleatoria");
        printf("\n[3] Rede Livre Escala\n");
        scanf("%d",&rede);
    }

    switch(rede)
    {
    case 1:
        Rede_Regular(op);
        break;
    case 2:
        Rede_Aleatoria(op);
        break;
    case 3:
        Rede_Livre_Escala(op);
        break;
    }

    InicializaVet();

    printf("\nDigite a porcentagem de contaminados");
    printf("\nLembre-se que este valor deve estar entre 0.0002 e 1\n");
    scanf("%f",&po);

    while(po < 0.0002 || po > 1)
    {
        printf("\nPorcentagem invalida!! Digite novamente: ");
        scanf("%f",&po);
    }

    aleatoria(po);
    Doenca();
}






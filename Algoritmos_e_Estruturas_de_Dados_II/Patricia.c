#include <stdio.h>
#include <stdlib.h>

typedef int TChave;

typedef struct {
    TChave Chave;
    /* outros compomentes */
} TItem;

typedef struct SNo *TArvBin;

typedef struct SNo {
    TItem Item;
    TArvBin Esq, Dir;
    int digito;
} TNo;

int retornaDigito(TChave x, int digito)
{
    return ((x >> digito) & 1);
}

/* Armazena informacao */
int EhInterno(TArvBin No)//No nao folha
{
    if(No->Esq != NULL || No->Dir != NULL)
        return 1;

    return 0;
}

/* Nao armazena informacao */
int EhExterno(TArvBin No)//No folha
{
    return !EhInterno(No);
}

TArvBin Inicializa()
{
    return NULL;
}

/* Cria um no Externo */
TArvBin CriaNoExt(TItem x){
    TArvBin aux = (TArvBin) malloc(sizeof(TNo));
    aux->Esq = NULL;
    aux->Dir = NULL;
    aux->Item = x;

    return aux;
}

/* Cria um no Interno */
TArvBin CriaNoInt(TArvBin Esq, TArvBin Dir, int digito){
    TArvBin aux = (TArvBin) malloc(sizeof(TNo));
    aux->Esq = Esq;
    aux->Dir = Dir;
    aux->digito = digito;

    return aux;
}

/* Retorna o digito que diferencia o No da chave a ser pesquisada/inserida*/
int DigitoSig(TChave No, TChave x){
    int digito = 0;

    while(retornaDigito(x, digito) == retornaDigito(No, digito))
        digito++;

    return digito;
}

/* Pesquisa se o No esta na arvore */
TArvBin Pesquisa(TArvBin Raiz, TChave x){
    TArvBin aux = Raiz;
    int digito;

    while(aux != NULL && EhInterno(aux) == 1){
    	digito = aux->digito;
        if(retornaDigito(x,digito) == 1)
            aux = aux->Dir;
        else
            aux = aux->Esq;
    }

    /* Verifica se chegou em um No vazia ou se a arvore ja eh vazia
       e se a chave do No eh diferente de x */
    if(aux == NULL || aux->Item.Chave != x)
        return NULL;

    else
        return aux;
}

int InsereI(TArvBin *raiz, TItem x, int digito){
    TArvBin Novo, No, pai = NULL, aux = *raiz;

    while(aux->digito < digito){
        pai = aux;

        if(retornaDigito(x.Chave,aux->digito) == 1)
        	aux = aux->Dir;
        else
            aux = aux->Esq;
    }

    if(pai == NULL){   		
        pai = CriaNoInt(NULL,NULL,digito);
        
        if(retornaDigito(x.Chave,digito) == 1){
            pai->Esq = aux;
            pai->Dir = CriaNoExt(x);
        }
        
        else{
            pai->Dir = aux;
            pai->Esq = CriaNoExt(x);
        }
        
        *raiz = pai;
    }

    else{
        Novo = CriaNoExt(x);

        if(retornaDigito(Novo->Item.Chave,digito) == 1){
            No = CriaNoInt(aux, Novo, digito);
            if(retornaDigito(Novo->Item.Chave,pai->digito) == 1)
                pai->Dir = No;
            else
                pai->Esq = No;
        }

        else{
            No = CriaNoInt(Novo, aux, digito);
            if(retornaDigito(aux->Item.Chave,pai->digito) == 1)
                pai->Dir = No;
            else
                pai->Esq = No;
        }
    }
    return 1;
}

int Insere(TArvBin *pRaiz, TItem x)
{
    if((*pRaiz) == NULL){
        (*pRaiz) = CriaNoExt(x);
        return 1;
    }

    else{
        TArvBin aux = (*pRaiz), pai = NULL;
        int digito;

        while(aux != NULL && EhInterno(aux) == 1){
        	pai = aux;
            if(retornaDigito(x.Chave,aux->digito) == 1)
                aux = aux->Dir;
            else
                aux = aux->Esq;
        }

        if(aux->Item.Chave == x.Chave)
            return 0;

        digito = DigitoSig(aux->Item.Chave, x.Chave);

        if(pai != NULL){
            if(pai->digito < digito){
                TArvBin No = CriaNoInt(NULL,NULL,digito);
                if(retornaDigito(x.Chave,digito) == 0){
                        No->Dir = aux;
                        No->Esq = CriaNoExt(x);
                }
                else{
                    No->Esq = aux;
                    No->Dir = CriaNoExt(x);
                }

                if(retornaDigito(aux->Item.Chave,pai->digito) == 1)
                    pai->Dir = No;

                else
                    pai->Esq = No;
            }
            else
                return InsereI(pRaiz,x,digito);
        }
        else{
            pai = CriaNoInt(NULL,NULL,digito);
            if(retornaDigito(x.Chave,digito) == 1){
                pai->Esq = aux;
                pai->Dir = CriaNoExt(x);
            }
            else{
                pai->Dir = aux;
                pai->Esq = CriaNoExt(x);
            }
            (*pRaiz) = pai;
        }
        return 1;
    }
}

void Carrega(TArvBin *pNo)
{
    int i, n;
    TItem x;

    scanf("%d", &n);
    for (i = 0; i < n ; i++) {
        scanf("%d", &x.Chave);
        Insere(pNo, x);
    }
}

void Libera(TArvBin *pNo)
{
    TArvBin No;

    No = *pNo;
    if (No != NULL) {
        Libera(&No->Esq);
        Libera(&No->Dir);
        free(No);
        (*pNo) = NULL;
    }
}

void Imprime(TArvBin No)
{
    if (No != NULL) {
        printf("(");
        if (EhExterno(No))
            printf("C%d", No->Item.Chave);
        else
            printf("D%d", No->digito);
        Imprime(No->Esq);
        Imprime(No->Dir);
        printf(")");
    }
    else
        printf("()");
}

int main()
{
    TArvBin Raiz;
    TItem x;

    Raiz = Inicializa();
    Carrega(&Raiz);
    scanf("%d", &x.Chave);
    if (Pesquisa(Raiz, x.Chave) == NULL)
        Insere(&Raiz, x);
    Imprime(Raiz);
    Libera(&Raiz);

    return 0;
}

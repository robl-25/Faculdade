#include <stdio.h>
#include <stdlib.h>

#define M 2
#define MM (2 * M)

typedef int TChave;

typedef struct {
	TChave Chave;
	/* outros compomentes */
} TItem; 

typedef int TIndice;

typedef struct SNo *TArvoreB;

typedef struct SNo {
	TItem Item[MM];
	TArvoreB Pagina[MM + 1];
	TIndice n;
} TNo;

int EhInterno(TArvoreB No)
{
	return (No != NULL) && (No->Pagina[0] != NULL);
}

int EhExterno(TArvoreB No)
{
	return (No != NULL) && (No->Pagina[0] == NULL);
}

TArvoreB Inicializa()
{
	return NULL;
}

TArvoreB Pesquisa(TArvoreB Raiz, TChave x)
{
	if(Raiz == NULL)
	    return NULL;
	    
	else{
	    int i;
	    for(i=0; i<Raiz->n && (Raiz->Item[i].Chave > x); i++)
	        if(Raiz->Item[i].Chave == x)
	            return Raiz;
	    
	    return Pesquisa(Raiz->Pagina[i],x);
	}
}

TArvoreB CriaNo(TItem x){
    TArvoreB aux = (TArvoreB)malloc(sizeof(TNo));
    aux->Item[0] = x;
    aux->Pagina[0] = NULL;
    aux->n = 1;
    return aux;
}

void InsereNo(TArvoreB No, TArvoreB info, int i){
    int cont;
    
    for(cont = No->n; cont>i; cont--){
        No->Item[(cont)] = No->Item[cont-1];
        No->Pagina[cont] = No->Pagina[cont-1];
    }
    
    No->n++;
    No->Item[i] = info->Item[0];
    No->Pagina[i] = info->Pagina[0];
}

void Divide(TArvoreB No, TArvoreB info, int i){
     TArvoreB Novo;
     int cont;
       
     Novo = (TArvoreB)malloc(sizeof(TNo));
           
     for(cont=M; cont<(No)->n; cont++){
         Novo->Item[cont-M] = (No)->Item[cont];
         Novo->Pagina[cont-M] = (No)->Pagina[cont];
         (No)->Pagina[cont] = NULL;
          Novo->n++;
     }
     No->n -= Novo->n;
     
     if(Novo->Item[0].Chave > info->Item[0].Chave){
        InsereNo(No,info,i);
        info->Item[0] = No->Item[No->n];
        No->n--;
     }
     
     else{
        InsereNo(Novo,info,i);
        info->Item[0] = Novo->Item[0];
        for(cont = 0; cont<Novo->n; cont++){
            Novo->Item[(cont)] = Novo->Item[cont+1];
            Novo->Pagina[cont] = Novo->Pagina[cont+1];
        }
                
        Novo->n--;
     }
     info->Pagina[0] = Novo;
}

int InsereRec(TArvoreB No, TItem x, TArvoreB *info){
    if(No == NULL){
        (*info) = CriaNo(x);
        return 1;
    }
    
    else{
	    int i;
	    for(i=0; i<No->n && (No->Item[i].Chave < x.Chave); i++);
	    
	    if(No->Item[i].Chave == x.Chave)
	            return 0;
	            
	    if(InsereRec(No->Pagina[i],x,info) == 1){
	        if(No->n < MM){
	            InsereNo(No,*info,i);
	            return 0;
	        }
	        
	        else{
	            Divide(No,*info,i);
	            return 1;
	        }
	    }
	}
}

void Insere(TArvoreB *pRaiz, TItem x)
{
	TArvoreB *info, No;
	
	if(*pRaiz == NULL){
	    *pRaiz = CriaNo(x);
	    return;
	}
	
	else if(InsereRec(*pRaiz,x,info) == 1){
	    No = CriaNo((*info)->Item[0]);
	    No->Pagina[0] = *pRaiz;
	    No->Pagina[1] = *info;
	    *pRaiz = No;
	}
}

void Imprime(TArvoreB No);

void Carrega(TArvoreB *pNo)
{
	int i, n;
	TItem x; 
	
	scanf("%d", &n);
	for (i = 0; i < n ; i++) {
		scanf("%d", &x.Chave);
		Insere(pNo, x);
		Imprime(*pNo);
	}
}

void Libera(TArvoreB *pNo)
{
	TArvoreB No;
	TIndice i;
	
	No = *pNo;
	if (No != NULL) {
		for (i = 0; i <= No->n; i++)
			Libera(&No->Pagina[i]);
		free(No);
		(*pNo) = NULL;
	}
}

void Imprime(TArvoreB No)
{
	TIndice i;
	
	if (No != NULL) {
		printf("(");
		for (i = 0; i < No->n; i++) {
			Imprime(No->Pagina[i]);
			printf("C%d", No->Item[i].Chave);
		}
		Imprime(No->Pagina[No->n]);
		printf(")");
	}
	else
		printf("()");
}

int main()
{
	TArvoreB Raiz;
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

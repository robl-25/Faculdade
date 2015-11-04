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
TArvBin CriaNoInt(TArvBin Esq, TArvBin Dir){
	TArvBin aux = (TArvBin) malloc(sizeof(TNo));
	aux->Esq = Esq;
	aux->Dir = Dir;
	
	return aux;
}

TArvBin PesquisaRecursivo(TArvBin No, TChave x, int digito)
{
	/* Arvore vazia */
	if(No == NULL)
		return NULL;
		
	/* Enquanto for um no interno */	
	if(EhInterno(No)){
		if(retornaDigito(x, digito) == 1)
			return PesquisaRecursivo(No->Dir, x, digito + 1);
		else
			return PesquisaRecursivo(No->Esq, x, digito + 1);
	}
	
	/* Quanto for um no externo */
	if(EhExterno(No)){
		if(No->Item.Chave == x)
			return No;
		else
			return NULL;
	}
}
TArvBin Pesquisa(TArvBin Raiz, TChave x){

	return PesquisaRecursivo(Raiz, x, 0);
}

int Separa(TArvBin *pNo, TItem x, int digito){

	TArvBin No = *pNo;
	*pNo = (TArvBin) malloc(sizeof(TNo));
	
		/* Caso o digito do No a ser movido seja 0*/
		if(retornaDigito(No->Item.Chave, digito) == 0){
			(*pNo) = CriaNoInt(No, NULL);
		
			/* Caso o no do elemento a ser inserido seja 0 */
			if(retornaDigito(x.Chave, digito) == 0)
				return Separa(&(*pNo)->Esq, x, digito + 1);
			
			/* Caso o no do elemento a ser inserido seja 1 */
			else{
				(*pNo)->Dir = CriaNoExt(x);
				return 1;
			}
		}
	
		/* Caso o digito do No a ser movido seja 1*/
		else{
			(*pNo) = CriaNoInt(NULL, No);
		
			/* Caso o no do elemento a ser inserido seja 1 */
			if(retornaDigito(x.Chave, digito) == 1)
				return Separa(&(*pNo)->Dir, x, digito + 1);
			
			/* Caso o no do elemento a ser inserido seja 0 */
			else{
				(*pNo)->Esq = CriaNoExt(x);
				return 1;
			}
		}
}

int InsereRecursivo(TArvBin *No, TItem x, int digito)
{
	/* Caso a arvore seja vazia */
	if(*No == NULL){
		*No = CriaNoExt(x);
		return 1;
	}
		
	/* Enquanto for um no interno */
	if(EhInterno(*No)){
		if(retornaDigito(x.Chave,digito) == 1 )
			return InsereRecursivo(&(*No)->Dir, x, digito + 1);
		else
			return InsereRecursivo(&(*No)->Esq, x, digito + 1);
	}
	
	/* Quanto for um no externo */
	else if(EhExterno(*No))
		return Separa(No, x, digito);
	
}

int Insere(TArvBin *pRaiz, TItem x)
{
	if(Pesquisa((*pRaiz), x.Chave))
		return 0;

	return InsereRecursivo(pRaiz, x, 0);
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

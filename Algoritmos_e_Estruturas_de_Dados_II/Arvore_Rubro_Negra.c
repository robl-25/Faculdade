
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
	int cor;
} TNo;

int EhNegro(TArvBin No)
{
	if((No == NULL) || (No->cor == 0))
		return 1;
	else
		return 0;
}

int EhRubro(TArvBin No)
{
    return !EhNegro(No);
}

int AlturaNegra(TArvBin No)
{
	int hEsq, hDir;

	if (No == NULL)
        return 0;

    hEsq = AlturaNegra(No->Esq);
    hDir = AlturaNegra(No->Dir);

	if (hEsq > hDir) 
		return hEsq + EhNegro(No); 

	else 
		return hDir + EhNegro(No);
}

int ArvoreARN(TArvBin No)
{   // retorna 1 se for ou 0 se não for
	if (No == NULL)
        return 1;
    if (!ArvoreARN(No->Esq))
        return 0;
    if (!ArvoreARN(No->Dir))
        return 0;
	if(EhRubro(No) && (!EhNegro(No->Esq) || !EhNegro(No->Dir)))
		return 0;
	if (AlturaNegra(No->Esq) != AlturaNegra(No->Dir))
		return 0;
	return 1;
}

void InverteCor(TArvBin No)
{
    if (No != NULL) 
		No->cor = !No->cor;
}

void TrocaCores(TArvBin No)
{
	InverteCor(No);
	InverteCor(No->Esq);
	InverteCor(No->Dir);
}

void RotacaoDireita(TArvBin *pA)
{
	TArvBin pB;

	pB = (*pA)->Esq;
	(*pA)->Esq = pB->Dir;
	pB->Dir = (*pA);
	(*pA) = pB;
}

void RotacaoEsquerda(TArvBin *pA)
{
	TArvBin pB;

	pB = (*pA)->Dir;
	(*pA)->Dir = pB->Esq;
	pB->Esq = (*pA);
	(*pA) = pB;
}

void BalancaEsq(TArvBin *pA, TArvBin *pB, TArvBin *pC)
{
	if(EhRubro((*pC)->Dir))
		TrocaCores(*pC);
	else
	{
		if(*pB == (*pA)->Dir)
			RotacaoEsquerda(pA);
		InverteCor(*pA);
		InverteCor(*pC);
		RotacaoDireita(pC);
	}
}

void BalancaDir(TArvBin *pA, TArvBin *pB, TArvBin *pC)
{
	if(EhRubro((*pC)->Esq))
		TrocaCores(*pC);
	else
	{
		if(*pB == (*pA)->Esq)
			RotacaoDireita(pA);
		InverteCor(*pA);
		InverteCor(*pC);
		RotacaoEsquerda(pC);
	}
}

void BalancaNo(TArvBin *pA, TArvBin *pB, TArvBin *pC)
{
	if((pC != NULL) && EhRubro(*pA) && EhRubro(*pB))
	{
		if(*pA == (*pC)->Esq)
			BalancaEsq(pA,pB,pC);
		else
			BalancaDir(pA,pB,pC);
	}
}

TArvBin Inicializa()
{
	return NULL;
}

void InsereR(TArvBin *pA, TArvBin *pC, TItem x)
{
	if(*pA == NULL)
	{
		*pA = (TArvBin)malloc(sizeof(TNo));
		(*pA)->Item = x;
		(*pA)->cor = 1;
	}
	else
	{
		if(x.Chave < (*pA)->Item.Chave)
		{
			InsereR(&(*pA)->Esq,pA,x);
			BalancaNo(pA, &(*pA)->Esq, pC);
		}
		else if (x.Chave > (*pA)->Item.Chave)
		{
			InsereR(&(*pA)->Dir, pA, x);
        	BalancaNo(pA, &(*pA)->Dir, pC); //pai, filho, avo
		}
	}
}

void Insere(TArvBin *pRaiz, TItem x)
{
	InsereR(pRaiz,NULL,x);
	(*pRaiz)->cor = 0;
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
		if (EhNegro(No))
			printf("(N%d", No->Item.Chave);
		else
			printf("(R%d", No->Item.Chave);
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
	if (ArvoreARN(Raiz)) {
		printf("%d\n", AlturaNegra(Raiz));
		Imprime(Raiz);
	}
	Libera(&Raiz);

	return 0;
}

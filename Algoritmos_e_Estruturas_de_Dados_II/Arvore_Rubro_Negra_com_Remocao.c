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
	int cor;//0 = preto e 1 = rubro
} TNo;

int EhNegro(TArvBin No)
{
	if((No == NULL) || (No->cor == 0))
		return 1;
	else
		return 0;
}

void InverteCor(TArvBin No)
{
    if (No != NULL) 
	No->cor = !No->cor;
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

int BalancaDir(TArvBin *pA)
{
	if(!EhNegro((*pA)->Dir))//Caso 4 (Filho Direito rubro)
		RotacaoEsquerda(pA);
	
	/*if((*pA)->Dir == NULL)
		return 1;*/

	else if((*pA)->Dir != NULL)
	{
		if(EhNegro((*pA)->Dir->Dir) && EhNegro((*pA)->Dir->Esq))
//Caso 1 (Filho Direito preto, neto Direito preto e Neto esquerdo preto))
		{
			InverteCor((*pA)->Dir);
			if(EhNegro(*pA))
				return 1;
			else
				InverteCor(*pA);
		}
		else
		{
			if(EhNegro((*pA)->Dir->Dir) && !EhNegro((*pA)->Dir->Esq))
//Caso 2 (Filho Direito preto, neto Direito preto e Neto esquerdo rubro)
			{
				RotacaoDireita(&(*pA)->Dir);
				InverteCor((*pA)->Dir);
				InverteCor((*pA)->Dir->Dir);
			}
			//Caso 3 (Filho Direito preto, neto Direito rubro)
			int i;
			i = (*pA)->cor;
			RotacaoEsquerda(pA);
			(*pA)->Esq->cor = 0;
			(*pA)->cor = i;
			(*pA)->Dir->cor = 0;
			
		}
	}
	return 0;
}

int BalancaEsq(TArvBin *pA)
{
	if(!EhNegro((*pA)->Esq))
		RotacaoDireita(pA);
	
	/*if((*pA)->Esq == NULL)
		return 1;*/

	if((*pA)->Esq != NULL)
	{
		if(EhNegro((*pA)->Esq->Esq) && EhNegro((*pA)->Esq->Dir))
		{
			InverteCor((*pA)->Esq);
			if(EhNegro(*pA))
				return 1;
			else
				InverteCor(*pA);
		}
		else
		{
			if(EhNegro((*pA)->Esq->Esq) && !EhNegro((*pA)->Esq->Dir))
			{
				RotacaoEsquerda(&(*pA)->Esq);
				InverteCor((*pA)->Esq);
				InverteCor((*pA)->Esq->Esq);
			}
			
			int i;
			i = (*pA)->cor;
			RotacaoDireita(pA);
			(*pA)->Dir->cor = 0;
			(*pA)->cor = i;
			(*pA)->Esq->cor = 0;
			
		}
	}
	return 0;
}

int Sucessor(TArvBin *q, TArvBin *r)
{
	if((*r)->Esq != NULL)
	{
		if(Sucessor(q, &(*r)->Esq) == 1)
			return BalancaDir(r);
		return 0;
	}
	
	else
	{		
		(*q)->Item = (*r)->Item;
		*q = *r;
		*r = (*r)->Dir;
		if(EhNegro(*q))
		{
			if(EhNegro(*r))
				return 1;
			else
				InverteCor(*r);
		}

		return 0;
	}
}

int RemoveR(TArvBin *p, TChave x)
{
	TArvBin q;
	
	if(*p == NULL)
		return 0;
	else if (x < (*p)->Item.Chave)
	{
		if(RemoveR(&(*p)->Esq, x) == 1)
			return BalancaDir(p);
		return 0;
	}
	else if (x > (*p)->Item.Chave)
	{
		if(RemoveR(&(*p)->Dir, x) == 1)
			return BalancaEsq(p);
		return 0;
	}

	else
	{
		int ret = 0;
		q = *p;

		if(q->Esq == NULL)
		{
			*p = q->Dir;
			if(EhNegro(q))
			{
				if((*p) != NULL)
					{
					if(EhNegro(*p))
						ret = 1;
					else
						InverteCor(*p);
					}
				else
					ret = 1;
			}
		}

		else if(q->Dir == NULL)
		{
			*p = q->Esq;
			if(EhNegro(q))
			{
				if(EhNegro(*p))
					ret = 1;
				else
					InverteCor(*p);
			}
		}
			
		else if(Sucessor(&(q), &(q->Dir)) == 1)
				ret = BalancaEsq(p);

		free(q);
		return ret;
	}
}

void Remove(TArvBin *No, TChave x)
{
	RemoveR(No,x);
	if(!EhNegro(*No))
		InverteCor(*No);
}

TArvBin Carrega()
{
	char c;
	TArvBin No;
	scanf("%c", &c);
	if (c == '(') {
		scanf("%c", &c);
		if ((c == 'N') || (c == 'R')) {
			No = (TArvBin) malloc(sizeof(TNo));
			scanf("%d", &No->Item.Chave);
			No->Esq = Carrega();
			No->Dir = Carrega();
			No->cor = (c == 'R');
			scanf("%c", &c);
		}
		else if (c == ')')
			No = NULL;
	}
	return No;
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

	Raiz = Carrega();
	scanf("%d", &x.Chave);
	Remove(&Raiz, x.Chave);
	Imprime(Raiz);
	Libera(&Raiz);
		
	return 0;
}

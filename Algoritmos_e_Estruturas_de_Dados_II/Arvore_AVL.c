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
    int fb; // fator de balanceamento: -1, 0, +1
} TNo;

int FB(TArvBin No)
{
    if (No == NULL)
        return 0;

return No->fb;
}

void LL(TArvBin *pA) // arrumar pra remocao
{
TArvBin pB;

       pB = (*pA)->Esq;
       (*pA)->Esq = pB->Dir;
       pB->Dir= *pA;
       /*(*pA)->fb=0;
       pB->fb=0;*/
       if(pB->fb == 0){
           (*pA)->fb =1;
            pB->fb=-1;}
       else{
            (*pA)->fb =0;
            pB->fb=0;}

       *pA=pB;


}

void RR(TArvBin *pA) // arrumar pra remocao
{
TArvBin pB;

       pB=(*pA)->Dir;
       (*pA)->Dir=pB->Esq;
       pB->Esq= *pA;
       /*(*pA)->fb=0;
       pB->fb=0;*/

       if(pB->fb == 0){
           (*pA)->fb =-1;
            pB->fb=1;}
       else{
            (*pA)->fb =0;
            pB->fb=0;}

       *pA=pB;
}

void LR(TArvBin *pA)
{
 TArvBin pB,pC;

       pB = (*pA)->Esq;
       pC= pB->Dir;
       pB->Dir= pC->Esq;
       pC->Esq=pB;
       (*pA)->Esq=pC->Dir;
       pC->Dir= *pA;

       if(pC->fb == 1)
            (*pA)->fb= -1;
       else
            (*pA)->fb= 0;

       if(pC->fb == -1)
            pB->fb= +1;
       else
            pB->fb=0;

       pC->fb=0;
       *pA=pC;

}

void RL(TArvBin *pA)
{
TArvBin pB,pC;

       pB = (*pA)->Dir;
       pC= pB->Esq;
       pB->Esq= pC->Dir;
       pC->Dir=pB;
       (*pA)->Dir=pC->Esq;
       pC->Esq= *pA;

       if(pC->fb == -1)
            (*pA)->fb= 1;
       else
            (*pA)->fb=0;

       if(pC->fb == 1)
            pB->fb=-1;
       else
            pB->fb=0;

        pC->fb=0;
       *pA=pC;

}

int BalancaEsquerda(TArvBin *pNo)
{
int fbe = FB((*pNo)->Esq);

    if(fbe > 0){
        LL(pNo);
        return 1;
    }
    else if (fbe < 0){
        LR(pNo);
        return 1;
    }
    else{
    LL(pNo);
    return 0;
    }
}

int BalancaDireita(TArvBin *pNo)
{
int fbd = FB((*pNo)->Dir);

    if(fbd < 0){
        RR(pNo);
        return 1;
    }
    else if (fbd > 0){
        RL(pNo);
        return 1;
    }
    else{
    RR(pNo);
    return 0;
    }


}

int BalancaNo(TArvBin *pNo)
{
   int fb = FB(*pNo);

       if(fb>1)
           return BalancaEsquerda(pNo);
       else if (fb < -1)
           return BalancaDireita(pNo);

       return 0;
}



TArvBin Inicializa()
{
return NULL;
}

TArvBin Pesquisa(TArvBin No, TChave x)
{
    if (No == NULL)
        return NULL; // retorna NULL caso a chave nao seja encontrada
    else if (x < No->Item.Chave)
        return Pesquisa(No->Esq, x);
    else if (x > No->Item.Chave)
        return Pesquisa(No->Dir, x);
    else
        return No;
}



int Insere(TArvBin *pNo, TItem x) //arrumar o case
{
    if(*pNo == NULL){
        *pNo = (TArvBin) malloc(sizeof(TNo));
        (*pNo)->Item = x;
        (*pNo)->Esq = NULL;
        (*pNo)->Dir = NULL;
        (*pNo)->fb = 0;
    return 1;
    }
    else if (x.Chave < ((*pNo)->Item.Chave)){
    if( Insere(&(*pNo)->Esq, x)){ //&& !BalancaNo(pNo);
               switch ((*pNo)->fb){
                   case -1: (*pNo)->fb= 0; return 0;//break;
                   case 0: (*pNo)->fb= +1; return 1;//break;
                   case 1: return !BalancaEsquerda(pNo); }
    return 0;
    }}


    else if (x.Chave > ((*pNo)->Item.Chave)){
    if( Insere(&(*pNo)->Dir, x)){ //&& !BalancaNo(pNo);
               switch ((*pNo)->fb){
                   case 1: (*pNo)->fb= 0; return 0;//break;
                   case 0: (*pNo)->fb= -1; return 1;//break;
                   case -1: return !BalancaDireita(pNo);}

    return 0;
    }}

    else
        return 0;
}








int Remove(TArvBin *p, TChave x)
{
    TArvBin q;
    int ret;

           if(*p == NULL)
               return 0;

           else if(x<(*p)->Item.Chave){
               if(Remove(&(*p)->Esq,x)){
                  switch ((*p)->fb){
                       case 1: (*p)->fb=0; return 1;//break;
                       case 0: (*p)->fb=-1; return 0;//break;
                       case -1: return BalancaDireita(p);
                  }
            return 0;
            }}

           else if(x>(*p)->Item.Chave){

               if(Remove(&(*p)->Dir,x)){
                  switch ((*p)->fb){
                   case -1: (*p)->fb=0; return 1;//break;
                   case 0 :  (*p)->fb=1;return 0;//break;
                   case 1: return BalancaEsquerda(p);}

               return 0;
               }}



           else{

                   q= *p;
                   if(q->Esq == NULL){
                       *p=q->Dir;
                       ret=1;}

                   else if(q->Dir==NULL){
                       *p=q->Esq;
                       ret=1;}

                   else{

                       if(Sucessor(&q, &q->Dir)){
                          switch ((*p)->fb){
                               case -1: (*p)->fb=0; ret =1; //break;
                               case 0 :  (*p)->fb=1; ret =0; //break;
                               case 1 : ret = BalancaEsquerda(p);
                          }
                       }
                       else ret=0;
                   }
                   free(q);
                   return ret;
           }

    }

int Sucessor(TArvBin *q,TArvBin *r){

   if((*r)->Esq != NULL){

       if(Sucessor(q, &(*r)->Esq)){
              switch ((*r)->fb){ // subarv da esq encolheu
                case 1: (*r)->fb=0; return 1;
                case 0: (*r)->fb=-1; return 0;
                case -1: return !BalancaDireita(r);
              }
        return 0;
       }}

    else{
           (*q)->Item = (*r)->Item;
           (*q)= *r;
           (*r) = (*r)->Dir;
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
printf("(C%d", No->Item.Chave);
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
else
Remove(&Raiz, x.Chave);
Imprime(Raiz);
Libera(&Raiz);

return 0;
}

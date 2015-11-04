#include <stdio.h>
#include <stdlib.h>

int main()
{
    char materia[3];
    printf("Escreva as tres primeiras letras da materia: ");
    scanf ("%s",materia);
    int p1, p2, p3, mf;
    printf("\nEscreva a nota da p1: ");
    scanf("%i",&p1);
    printf("\nEscreva a nota da p2: ");
    scanf("%i",&p2);
    printf("\nEscreva a nota da p3: ");
    scanf("%i",&p3);
    if (strcmp(materia,"mat")==0){
       mf=(p1+p2+p3)/3;
       printf("\n%i",mf);
       if (mf>=7)
       printf("\naprovado\n");
    else
       printf("\nreprovado\n");
    }

    else if (strcmp(materia,"por")==0){
       mf=0.2*p1+0.3*p2+0.5*p3;
       printf("\n%i",mf);
       if (mf>=7)
       printf("\naprovado\n");
    else
       printf("\nreprovado\n");
    }

    else if (strcmp(materia,"his")==0){
       mf=0.25*p1+0.3*p2+0.45*p3;
       printf("\n%i",mf);
       if (mf>=7)
       printf("\naprovado\n");
       else if (mf<7)
       printf("\nreprovado\n");
    }

    else
       printf("\nnao existe materia\n");
    return 0;
}

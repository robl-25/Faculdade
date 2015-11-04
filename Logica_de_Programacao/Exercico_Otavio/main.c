#include <stdio.h>
#include <stdlib.h>

int main()
{
    float n, x, cosx=1, fat=1, ter=1;
    int cont1, k=1;
    printf("\nEscreva o numero de termos a ser calculado: ");
    scanf("%f", &n);
    printf("\nEscreva o valor do termo a ser calculado: ");
    scanf("%f", &x);
    for (cont1=2; k<n; cont1=cont1+2)
    {
        ter=(-1)*ter*x*x;
        fat=fat*cont1*(cont1-1);
        cosx=cosx+(ter/fat);
        k++;
    }

    printf("\nO resultado de cosx eh: %f\n", cosx);

    printf("\nPressione enter para finalizar o programa\n");

    getch();

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,i,j;
    float b;
    printf("escreva um numero: ");
    scanf("%d", &i);
    printf("\nEscreva a potencia do numero:  ");
    scanf("%d", &j);
    a=0;
    b=1;
    if (j==0)
    {
        b=1;
    }
    else if(j>0)
    {
        while(a<j)
        {
            a=a+1;
            b=b*i;
        }
    }
    else
    {
        j=j*-1;
        while(a<j)
        {
            a=a+1;
            b=b*i;
        }
        b=1/b;
    }

    printf ("\nO resultado é:  %f\n", b );

    return 0;

}

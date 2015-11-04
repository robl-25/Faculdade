#include <stdio.h>
#include <stdlib.h>

int soma (int a, int b)
{
    int so;

    so=a+b;

    printf ("%i", so);

    return so;
}

int sub (int a, int b)
{
    int su;

    su= a-b;

    printf ("%i", su);

    return su;
}

int mul (int a, int b)
{
    int m;

    m=a*b;

    printf ("%i", m);

    return m;
}

float div (int a, int b)
{
    float d;

    d = a/b;

    printf ("%f", d);

    return d;
}

int main ()
{
    int a,b;

    printf ("\nEscreva dois números inteiros e maiores que zero: ");
    scanf ("%i %i", &a, &b);

    soma(a,b);
    su(a,b);
    mul(a,b);
    div(a,b);

    return 0;
}

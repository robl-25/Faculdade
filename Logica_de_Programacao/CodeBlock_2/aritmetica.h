#include <stdio.h>

int soma (int a, int b)
{
    return a+b;
}

float media (int v[1000], int n)
{
    float m=0;
    int i;

    for (i=0; i<n; i++)
    {
        m += v[i];
    }

    m = m/n;

    return m;
}

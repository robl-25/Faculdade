#include <stdio.h>
#include <stdlib.h>

char c (char v1[10], char v2[10], int n)
{
    int i, b=0;
    for (i=0; i<n || b==0; i++)
    {
        if (v1[i] != v2[i])
            b=1;
    }
    return b;
}

int cont (int n)
{

}

void main ()
{
    char v1[10], v2[10];
    int i;
    printf ("Escreva os elementos do primeiro vetor de caracteres:\n");
    scanf ("%s", v1);

    for (i=0; )

}

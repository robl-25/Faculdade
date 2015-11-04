#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void removeEsquerda (char a[])
{
    int j, b;
    for (j=0; j<100; j++)
    {
        if (a[j] == '\n')
            break;

        if (a[j] == ' ')
        {
            for (b=j; b<100; b++)
            {
                if (a[b] == '\n')
                    break;
                a[b]=a[b+1];
            }
        }
    }
}

void main ()
{
    char s[100];
    int i;

    printf ("Escreva uma frase: ");
    for (i=0; i<100; i++)
    {
        scanf ("%c", &s[i]);
        if (s[i] == '\n')
            break;
    }

    //scanf("%s", s);

    removeEsquerda(s);

    for (i=0; i<100; i++)
    {
        printf ("%c", s[i]);
    }
}

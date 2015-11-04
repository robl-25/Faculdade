#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inverte(char a[])
{
     int b, i;

     i=strlen(a);

     for (b=i; b>-1; b--)
    {
        printf ("%c", a[b]);
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

    inverte(s);
}

#include <stdio.h>
#include <string.h>

void conta(char c, char str[], int a)
{
    int j, cont=0;

    for (j=0; j<=a; j++)
    {
        if (str[j] == c)
            cont++;
    }
    printf ("O numero de vezes que esse caracater aparece é %d vezes", cont);
}

void main ()
{
    char s[100], b;
    int i;

    printf ("Escreva uma frase: ");
    for (i=0; i<100; i++)
    {
        scanf ("%c", &s[i]);
        if (s[i] == '\n')
            break;
    }

    printf ("Escreva o caracter que voce deseja verificar: ");
    scanf ("%c", &b);

    conta(b,s,i);
}

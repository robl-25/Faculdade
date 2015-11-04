#include <string.h>
#include <stdio.h>

char comparacao (char string1[100], char string2[100])
{
    int i, b=0;

    for (i=0; (string1[i]=!' ') || (string2[i]=! ' '); i++)
        if (string1[i] == string2[i])
            b++;

    return b;
}

char verificacao (char string1[100])
{
    int i=0,b=0;

    while (string1[i] != ' ')
    {
        b++;
        i++;
    }

    return b;
}

char juncao (char string1[100], char string2[100])
{
    char s[200];
    int i=0, j=0;

    for(i=0; i<200; i++)
        s[i] = ' ';

    while (string1[i] != ' ')
    {
        s[i]=string1[i];
        i++;
    }

    while (string2[j] != ' ')
    {
        s[i+j] = string2[j];
        j++;
    }
    return s;
}

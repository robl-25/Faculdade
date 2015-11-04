#include <stdio.h>
#include <string.h>



void main ()
{
    int cont, cont1=0,cont2=0,cont3=0,i, cont4=0;
    char t[100];

    printf ("Escreva uma frase sem pontos:\n");
    for (i=0; i< 100;i++)
        {scanf ("%c", &t[i]);
            if (t[i] == '\n')
                break;
        }

    for (i=0; i< 100 ;i=i+cont)
    {
        if (t[i] == '\n')
                break;
        for (cont=0; cont<100; cont++)
        {
            if (t[i] == ' ')
                break;
        }

        switch (cont){
        case 1: cont1++; break;
        case 2: cont2++; break;
        case 3: cont3++; break;
        case 4: cont4++; break;
    }
    }

    printf ("\n%d %d %d %d\n", cont1, cont2, cont3, cont4);
}

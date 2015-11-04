#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char sigla[2]; // estado da pessoa
    printf ("digite a sigla do estado que voce nasceu: ");
    scanf ("%s",sigla);
    if (strcmp(sigla,"SP")==0)
       printf("voce e paulista");
    else if (strcmp(sigla,"RJ")==0)
       printf("voce e carioca");
    else if (strcmp(sigla,"MG")==0)
       printf ("voce e mineiro");
    else if (strcmp(sigla,"BA")==0)
       printf ("voce e baiano");
    else
        printf ("voce e de outro estado");
    return 0;
}

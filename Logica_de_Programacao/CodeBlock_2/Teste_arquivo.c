#include <stdio.h>

int main()
{
    FILE *arquivo;
    char texto[100];
    gets(texto);
// cria um arquivo de texto e escreve nele
    /*arquivo = fopen ("/home/robl25/Área de Trabalho/CodeBlocks/arq.txt","w");
    fputs (texto, arquivo);
    fclose (arquivo);*/

    arquivo = fopen("/home/robl25/Área de Trabalho/CodeBlocks/arq.txt","r");
    while (fgets(texto,100, arquivo) != NULL)
        printf("%s", texto);
    fclose(arquivo);
    return 0;
}

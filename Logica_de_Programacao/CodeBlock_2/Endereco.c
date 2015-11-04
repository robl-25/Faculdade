#include <stdio.h>
#include <string.h>

struct endereco
{
    char logradouro[100];
    char complemento [100];
    char bairro[100];
    char cidade[100];
    char estado[100];
    char pais[100];
    int numero;
};

void registro (struct endereco *pessoa)
{
    char r,f;
    printf ("Digite o logradouro:\n");
    gets (pessoa->logradouro);
    printf ("Digite o bairro:\n");
    gets (pessoa->bairro);
    printf ("Digite o cidade:\n");
    gets (pessoa->cidade);
    printf ("Digite o estado:\n");
    gets (pessoa->estado);
    printf ("Digite o pais:\n");
    gets (pessoa->pais);
    printf ("Digite o numero: ");
    scanf ("%d", &pessoa->numero);
    scanf ("%c",&f);
    printf ("Há complemento? ");
    scanf ("%c", &r);
    if (r == 's')
        gets (pessoa->complemento);
    else
        strcpy (pessoa->complemento,"");
}

void main ()
{
    const int n=10;
    struct endereco pessoa[n];
    int i;

    for (i=0; i<n; i++)
        registro (&pessoa[i]);
    for (i=0; i<n; i++)
        printf ("\nO endereço da primeira pessoa é Rua %s, %d, %s, %s, %s, %s, %s\n",pessoa[i].logradouro, pessoa[i].numero, pessoa[i].complemento, pessoa[i].bairro, pessoa[i].cidade, pessoa[i].estado, pessoa[i].pais);
}




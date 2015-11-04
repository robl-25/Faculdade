#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
   int contcaracter, contpalavras,contvogais;
   char  frase [50];
   printf ("Digite uma frase: ");
   gets(frase);
   contcaracter=0;
   contpalavras=1;
   contvogais=0;
   while (contcaracter<strlen(frase))
   {
        if (frase[contcaracter]=='a' || frase[contcaracter]=='e' || frase[contcaracter]=='i' || frase[contcaracter]=='o' || frase[contcaracter]=='u'){
           contvogais=contvogais+1;
        }
        if (frase[contcaracter]==' '){
           contpalavras=contpalavras+1;
        }
        contcaracter=contcaracter+1;
    }
   printf("\nA frase contem %i vogais\n",contvogais);
   printf("\nA frase contem %i palavras\n", contpalavras);
   printf("\nA frase contem %i caracteres\n", contcaracter);




   return 0;
}

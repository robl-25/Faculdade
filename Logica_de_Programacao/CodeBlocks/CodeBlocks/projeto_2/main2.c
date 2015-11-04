#include <stdio.h>
#include <stdlib.h>

int main()
{
    int imp,ass,maximp;
    scanf("%d", &imp);
    maximp=imp;
    ass=0;
    while(imp!=-1)
    {
        if(imp>maximp)
        {
            maximp=imp;
        }
        else if (maximp==imp)
            ass=ass+1;
        scanf("%d", &imp);
    }
    printf("\nO maior impulso é: %d\n", maximp);
    printf("\n A quantidade de usuarios que atigiram o impulso maximo são: %d\n", ass);

    return 0;
}

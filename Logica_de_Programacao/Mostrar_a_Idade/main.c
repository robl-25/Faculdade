#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,aa,a,dn,mn,da,ma,d,m; //n=ano de nascimento, aa=ano atual, i=idade, dn=dia de nascimento, mn=mes de nascimento, da=dia atual, ma=mes atual, a=anos, m=meses, d=dias
    printf ("Digite o dia de seu nascimento: ");
    scanf ("%d",&dn);
    printf ("\nDigite o numero correspondente ao mes de seu nascimento: ");
    scanf ("%d",&mn);
    printf ("\nDigite o seu ano de nascimento: ");
    scanf ("%d",&n);
    printf ("\nDigite o dia de hoje: ");
    scanf ("%d",&da);
    printf ("\nDigite o numero correspondente ao mes atual: ");
    scanf ("%d",&ma);
    printf ("\nDigite o ano atual: ");
    scanf ("%d",&aa);
    if (n<aa){
    d=da-dn;
    m=ma-mn;
    if (d<0){
    d=d+30;
    }
    else if (d>0) {
    a=aa-n;
    }
    if (m<0){
    a=aa-n-1;
    m=m+12;
    }
    else if (m>0){
    a=aa-n;
    }
    printf ("\nSua idade eh: %d anos %d meses %d dias",a,m,d);
    }
    else
    printf ("\nerro");

    return 0;
}

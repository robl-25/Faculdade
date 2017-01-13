/*
* Nome: Mariane Coelho Robl
* R.A.: 86902
* Description: Conta numeros, simbolos e identificadores

* */

%{

    int num_numbers = 0, num_chars = 0, num_sim = 0;

%}

digitos [0-9]
numeros {digitos}+

alfa [a-zA-Z]
id {alfa}({alfa}|{numeros})*

simbolos ["-""!=""<""<="">""=>""==""&&""||""*""+""--""=""/""%"]

espaco [ \t]+

%%

{espaco} /* Ignorar os espacos */;

{id} ++num_chars;

{numeros} ++num_numbers;

{simbolos} ++num_sim;

<<EOF>> return 0;

fim\n return 0;

%%

int main(int argc, char *argv[]){

    FILE *f_in;

    if (argc == 2){

        if(f_in = fopen(argv[1],"r")) yyin = f_in;

        else perror(argv[0]);

    }

    else yyin = stdin;

    yylex();

    printf("Numero(s) = %d\n", num_numbers);
    printf("Id(s) = %d\n", num_chars);
    printf("Simbolo(s) = %d\n", num_sim);
    
    return 0;

}

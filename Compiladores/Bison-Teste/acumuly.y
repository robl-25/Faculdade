%{
//GLC para gerar parser para calculadora simples
#include <stdio.h>
#define YYDEBUG 1    //Para exibir na tela os passos da análise sintática quando o parser é executado
void yyerror(char *);
void abrirArq();
%}

%start entrada
%token NUM ERRO LINH 
%left SOMA SUBT
%left MULT
%token PARD PARE

//Para mostrar o valor semântico to token quando for debugar o parser
%printer { fprintf (yyoutput, "%d", $$); } NUM

%%

entrada :	/* entrada vazia */
	| 	entrada result;
result	:	LINH
	|	exp LINH	{ printf("\nResposta: %d\n", $1); }
	|	error LINH	{ yyerrok; }
	;
exp	:	exp SOMA termo 	{$$ = $1 + $3;}
	|	exp SUBT termo 	{$$ = $1 - $3;}
	|	termo 		{$$ = $1;}
	;
termo	:	termo MULT fator	{$$ = $1 * $3;}
	|	fator		{$$ = $1;}
	;
fator	:	PARE exp PARD	{$$ = $2;}
	|	NUM 		{$$ = $1;}
	;
%%

int main()
{
  extern int yydebug;
  yydebug = 1;

  printf("\nParser em execução...\n");
  abrirArq();
  return yyparse();
}

void yyerror(char * msg)
{
  extern char* yytext;
  printf("\n%s : %s %d\n", msg, yytext, yylval);
}


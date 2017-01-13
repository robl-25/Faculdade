/****************************************************/
/* File: tiny.y                                     */
/* The TINY Yacc/Bison specification file           */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/
%{
#define YYPARSER /* distinguishes Yacc output from other code files */

#include "globals.h"
#include "util.h"
#include "scan.h"
#include "parse.h"

#define YYSTYPE TreeNode *
static TreeNode * savedTree; /* stores syntax tree for later return */
static int yylex(void);
int yyerror(char *msg);


%}

%token IF ELSE INT RETURN VOID WHILE
%token ID NUM
%token EQ ATRIBUICAO LT RT PLUS MINUS TIMES OVER LPAREN RPAREN
%token SEMI LTEQ RTEQ NEQ VIRGULA LCOLCHETE RCOLCHETE LCHAVE RCHAVE
%token ERROR ENDFILE

%% /* Grammar for cminus */

program        : decl_list {savedTree = $1;}
               ;
decl_list      : decl_list decl
                 { YYSTYPE t = $1;
                    if(t != NULL){
                        while(t->sibling != NULL)
                            t = t->sibling;
                        t->sibling = $2;
                        $$ = $1;
                     }
                     else $$ = $2;
                 }
               | decl {$$ = $1;}
               ;
decl           : var_decl {$$ = $1;}
               | fun_decl {$$ = $1;}
               ;
var_decl       : INT identificador SEMI
                 { $$ = newExpNode(TipoK);
                   $$->attr.name = "Int";
                   $$->size = 1;
                   $$->child[0] = $2;
                   $2->kind.exp = VariavelK;
                   $2->type = INTTYPE;
                 }
               | INT identificador LCOLCHETE numero RCOLCHETE SEMI
                 { $$ = newExpNode(TipoK);
                   $$->attr.name = "Int";
                   $$->size = $4->attr.val;
                   $$->child[0] = $2;
                   $2->kind.exp = VetorK;
                 }
	           ;
tipo_esp       : INT { $$ = newExpNode(TipoK);
                       $$->type = Integer;
                       $$->attr.name = "Int";
                       $$->type = INTTYPE;
                     }
	           | VOID { $$ = newExpNode(TipoK);
                        $$->type = Void;
                        $$->attr.name = "Void";
                        $$->type = VOIDTYPE;
                        $$->size = 1;
                      }
	           ;
fun_decl       : INT identificador LPAREN params RPAREN composto_decl
                 { $$ = newExpNode(TipoK);
                   $$->attr.name = "Int";
                   $$->child[0] = $2;
                   $2->kind.exp = FuncaoK;
                   $2->lineno = $$->lineno;
                   $2->type = INTTYPE;
                   $2->child[0] = $4;
                   $2->child[1] = $6;
                 }
               | VOID identificador LPAREN params RPAREN composto_decl
                 { $$ = newExpNode(TipoK);
                  $$->attr.name = "Void";
                  $$->child[0] = $2;
                  $2->kind.exp = FuncaoK;
                  $2->lineno = $$->lineno;
                  $2->type = VOIDTYPE;
                  $2->child[0] = $4;
                  $2->child[1] = $6;
                 }
	           ;
params         : param_list {$$ = $1;}
	           | VOID { $$ = newExpNode(TipoK);
                        $$->attr.name = "Void";
                        $$->size = 1;
                        $$->child[0] = NULL;
                      }
	           ;
param_list     : param_list VIRGULA param_list
                 { YYSTYPE t = $1;
                    if(t != NULL){
                        while(t->sibling != NULL)
                            t = t->sibling;
                        t->sibling = $3;
                        $$ = $1;
                     }
                     else $$ = $3;
                 }
	           | param {$$ = $1;}
	           ;
param 	       : tipo_esp identificador
                 { $1->child[0] = $2;
                   $$ = $1;
                   $2->kind.exp = CallK;
                 }
	           | tipo_esp identificador LCOLCHETE RCOLCHETE
	             { $$ = $1;
                   $$->size = 0;
                   $$->child[0] = $2;
	               $2->kind.exp = CallK;
	             }
	           ;
composto_decl  : LCHAVE local_decl statement_list RCHAVE
                 { YYSTYPE t = $2;
                    if(t != NULL){
                        while(t->sibling != NULL)
                            t = t->sibling;
                        t->sibling = $3;
                        $$ = $2;
                     }
                     else $$ = $3;
                 }
	           | LCHAVE RCHAVE
	           | LCHAVE local_decl RCHAVE {$$ = $2;}
	           | LCHAVE statement_list RCHAVE {$$ = $2;}
	           ;
local_decl     : local_decl var_decl
                 { YYSTYPE t = $1;
                    if(t != NULL){
                        while(t->sibling != NULL)
                            t = t->sibling;
                        t->sibling = $2;
                        $$ = $1;
                     }
                     else $$ = $2;
                 }
	           | var_decl {$$ = $1;}
	           ;
statement_list : statement_list statement
                 { YYSTYPE t = $1;
                    if(t != NULL){
                        while(t->sibling != NULL)
                            t = t->sibling;
                        t->sibling = $2;
                        $$ = $1;
                     }
                     else $$ = $2;
                 }
    	       | statement {$$ = $1;}
	           ;
statement      : exp_decl {$$ = $1;}
               | composto_decl {$$ = $1;}
               | selecao_decl {$$ = $1;}
               | iteracao_decl {$$ = $1;}
               | retorno_decl {$$ = $1;}
               ;
exp_decl       : exp SEMI {$$ = $1;}
               | SEMI
               ;
selecao_decl   : IF LPAREN exp RPAREN statement
                 { $$ = newStmtNode(IfK);
                   $$->child[0] = $3;
                   $$->child[1] = $5;
                 }
               | IF LPAREN exp RPAREN statement ELSE statement
                 { $$ = newStmtNode(IfK);
                   $$->child[0] = $3;
                   $$->child[1] = $5;
                   $$->child[2] = $7;
                 }
               ;
iteracao_decl  : WHILE LPAREN exp RPAREN statement
                 { $$ = newStmtNode(WhileK);
                   $$->child[0] = $3;
                   $$->child[1] = $5;
                 }
               ;
retorno_decl   : RETURN SEMI { $$ = newStmtNode(ReturnK);}
               | RETURN exp SEMI
                 { $$ = newStmtNode(ReturnK);
                   $$->child[0] = $2;
                 }
               ;
exp            : var ATRIBUICAO exp
                 { $$ = newStmtNode(AssignK);
                   $$->child[0] = $1;
                   $$->child[1] = $3;
                 }
               | simples_exp {$$ = $1;}
               ;
var            : identificador{$$ = $1;}
               | identificador LCOLCHETE exp RCOLCHETE
                 { $$ = $1;
                   $$->type = INTTYPE;
                   $$->child[0] = $3;
                 }
               ;
simples_exp    : soma_exp relacional soma_exp
                 { $$ = $2;
                   $$->child[0] = $1;
                   $$->child[1] = $3;
                 }
               | soma_exp {$$ = $1;}
               ;
relacional     : LTEQ
                 {
                     $$ = newExpNode(OpK);
                     $$->attr.op = LTEQ;
                 }
               | LT
                 {
                     $$ = newExpNode(OpK);
                     $$->attr.op = LT;
                 }
               | RT
                 {
                     $$ = newExpNode(OpK);
                     $$->attr.op = RT;
                 }
               | RTEQ
                 {
                     $$ = newExpNode(OpK);
                     $$->attr.op = RTEQ;
                 }
               | EQ
                 {
                     $$ = newExpNode(OpK);
                     $$->attr.op = EQ;
                 }
               | NEQ
                 {
                     $$ = newExpNode(OpK);
                     $$->attr.op = NEQ;
                 }
               ;
soma_exp       : soma_exp soma termo
                 { $$ = $2;
                   $$->child[0] = $1;
                   $$->child[1] = $3;
                 }
               | termo {$$ = $1;}
               ;
soma           : PLUS
                 {
                     $$ = newExpNode(OpK);
                     $$->attr.op = PLUS;
                 }
               | MINUS
                 {
                     $$ = newExpNode(OpK);
                     $$->attr.op = MINUS;
                 }
               ;
termo          : termo mult fator
                 { $$ = $2;
                   $$->child[0] = $1;
                   $$->child[1] = $3;
                 }
               | fator {$$ = $1;}
               ;
mult           : TIMES
                 {
                     $$ = newExpNode(OpK);
                     $$->attr.op = TIMES;
                 }
               | OVER
                 {
                     $$ = newExpNode(OpK);
                     $$->attr.op = OVER;
                 }
               ;
fator          : LPAREN exp RPAREN {$$ = $2;}
               | var {$$ = $1;}
               | ativacao {$$ = $1;}
               | numero {$$ = $1;}
               ;
ativacao       : identificador LPAREN RPAREN
                 { $$ = $1;
                     $$ = newExpNode(AtivacaoK);
                     $$->attr.name = $1->attr.name;
                 }
	           | identificador LPAREN arg_list RPAREN
                 { $$ = $1;
                     $$ = newExpNode(AtivacaoK);
                     $$->attr.name = $1->attr.name;
                     $$->child[0] = $3;
                 }
	           ;
arg_list       : arg_list VIRGULA exp
                { YYSTYPE t = $1;
                   if(t != NULL){
                       while(t->sibling != NULL)
                           t = t->sibling;
                       t->sibling = $3;
                       $$ = $1;
                    }
                    else $$ = $3;
                }
               | exp {$$ = $1;}
               ;
identificador  : ID { $$ = newExpNode(IdK);
                      $$->attr.name = copyString(tokenString);
                    }
               ;
numero         : NUM { $$ = newExpNode(ConstK);
                        $$->type = INTTYPE;
                      $$->attr.val = atoi(tokenString);
                    }
               ;
%%

int yyerror(char * message)
{ fprintf(listing,"Syntax error at line %d: %s\n",lineno,message);
  fprintf(listing,"Current token: ");
  printToken(yychar,tokenString);
  Error = TRUE;
  return 0;
}

/* yylex calls getToken to make Yacc/Bison output
 * compatible with ealier versions of the TINY scanner
 */
static int yylex(void)
{ return getToken(); }

TreeNode * parse(void)
{ yyparse();
  return savedTree;
}

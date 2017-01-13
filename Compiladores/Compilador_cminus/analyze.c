/****************************************************/
/* File: analyze.c                                  */
/* Semantic analyzer implementation                 */
/* for the TINY compiler                            */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#include "globals.h"
#include "symtab.h"
#include "analyze.h"
#include <stdio.h>

/* counter for variable memory locations */
static int location = 0;
char* escopo = "global";

void atualizaEscopo(TreeNode * t)
{
  //printf("atualiza Escopo\n");
  if (t->child[0] != NULL && t->child[0]->kind.exp == FuncaoK) escopo = t->child[0]->attr.name;
}

/* Procedure traverse is a generic recursive
 * syntax tree traversal routine:
 * it applies preProc in preorder and postProc
 * in postorder to tree pointed to by t
 */
static void traverse( TreeNode * t,
               void (* preProc) (TreeNode *),
               void (* postProc) (TreeNode *) )
{ if (t != NULL)
  { atualizaEscopo(t);
      preProc(t);
    { int i;
      for (i=0; i < MAXCHILDREN; i++)
        traverse(t->child[i],preProc,postProc);
    }
    if(t->child[0]!= NULL && t->child[0]->kind.exp == FuncaoK) escopo = "global";
    postProc(t);
    traverse(t->sibling,preProc,postProc);
  }
}

/* nullProc is a do-nothing procedure to
 * generate preorder-only or postorder-only
 * traversals from traverse
 */
static void nullProc(TreeNode * t)
{ if (t==NULL) return;
  else return;
}

/* Procedure insertNode inserts
 * identifiers stored in t into
 * the symbol table
 */
 static void insertNode( TreeNode * t)
 {
   switch (t->nodekind){
     case StmtK:
       if(t->kind.stmt == AssignK)
       {
           if (st_lookup(t->child[0]->attr.name) == -1){
             fprintf(listing,"Erro na linha %d: A variavel %s nao foi declarada.\n", t->lineno, t->child[0]->attr.name);
             Error = TRUE;
           }
           else
             st_insert(t->child[0]->attr.name,t->lineno,0,escopo,INTTYPE,VAR);
           t->child[0]->add = 1;
       }
       else
       break;
     case ExpK:
       switch(t->kind.exp )
       {
         case TipoK:

           if(t->child[0] != NULL){
             switch (t->child[0]->kind.exp)
             {
                 case VariavelK:
                     if (st_lookup(t->attr.name) == -1)
                       st_insert(t->child[0]->attr.name,t->lineno,location++, escopo,INTTYPE, VAR);
                     else
                       st_insert(t->child[0]->attr.name,t->lineno,0, escopo,INTTYPE, VAR);
                       break;

                case VetorK:
                    st_insert(t->child[0]->attr.name,t->lineno,location++, escopo,INTTYPE, VAR);
                    break;

                 case FuncaoK:
                     if (st_lookup(t->attr.name) == -1)
                       st_insert(t->child[0]->attr.name,t->lineno,location++, "global",t->child[0]->type,FUN);
                     else
                       fprintf(listing,"Erro na linha %d: Multiplas declaracoes da funcao %s.\n", t->lineno, t->child[0]->attr.name);
                 break;
               default:
                   break;
             }
           }
           break;
         case CallK:
           st_insert(t->attr.name,t->lineno,location++, escopo,INTTYPE, VAR);
           break;
         case IdK:
           if(t->add != 1){
             if (st_lookup(t->attr.name) == -1){
               fprintf(listing,"Erro na linha %d: A variavel %s nao foi declarada.\n", t->lineno, t->attr.name);
               Error = TRUE;
             }
             else {
               st_insert(t->attr.name,t->lineno,0, escopo,INTTYPE,FUN);
             }
           }
           break;
         case AtivacaoK:
           if (st_lookup(t->attr.name) == -1){
             fprintf(listing,"Erro na linha %d: A funcao %s nao foi declarada.\n", t->lineno, t->attr.name);
             Error = TRUE;
           }
           else {
             st_insert(t->attr.name,t->lineno,0, escopo,0,FUN);
           }
           break;
         default:
           break;
       }
       break;
     default:
       break;
   }
 }

/* Function buildSymtab constructs the symbol
 * table by preorder traversal of the syntax tree
 */
void buildSymtab(TreeNode * syntaxTree)
{ traverse(syntaxTree,insertNode,nullProc);
  busca_main();
  typeCheck(syntaxTree);
  if (TraceAnalyze)
  { fprintf(listing,"\nSymbol table:\n\n");
    printSymTab(listing);
  }
}

static void typeError(TreeNode * t, char * message)
{ fprintf(listing,"Type error at line %d: %s\n",t->lineno,message);
  Error = TRUE;
}

/* Procedure checkNode performs
 * type checking at a single tree node
 */
void checkNode(TreeNode * t)
{ switch (t->nodekind)
{ case ExpK:
    switch (t->kind.exp)
    { case OpK:
        if (((t->child[0]->kind.exp == AtivacaoK) &&( getFunType(t->child[0]->attr.name)) == VOIDTYPE) ||
            ((t->child[1]->kind.exp == AtivacaoK) && (getFunType(t->child[1]->attr.name) == VOIDTYPE)))
              typeError(t->child[0],"Chamada de funcao do tipo void na expressao");
        break;

      default:
        break;
    }
    break;
  case StmtK:
    switch (t->kind.stmt)
    {
      case AssignK:
        if (t->child[1]->kind.exp == AtivacaoK && getFunType(t->child[1]->attr.name) == VOIDTYPE)
          typeError(t->child[0],"Funcao com retorno void nao pode ser atribuido a uma variavel");
        break;

      default:
        break;
    }
    break;
  default:
    break;

  }
}

/* Procedure typeCheck performs type checking
 * by a postorder syntax tree traversal
 */
void typeCheck(TreeNode * syntaxTree)
{ traverse(syntaxTree,nullProc,checkNode);
}

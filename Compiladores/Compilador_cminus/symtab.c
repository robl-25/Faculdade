/****************************************************/
/* File: symtab.c                                   */
/* Symbol table implementation for the TINY compiler*/
/* (allows only one symbol table)                   */
/* Symbol table is implemented as a chained         */
/* hash table                                       */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtab.h"

/* SIZE is the size of the hash table */
#define SIZE 211

/* SHIFT is the power of two used as multiplier
   in hash function  */
#define SHIFT 4

/* the hash function */
static int hash ( char * key )
{ int temp = 0;
  int i = 0;
  while (key[i] != '\0')
  { temp = ((temp << SHIFT) + key[i]) % SIZE;
    ++i;
  }
  return temp;
}

/* the list of line numbers of the source
 * code in which a variable is referenced
 */
typedef struct LineListRec
   { int lineno;
     struct LineListRec * next;
   } * LineList;

/* The record in the bucket lists for
 * each variable, including name,
 * assigned memory location, and
 * the list of line numbers in which
 * it appears in the source code
 */
typedef struct BucketListRec
   { char * name;
     LineList lines;
     int memloc ; /* memory location for variable */
     char * escopo;
     dataTypes tipo_dados;
     IDTypes tipo_id;
     struct BucketListRec * next;
   } * BucketList;

/* the hash table */
static BucketList hashTable[SIZE];

/* Procedure st_insert inserts line numbers and
 * memory locations into the symbol table
 * loc = memory location is inserted only the
 * first time, otherwise ignored
 */
void st_insert( char * name, int lineno, int loc, char* escopo,
                dataTypes tipo_dados, IDTypes tipo_id)
{ int h = hash(name);
  BucketList l =  hashTable[h];
  while ((l != NULL) && (strcmp(name,l->name) != 0))
    l = l->next;
  if (l == NULL || (loc != 0 && l->escopo != escopo && l->tipo_id != FUN)) /* variable not yet in table */
  { l = (BucketList) malloc(sizeof(struct BucketListRec));
    l->name = name;
    l->lines = (LineList) malloc(sizeof(struct LineListRec));
    l->lines->lineno = lineno;
    l->memloc = loc;
    l->tipo_dados = tipo_dados;
    l->tipo_id = tipo_id;
    l->escopo = escopo;
    l->lines->next = NULL;
    l->next = hashTable[h];
    hashTable[h] = l; }
  else if(l->tipo_dados == FUN && tipo_id == VAR){
      fprintf(listing, "Erro linha %d: Nome de variavel %s ja declarado como funcao.\n", lineno, name);
      Error = TRUE;
  }
  else if( l->escopo == escopo && loc != 0)
  {
    fprintf(listing,"Erro linha %d: Variavel %s já declarada neste escopo.\n",lineno, name);
    Error = TRUE;
  }
  else if(l->escopo != escopo && (strcmp(l->escopo,"global") != 0) ){
    while ((l != NULL)){
      if((strcmp(l->escopo, "global")==0)&& ((strcmp( name,l->name) == 0))){
        LineList t = l->lines;
        while (t->next != NULL) t = t->next;
        t->next = (LineList) malloc(sizeof(struct LineListRec));
        t->next->lineno = lineno;
        t->next->next = NULL;
        break;
      }
      l = l->next;
    }
    if(l == NULL){
      fprintf(listing,"Erro linha %d: Variavel %s não declarada neste escopo.\n",lineno, name);
      Error = TRUE;
    }
  }
  else if(loc == 0)
  {
    LineList t = l->lines;
    while (t->next != NULL) t = t->next;
    t->next = (LineList) malloc(sizeof(struct LineListRec));
    t->next->lineno = lineno;
    t->next->next = NULL;
  }
} /* st_insert */

/* Function st_lookup returns the memory
 * location of a variable or -1 if not found
 */
int st_lookup ( char * name )
{ int h = hash(name);
  BucketList l =  hashTable[h];
  while ((l != NULL) && (strcmp(name,l->name) != 0))
    l = l->next;
  if (l == NULL) return -1;
  else return l->memloc;
}

void busca_main ()
{
  //printf("st_lookup\n");
  int h = hash("main");
  BucketList l =  hashTable[h];
  while ((l != NULL) && ((strcmp("main",l->name) != 0 || l->tipo_id == VAR)))
    l = l->next;
  if (l == NULL) {
    fprintf(listing,"Erro: Função main não declarada\n");
    Error = TRUE;
  }

}

dataTypes getFunType(char* nome){
    int h = hash(nome);
    BucketList l =  hashTable[h];
    while ((l != NULL) && (strcmp(nome,l->name) != 0))
      l = l->next;

    if (l == NULL) return -1;
    else return l->tipo_dados;
}

/* Procedure printSymTab prints a formatted
 * listing of the symbol table contents
 * to the listing file
 */
 void printSymTab(FILE * listing)
 {
   //printf("printSymtab\n");
   int i;
   fprintf(listing,"Variable Name  Escopo  Tipo ID  Tipo dado  Line Numbers\n");
   fprintf(listing,"-------------  ------  -------  ---------  ------------\n");
   for (i=0;i<SIZE;++i)
   { if (hashTable[i] != NULL)
     { BucketList l = hashTable[i];
       while (l != NULL)
       { LineList t = l->lines;
         fprintf(listing,"%-14s ",l->name);
         fprintf(listing,"%-6s  ",l->escopo);
         char* id, *data;
         if(l->tipo_id == VAR){
           id = "VAR";
         }
         else if(l->tipo_id == FUN){
           id = "FUN";
         }
         if(l->tipo_dados == INTTYPE){
           data = "INT";
         }
         else if(l->tipo_dados == VOIDTYPE){
           data = "VOID";
         }
         fprintf(listing,"%-7s  ",id);
         fprintf(listing,"%-8s  ",data);

         while (t != NULL)
         { fprintf(listing,"%3d; ",t->lineno);
           t = t->next;
         }
         fprintf(listing,"\n");
         l = l->next;
       }
     }
   }
 } /* printSymTab */

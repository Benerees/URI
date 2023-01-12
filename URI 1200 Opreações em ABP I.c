/*
  autor: Benjamim Rees Pereira do Nascimento
  problem: 1200 - Operações em ABP I
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nohArvore{
  char dado[1];
  struct nohArvore *subArvEsq;
  struct nohArvore *subArvDir;
}TipoNohArvore;

typedef  TipoNohArvore *PNohArvore;

int arvoreVazia(PNohArvore raiz){
  return raiz==NULL;
}

PNohArvore instanciaArvore(char dado[1]){
  PNohArvore raiz;

  raiz = (PNohArvore) malloc(sizeof(TipoNohArvore));

  raiz->dado[0] = dado[0];
  raiz->subArvEsq = NULL;
  raiz->subArvDir = NULL;

  return raiz;
}

PNohArvore inicializaArvore(){
  return NULL;
}

PNohArvore insereNaArvore(PNohArvore raiz,char dado[1]){
  if(!arvoreVazia(raiz))
  {
    if(raiz->dado[0]<dado[0])
    {
        raiz->subArvDir = insereNaArvore(raiz->subArvDir,dado);
    }
    else
    {
      if(raiz->dado[0]>dado[0])
      {
        raiz->subArvEsq = insereNaArvore(raiz->subArvEsq,dado);
      } 
    }
  }
  else{
    raiz = instanciaArvore(dado);
  }
  return raiz;
}

PNohArvore buscaNaArvore(PNohArvore raiz,char dado[1]){
  if(!arvoreVazia(raiz))
  {
    if(raiz->dado[0]<dado[0])
    {
      return buscaNaArvore(raiz->subArvDir,dado);
    }
    else
    {
      if(raiz->dado[0]>dado[0])
      {
        return buscaNaArvore(raiz->subArvEsq,dado);
      }   
      else
        return raiz;
    }
  }
  return NULL;
}

void imprimeArvorePreFixa(PNohArvore raiz, int *contPrint){
  if(!arvoreVazia(raiz))
  {
    if(*contPrint != 0)
      printf(" %c",raiz->dado[0]);
    else
      printf("%c",raiz->dado[0]);

    (*contPrint)++;

    imprimeArvorePreFixa(raiz->subArvEsq, contPrint);
    imprimeArvorePreFixa(raiz->subArvDir, contPrint);
  }  
}

void imprimeArvoreInfixa(PNohArvore raiz, int *contPrint){
  if(!arvoreVazia(raiz))
  {
    imprimeArvoreInfixa(raiz->subArvEsq, contPrint);

    if(*contPrint != 0)
      printf(" %c",raiz->dado[0]);
    else
      printf("%c",raiz->dado[0]);

    (*contPrint)++;

    imprimeArvoreInfixa(raiz->subArvDir, contPrint);
  }  
}

void imprimeArvorePosFixa(PNohArvore raiz, int *contPrint){
  if(!arvoreVazia(raiz))
  {
    if(raiz->subArvEsq!=NULL)
      imprimeArvorePosFixa(raiz->subArvEsq, contPrint);

    if(raiz->subArvDir!=NULL)
      imprimeArvorePosFixa(raiz->subArvDir, contPrint);
      
    if(*contPrint != 0)
      printf(" %c",raiz->dado[0]);
    else
      printf("%c",raiz->dado[0]);

    (*contPrint)++;
  }  
}

int main(){
  char entrada[7], N[1];
  int C, cont1, cont2, dado, contPrint = 0;
  PNohArvore raiz;
  
  raiz = inicializaArvore();

  while (scanf("%s%*c", entrada) != EOF)
	{
    contPrint = 0;

    if(strcmp(entrada,"INFIXA")==0)
    {
      imprimeArvoreInfixa(raiz, &contPrint);
      printf("\n");
    }
    else
    {
      if(strcmp(entrada,"PREFIXA")==0)
      {
        imprimeArvorePreFixa(raiz, &contPrint);
        printf("\n");
      }
      else
      {
        if(strcmp(entrada,"POSFIXA")==0)
        {
          imprimeArvorePosFixa(raiz, &contPrint);
          printf("\n");
        }
        else
        {
          scanf("%c", &N[0]);

          if(strcmp(entrada, "I")==0)
              raiz = insereNaArvore(raiz, N);
          else
          {
            if(strcmp(entrada, "P")==0)
            {
              if(buscaNaArvore(raiz,  N)==NULL)
                printf("%c nao existe\n", N[0]);
              else
                printf("%c existe\n", N[0]);
            }
          }
        }
      } 
    }
  }
  return 0;
}
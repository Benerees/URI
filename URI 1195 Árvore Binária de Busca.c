/*
  autor: Benjamim Rees Pereira do Nascimento
  problem: 1195 - Árvore Binária de Busca
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nohArvore{
  int dado;
  struct nohArvore *subArvEsq;
  struct nohArvore *subArvDir;
}TipoNohArvore;

typedef  TipoNohArvore *PNohArvore;

int arvoreVazia(PNohArvore raiz){
  return raiz==NULL;
}

PNohArvore inicializaArvore(){
  return NULL;
}

PNohArvore instanciaArvore(int dado){
  PNohArvore raiz;

  raiz = (PNohArvore) malloc(sizeof(TipoNohArvore));

  raiz->dado = dado;
  raiz->subArvEsq = NULL;
  raiz->subArvDir = NULL;

  return raiz;
}

PNohArvore insereNaArvore(PNohArvore raiz,int dado){
  if(!arvoreVazia(raiz))
  {
    if(raiz->dado<dado)
    {
      raiz->subArvDir = insereNaArvore(raiz->subArvDir,dado);
    }
    else
    {
      if(raiz->dado>dado)
      {
        raiz->subArvEsq = insereNaArvore(raiz->subArvEsq,dado);
      }
    }
  }
  else
  {
    raiz = instanciaArvore(dado);
  }
  return raiz;
}

void imprimeArvorePreFixa(PNohArvore raiz){
  if(!arvoreVazia(raiz))
  {
    printf(" %d",raiz->dado);
    imprimeArvorePreFixa(raiz->subArvEsq);
    imprimeArvorePreFixa(raiz->subArvDir);
  }  
}

void imprimeArvoreInfixa(PNohArvore raiz)
{
  if(!arvoreVazia(raiz))
  {
    imprimeArvoreInfixa(raiz->subArvEsq);
    printf(" %d",raiz->dado);
    imprimeArvoreInfixa(raiz->subArvDir);
  }  
}

void imprimeArvorePosFixa(PNohArvore raiz){
  if(!arvoreVazia(raiz))
  {
    imprimeArvorePosFixa(raiz->subArvEsq);
    imprimeArvorePosFixa(raiz->subArvDir);
    printf(" %d",raiz->dado);
  }  
}

int main(){
  int C, N, cont1, cont2, dado;
  PNohArvore raiz[1000];

  scanf("%d", &C);

  for(cont1 = 0; cont1 < C; cont1++)
  {
    raiz[cont1] = inicializaArvore();

    scanf("%d", &N);

    for(cont2 = 0; cont2 < N; cont2++)
    {
        scanf("%d", &dado);

        raiz[cont1] = insereNaArvore(raiz[cont1], dado);
    }
  }

  for(cont1 = 0; cont1 < C; cont1++)
  {
    printf("Case %d:",cont1+1);

    printf("\nPre.:");
    imprimeArvorePreFixa(raiz[cont1]);

    printf("\nIn..:");
    imprimeArvoreInfixa(raiz[cont1]);

    printf("\nPost:");
    imprimeArvorePosFixa(raiz[cont1]);

    printf("\n\n");
  }
  
  return 0;
}
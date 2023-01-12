/*
  autor: Benjamim Rees Pereira do Nascimento
  problem: 1466 - Percurso em Árvore por Nível
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

PNohArvore instanciaArvore(int dado){
  PNohArvore raiz;

  raiz = (PNohArvore) malloc(sizeof(TipoNohArvore));

  raiz->dado = dado;
  raiz->subArvEsq = NULL;
  raiz->subArvDir = NULL;

  return raiz;
}

PNohArvore inicializaArvore(){
  return NULL;
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
  else{
    raiz = instanciaArvore(dado);
  }
  return raiz;
}

typedef struct tipoNoh{
  PNohArvore raiz;
  struct tipoNoh *prox;
} TipoNoh;

typedef TipoNoh *PNoh;

typedef struct {
  PNoh inicio, fim;
} TipoFilaD;

void inicializaFila(TipoFilaD *fila) {
  fila->inicio = NULL;
  fila->fim = NULL;
}

int filaVazia(TipoFilaD *fila){
  return fila->inicio==NULL;
}

void insereNaFila(TipoFilaD *fila, PNohArvore raiz) {
  PNoh novo, aux, aux2;
  int verifica;

  novo = (PNoh)malloc(sizeof(TipoNoh));

  if (novo != NULL) 
  {
    novo->raiz = raiz;
    novo->prox = NULL;

    if(filaVazia(fila))
    {
      fila->inicio = novo;
      fila->fim = novo;
    }
    else
    {
      fila->fim->prox = novo; 
      fila->fim = novo;
    }
  }
}

void retiraDaFila(TipoFilaD *fila, int n){
  TipoNoh *ptrAux;

  if(!filaVazia(fila))
  {
    if(fila->inicio->raiz->subArvEsq != NULL)
      insereNaFila(fila, fila->inicio->raiz->subArvEsq);

    if(fila->inicio->raiz->subArvDir != NULL)
      insereNaFila(fila, fila->inicio->raiz->subArvDir);

    ptrAux = fila->inicio;

    if(fila->inicio==fila->fim)
    {
      fila->inicio = NULL;
      fila->fim = NULL;
    }
    else
    {
      fila->inicio = ptrAux->prox;
    }

    if(n != 0)
      printf(" %d",ptrAux->raiz->dado);
    else
      printf("%d",ptrAux->raiz->dado);

    free(ptrAux);
  }
}

void imprimeArvorePorNivel(PNohArvore raiz){
  TipoFilaD fila;
  int n = 0;

  inicializaFila(&fila);
  
  if(!arvoreVazia(raiz))
  {
    insereNaFila(&fila, raiz);

    while(!filaVazia(&fila))
    {  
      retiraDaFila(&fila, n);
      n++;
    }
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
    printf("Case %d:\n",cont1+1);
    imprimeArvorePorNivel(raiz[cont1]); 
    printf("\n\n");
  }

  return 0;
}
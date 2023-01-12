/*
  autor: Benjamim Rees Pereira do Nascimento
  problem: 1201 - Operações em ABP II
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nohArvore{
  int dado;
  struct nohArvore *subArvEsq;
  struct nohArvore *subArvDir;
}TipoNohArvore;

typedef TipoNohArvore *PNohArvore;

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
    if(raiz->dado>dado)
    {
      raiz->subArvEsq = insereNaArvore(raiz->subArvEsq,dado);
    }
    else{     
      if(raiz->dado<dado)
      {
        raiz->subArvDir = insereNaArvore(raiz->subArvDir,dado);
      }
    }
  }
  else{
    raiz = instanciaArvore(dado);
  }
  return raiz;
}



PNohArvore buscaNaArvore(PNohArvore raiz,int dado){
  if(!arvoreVazia(raiz))
  {
    if(raiz->dado>dado)
    {
      return buscaNaArvore(raiz->subArvEsq,dado);
    }
    else{
      if(raiz->dado<dado)
      {
        return buscaNaArvore(raiz->subArvDir,dado);
      }
      else
        return raiz;
    }
  }
  return NULL;
}

//contPrint ser apenas para verificar qual o primeiro a ser impresso para que possa dar o espaço
void imprimeArvorePreOrdem(PNohArvore raiz, int *contPrint){
  if(!arvoreVazia(raiz))
  {
    if(*contPrint != 0)
      printf(" %d",raiz->dado);
    else
      printf("%d",raiz->dado);
    
    (*contPrint)++;

    imprimeArvorePreOrdem(raiz->subArvEsq, contPrint);
    imprimeArvorePreOrdem(raiz->subArvDir, contPrint);
  }  
}


void imprimeArvoreEmOrdem(PNohArvore raiz, int *contPrint){
  if(!arvoreVazia(raiz))
  {
    imprimeArvoreEmOrdem(raiz->subArvEsq, contPrint);

    if(*contPrint != 0)
      printf(" %d",raiz->dado);
    else
      printf("%d",raiz->dado);

    (*contPrint)++;

    imprimeArvoreEmOrdem(raiz->subArvDir, contPrint);
  }  
}

void imprimeArvorePosOrdem(PNohArvore raiz, int *contPrint){
  if(!arvoreVazia(raiz))
  {
    if(raiz->subArvEsq!=NULL)
      imprimeArvorePosOrdem(raiz->subArvEsq, contPrint);

    if(raiz->subArvDir!=NULL)
      imprimeArvorePosOrdem(raiz->subArvDir, contPrint);

    if(*contPrint != 0)
      printf(" %d",raiz->dado);
    else
      printf("%d",raiz->dado);

    (*contPrint)++;
  }  
}

PNohArvore buscaAnteriorNaArvore(PNohArvore raiz,int dado , PNohArvore *anterior){
  if(!arvoreVazia(raiz))
  {
    if(raiz->dado>dado)
    {
      if(raiz != *anterior )
      {
        *anterior = raiz;
      }

      return buscaAnteriorNaArvore(raiz->subArvEsq,dado, anterior);
    }
    else{      
      if(raiz->dado<dado)
      {
        if(raiz != *anterior )
        {
          *anterior = raiz;
        }

        return buscaAnteriorNaArvore(raiz->subArvDir,dado , anterior);
      }else
        return raiz;
    }
  }
  return NULL;
}

PNohArvore retiraDaArvore(PNohArvore raiz,int dado){
  PNohArvore aux1, pai, aux2;

  if (raiz == NULL)
    return NULL;
  else if (dado < raiz->dado)
    raiz->subArvEsq = retiraDaArvore(raiz->subArvEsq, dado);
  else if (raiz->dado < dado)
    raiz->subArvDir = retiraDaArvore(raiz->subArvDir, dado);
  else {
    if (raiz->subArvEsq==NULL && raiz->subArvDir==NULL)
    {
      free (raiz);
      raiz = NULL;
    }
    else if (raiz->subArvEsq == NULL) 
    {
      aux1 = raiz;
      raiz = raiz->subArvDir;
      free (aux1);
    }
    else if (raiz->subArvDir == NULL) 
    {
      aux1 = raiz;
      raiz = raiz->subArvEsq;
      free (aux1);
    }
    else 
    {
      pai = raiz;
      aux2 = raiz->subArvEsq;

      while (aux2->subArvDir != NULL) 
      {
        pai = aux2;
        aux2 = aux2->subArvDir;
      }

      raiz->dado = aux2->dado;

      if (pai==raiz)
        pai->subArvEsq = aux2->subArvEsq;    
      else
        pai->subArvDir = aux2->subArvEsq;

      free(aux2);    
    }
  }
  return raiz;
}

int main(){
  char entrada[50];
  int C, N, cont1, cont2, dado, contPrint = 0;
  PNohArvore raiz;
  
  raiz = inicializaArvore();

  while (scanf("%s%*c", entrada) != EOF)
	{
    contPrint = 0;

    if(strcmp(entrada,"INFIXA")==0)
    {
      imprimeArvoreEmOrdem(raiz, &contPrint);
      printf("\n");
    }
    else{
      if(strcmp(entrada,"PREFIXA")==0)
      {
        imprimeArvorePreOrdem(raiz, &contPrint);
        printf("\n");
      }
      else
      {
        if(strcmp(entrada,"POSFIXA")==0)
        {
          imprimeArvorePosOrdem(raiz, &contPrint);
          printf("\n");
        }
        else
        {
          scanf("%d", &N);

          if(strcmp(entrada, "I")==0)
              raiz = insereNaArvore(raiz, N);
          else
          {
            if(strcmp(entrada, "P")==0)
            {
              if(buscaNaArvore(raiz,  N)==NULL)
                printf("%d nao existe\n", N);
              else
                printf("%d existe\n", N);
            }else
            {
              if(strcmp(entrada, "R")==0)
              {
                 raiz = retiraDaArvore(raiz, N);
              }
            }
          }
        }
      } 
    }
  }

  return 0;
}
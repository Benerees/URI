/*
  autor: Benjamim Rees Pereira do Nascimento
  problem: 1194 - Prefixa, Infixa e Posfixa
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

PNohArvore inicializaArvore(){
  return NULL;
}

PNohArvore instanciaArvore(char dado[1]){
  PNohArvore raiz;

  raiz = (PNohArvore) malloc(sizeof(TipoNohArvore));

  raiz->dado[0] = dado[0];
  raiz->subArvEsq = NULL;
  raiz->subArvDir = NULL;
  
  return raiz;
}

PNohArvore insereNaArvore(PNohArvore raiz,char S1[1], char* S2){
  int cont1 = 0, cont2 = 0;
  
  if(arvoreVazia(raiz))
  {
    raiz = instanciaArvore(&S1[0]);

    return raiz;
  }
  else
  {
    while(raiz->dado[0] != S2[cont1])
    {
      cont1++;
    }
    
    while(S2[cont2] != S1[0])
    {
      cont2++;
    }

    if(cont1 > cont2)
    {
      raiz->subArvEsq = (insereNaArvore(raiz->subArvEsq, &S1[0], S2));
    }
    else
    {
      raiz->subArvDir = (insereNaArvore(raiz->subArvDir, &S1[0], S2));
    } 
  }
  return raiz;
}

void imprimeArvorePosFixa(PNohArvore raiz){
  if(!arvoreVazia(raiz))
  {
    if(raiz->subArvEsq!=NULL)
      imprimeArvorePosFixa(raiz->subArvEsq);

    if(raiz->subArvDir!=NULL)
      imprimeArvorePosFixa(raiz->subArvDir);

    printf("%c",raiz->dado[0]);
  }  
}

int main(){
  char S1[100], S2[100];
  int C, cont1, cont2, nodos;
  PNohArvore raiz[2000];

  scanf("%d", &C);
  
  for(cont1 = 0; cont1 < C; cont1++)
	{
    raiz[cont1] = inicializaArvore();

    scanf("%d", &nodos);
    scanf("%s%*c", S1);
    scanf("%s%*c", S2);

    for(cont2 = 0; cont2 < strlen(S1); cont2++)
    {     
        raiz[cont1] = insereNaArvore(raiz[cont1], &S1[cont2], S2);
    }
  }

  for(cont1 = 0; cont1 < C; cont1++)
  {
    imprimeArvorePosFixa(raiz[cont1]);
    printf("\n");
  }

  return 0;
}
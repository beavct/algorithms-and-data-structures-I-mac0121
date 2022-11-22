/* 

Tabela de símbolos para pares (chave,valor)
 chave - é uma string
 valor - um inteiro

Implementada com Árvores de Busca Binária 

*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arv.h"


no * busca (no * raiz, char * x){
  if (raiz == NULL || strcmp(raiz->chave, x) == 0)
    return raiz;
  if (strcmp(x, raiz->chave) < 0)
    return busca (raiz->esq, x);
  return busca (raiz->dir, x);
}

      
/* Insere um elemento na tabela, devolve a raiz da árvore com o
   elemento inserido. Se o elemento já está na árvore, altera o valor
   do mesmo para "valor"

no * insere (no * raiz, char * x, int valor); 
*/ 

no * insercao (no * raiz, char * x, int valor){

  if (raiz == NULL){
    raiz = malloc (sizeof(no));
    raiz->chave = malloc(strlen(x)+1);
    strcpy(raiz->chave,x);
    raiz->valor = valor;
    raiz->dir = raiz->esq = NULL;
    return raiz;
  }
  if (strcmp(x, raiz->chave) == 0)
    raiz->valor = valor;
  else if (strcmp(x, raiz->chave) < 0)
    raiz->esq = insercao (raiz->esq, x, valor);
  else if (strcmp(x, raiz->chave) > 0)
    raiz->dir = insercao (raiz->dir, x, valor);
  return raiz;
}




no * remocao (no * raiz, char * x){
  no * y; 
  if (raiz == NULL)
    return NULL;
  if (strcmp(x, raiz->chave) < 0)
    raiz->esq = remocao(raiz->esq, x);
  else if (strcmp(x, raiz->chave) > 0)
    raiz->dir = remocao(raiz->dir, x);
  else{
    if (raiz->esq == NULL){
      y = raiz->dir;
      free(raiz);
      raiz = y;     
    }
    else if (raiz->dir == NULL){
      y = raiz->esq;
      free(raiz);
      raiz = y;
    }
    else{
      y = minimo(raiz->dir);
      raiz->chave = y->chave;
      raiz->valor = y->valor;
      raiz->dir = remocao(raiz->dir, y->chave);
      /* nao precisa de free, a recursao cuida */
    }
  }
  return raiz;
}




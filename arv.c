/* Árvores Binárias */

#include <stdio.h>
#include <stdlib.h>
#include "arv.h"



no * minimo (no * raiz){
  if (raiz == NULL || raiz->esq == NULL)
    return raiz;
  return minimo(raiz->esq);
} 


/* recebe a raiz de uma árvore e devolve quantos nós ela tem 
   int contaNo (no *raiz); 
*/

int contaNo (no *raiz){
  if (raiz == NULL)
    return 0;
  return (1 + contaNo(raiz->dir) + contaNo(raiz->esq));
}

/* 
   recebe a raiz de uma árvore e devolve 
   sua altura. A árvore vazia tem altura -1. 

   int altura (no *raiz); 

   altura (arvore) = 1 + max (altura(esq), altura(dir))
*/ 

int altura (no *raiz){
  int alte, altd; 
  if (raiz == NULL)
    return -1;
  alte = altura(raiz->esq);
  altd = altura(raiz->dir); 
  if (alte > altd)
    return 1 + alte;
  return 1 + altd;
} 
  


/*****
int ehDescendente (no *x, no *y); 

devolve 1 se x é descendente de y ou 0 caso contrário
******/


int ehDescendente (no *x, no *y){
  if (x == NULL || y == NULL) return 0;
  if (x == y) return 1;
  return (ehDescendente (x, y->esq) || ehDescendente (x, y->dir));
} 


/******

Percurso in-ordem: esquerda, raiz, direita

void inordem (no *raiz); 
********/

void inordem (no *raiz) {
  if (raiz != NULL){
    inordem (raiz->esq);
    printf("%d %s\n", raiz->valor, raiz->chave);
    inordem (raiz->dir);
  }
}


/******
Percurso pre-ordem: raiz, esquerda, direita

void preordem (no *raiz); 
********/

void preordem (no *raiz) {
  if (raiz != NULL){
    printf("%d %s\n", raiz->valor, raiz->chave);
    preordem (raiz->esq);
    preordem (raiz->dir);
  }
}

/******
Percurso pos-ordem: esquerda, direita, raiz

void posordem (no *raiz); 
********/

void posordem (no *raiz) {
  if (raiz != NULL){
    posordem (raiz->esq);
    posordem (raiz->dir);
    printf("%d %s\n", raiz->valor, raiz->chave);
  }
}




/*******
Lista as folhas descendentes de um nó x

void folhasDescendentes (no *x); 
*******/

void folhasDescendentes (no *x){
  if (x != NULL){
    if (x->esq == NULL && x->dir == NULL){
      printf("%d %s\n", x->valor, x->chave);
      return;
    }
    folhasDescendentes (x->esq);
    folhasDescendentes (x->dir);
  }
}



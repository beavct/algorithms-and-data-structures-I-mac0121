#include <stdio.h>
#include <stdlib.h>
#include "listasligadas.h"


void imprimeLista (celula * inicio) {
  if (inicio != NULL) {
    printf ("%d ", inicio->info);
    imprimeLista (inicio->prox);
  }
  else printf("\n"); 
}

 
void imprimeListaIterativo (celula * inicio) {
  celula * p;
  for (p = inicio; p != NULL; p = p -> prox)
    printf("%d ", p->info); 
  printf("\n");
} 

celula * busca (celula * inicio, chave x) {
  if (inicio == NULL || inicio -> info == x)
    return inicio;
  return (busca (inicio->prox, x));
}

celula * buscaIterativa (celula * inicio, chave x) {
  celula * p;
  for (p = inicio; p != NULL && p->info != x; p = p->prox);
  return p;
}


celula * insereNoInicio (celula * inicio, chave x){
  celula * novo = malloc(sizeof(celula));
  novo->info = x;
  novo->prox = inicio;
  return (novo);
}



celula * removelista (celula * inicio, chave x){
  celula * p;
  celula * ant;
  celula * cabeca;

  if (inicio->info == x){
    p = inicio->prox;
    free(inicio);
    return p;
  }

  cabeca = inicio;
  ant = inicio;
  for (p = inicio->prox; p->prox != NULL && p->info != x; p = p->prox)
    ant = p;

  if (p->info == x){
    ant->prox = p->prox;
    free(p);
  }
  return(cabeca);

}


celula * insereNoFim (celula * inicio, chave x) {
  celula *novo = malloc(sizeof (celula));
  celula *atual, *ant; 
  novo->info = x;
  novo->prox = NULL; 
  for (atual = inicio, ant = NULL; atual != NULL;
       ant = atual, atual = atual->prox);
  if (ant != NULL)
    ant -> prox = novo;
  else
    inicio = novo;
  return (inicio);
}


celula * insereNoFimRec (celula * inicio, chave x) {
  if (inicio == NULL) {
    inicio = malloc (sizeof(celula));
    inicio->info = x;
    inicio->prox = NULL;
  } 
  else inicio->prox = insereNoFimRec(inicio->prox, x);
  
  return inicio;
} 

  

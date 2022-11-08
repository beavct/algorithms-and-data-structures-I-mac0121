#include <stdlib.h>
#include <stdio.h>
#include "fila.h"

fila * criaFila () {
  fila * f = malloc (sizeof(fila));
  f->max = 2;
  f->ini = f->fim = 0;
  f->v = malloc (f->max * sizeof(item));
  return f;
}


void destroiFila (fila *f) {
  free (f->v);
  free (f); 
}


int filaVazia (fila *f) {
  return (f->fim == f->ini); 
}


item primeiroFila (fila *f) {
  if (!filaVazia(f))
    return (f->v[f->ini]); 
}


void insereFila (fila *f, item x) {
  if ((f->fim + 1) % f->max == f->ini)
    aumentaFila (f);
  f->v[f->fim] = x;
  f->fim = (f->fim + 1) % f->max;
}



item removeFila (fila *f) {
  item primeiro;
  if (!filaVazia(f)){
    primeiro = f->v[f->ini];
    f->ini = (f->ini + 1) % f->max;
    return primeiro;
  }
}


void aumentaFila (fila * f) {
  int i;
  item * w = malloc(2 * f->max * sizeof(item));
  for (i = 0; i < f->max - 1; i++){
    w[i] = f->v[(f->ini + i) % f->max];
  }
  f->ini = 0;
  f->fim = f->max - 1;
  f->max = 2 * f->max;
  free (f->v);
  f->v = w;
}


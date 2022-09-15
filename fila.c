#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

fila *criafila() {
    fila * f = malloc (sizeof(fila));
    f->max = 2;
    f->ini = f->fim = 0;
    f->v = malloc(f->max * sizeof(item));
    return f;
}

void destroifila(fila *f) {
    free(f->v);
    free(f);
}

int filaVazia(fila *f) {
    return(f->ini == f->fim);
}

item primeiroFila(fila *f) {
    if (!filaVazia(f)) {
        return(f->v[f->ini]);
    }
}

void insereFila(fila *f, item x) {
    if ((f->fim + 1) % f->max == f->ini) { 
    // nesse caso a fila tá cheia, fazer resize
        aumentaFila(f);
    }

    f->v[f->fim] = x;
    f->fim = (f->fim + 1) % f->max;
}

void aumentaFila(fila *f) {
    int i;
    item *w = malloc (2 * f->max * sizeof(item));

    for (i = 0; i < f->max - 1; i++) {
    // max - 1, porque vai sempre ter uma posição vazia para fazermos o controle do fim da fila
        w[i] = f->v[(f->ini + 1) % f->max];
    }
    f->ini = 0;
    f->fim = f->max - 1;
    f->max = 2 * f->max;
    free(f->v);
    f->v = w;
}

item removeFila(fila *f) {
    item primeiro;
    if (!filaVazia(f)) {
        primeiro = f->v[f->ini];
        f->ini = (f->ini + 1) % f->max;
        return primeiro;
    }
}


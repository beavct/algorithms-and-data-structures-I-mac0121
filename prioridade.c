/* fila de prioridades começando do indice 0 do vetor */
/* filhos nas posicoes 2i+1 e 2i+2 */
/* pai na posição "piso de (i-1)/2" */

#include <stdio.h>
#include <stdlib.h>
#include "prioridade.h"

int filaPriorVazia (filaPrior *f) {
  return (f->n == 0);
}

void rebaixa (filaPrior * f, int i) {
  int maior, pai, filhoEsq, filhoDir;
  item aux;

  pai = i;
  filhoEsq = 2*i + 1;
  filhoDir = 2*i + 2;

  maior = i;
  if (filhoEsq < f->n && f->vet[filhoEsq].prior > f->vet[maior].prior)
    maior = filhoEsq;

  if (filhoDir < f->n && f->vet[filhoDir].prior > f->vet[maior].prior)
    maior = filhoDir;

  if (maior != pai){
    aux = f->vet[maior];
    f->vet[maior] = f->vet[pai];
    f->vet[pai] = aux;

    f->ind[f->vet[maior].elem] = maior;
    f->ind[f->vet[pai].elem] = pai;
    rebaixa(f, maior);
  }
}

void sobe (filaPrior * f, int i) {
  int pai, filho;
  item aux; 
  filho = i;
  pai = (i - 1)/2;

  if (filho >= 1 && f->vet[filho].prior > f->vet[pai].prior){
    aux = f->vet[pai];
    f->vet[pai] = f->vet[filho];
    f->vet[filho] = aux;

    f->ind[f->vet[pai].elem] = pai;
    f->ind[f->vet[filho].elem] = filho;
    sobe(f, pai);
  }
}





filaPrior * criaFilaPrior (int max, int tam) {
  int i;
  
  filaPrior *f = malloc (sizeof(filaPrior));
  f->vet = malloc (max * sizeof (item));
  f->ind = malloc (tam * sizeof (int));
  for (i = 0; i < tam; i++)
    f->ind[i] = -1; 
  f->n   = 0;
  f->max = max;
  f->tam = tam;
  return f; 
}

filaPrior * resizeFilaPrior (filaPrior * f) {
  item * novo = malloc (2 * f->max * sizeof(item)) ; 
  int i; 
  for (i = 0; i < f->n; i++){
    novo[i] = f->vet[i];
  }
  free (f->vet); 
  f->vet = novo;
  f-> max = 2 * f->max;
  return f; 
} 

void destroiFilaPrioridade (filaPrior * f) {
  free (f->vet);
  free (f->ind);
  free (f); 
} 


int removeFilaPrior (filaPrior * f) {
  int aux;
  if (!filaPriorVazia(f)){
    aux = f->vet[0].elem;
    f->ind[aux] = -1;   /* removi da fila de prioridade */ 
 
    f->vet[0] = f->vet[f->n - 1];
    f->ind[f->vet[0].elem] = 0;
    f->n = f->n - 1;
    rebaixa (f, 0);
    return aux;
  }
} 

void insereFilaPrior (filaPrior *f, item x) {
  if (f->n == f->max)
    resizeFilaPrior (f);
  f->vet[f->n] = x;
  f->ind[x.elem] = f->n;
  f->n = f->n + 1;
  /* corrige pra cima no indice f->n - 1 */
  sobe (f, f->n - 1);
}

void mudaPrior (filaPrior *f, int indice, int novaPrior){
  int auxPrior = f->vet[indice].prior;
  
  f->vet[indice].prior = novaPrior;
    if (auxPrior < novaPrior)
    sobe (f, indice);
  else
    rebaixa (f, indice);
} 



  




/*
int main() {
  item novo;
  int i, j, n;
  filaPrior * f;

  n = 15;
  f  = criaFilaPrior(1,n);
  
  for (i = 0; i < n; i++){
    novo.elem = i;
    novo.prior = 100-i;
    insereFilaPrior(f, novo);
   }
    printf("----------\n");

  
  mudaPrior(f,6,1000);
  
  mudaPrior(f,8,900);
  
  for (i = 0; i < n; i++){
    printf("%d \n",f->vet[i].elem);
  }

    printf("----------\n");
   for (i = 0; i < n; i++){
     j = removeFilaPrior(f);
     
     printf("removido: %d\n",j);
     for (j = 0; j < f->n; j++){
       printf("%d \n",f->vet[j].elem);
     }
     
     printf("*********** \n");
   }
}


*/

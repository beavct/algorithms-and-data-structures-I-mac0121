#include <stdio.h>
#include <stdlib.h> 
#include <limits.h>
#include <time.h>

typedef int item;

typedef struct cel {
  item chave;
  int qtdNiveis;
  struct cel * * prox;
} celula; 


typedef struct skiplist {
  int N;
  int qtdNiveis;
  struct cel * cabeca;
} skiplist;


#define MAX_NIVEIS 6


/* Cria uma skiplist com a "cabeca" tendo 
  - chave = INT_MAX
  - qtdNiveis = 1
  - N = 0
  - todos os ponteiros de todos os MAX_NIVEL níveis são NULL
*/
skiplist * criaSkiplist(skiplist * lista) {
  int i;
  
  celula * cabeca = malloc(sizeof(cabeca));
  lista->cabeca = cabeca;
  lista->N = 0;
  lista->qtdNiveis = 1; 
  cabeca->chave = INT_MAX;
  cabeca->prox  =  malloc(MAX_NIVEIS * sizeof(celula*));

  for (i = 0; i <= MAX_NIVEIS; i++) {
    cabeca->prox[i] = NULL;
  }
  
  return lista;
}


/* cria uma celula nova com um item e k niveis */
celula * novaCelula(item chave, int k) {
  int i;
  celula * x = malloc(sizeof(celula));

  x->prox = malloc(k * sizeof(celula*));
  x->chave = chave;
  x->qtdNiveis = k;
  
  for (i = 0; i < k; i++)
    x->prox[i] = NULL;
  
  return x;
}


/* devolve um numero aleatorio menor ou igual que MAX_NIVEIS */
int nivelAleatorio() {
  int i = 1;
  int j = 1;   /* j é 2^i */

  /* Gera numero aleatorio entre 0 e 1 */
  double t = (double) rand() / (double) RAND_MAX;
 
  while (i < MAX_NIVEIS && t <= (double) 1/ (double)j) {
    j = 2 * j;
    i = i + 1;
   }
  return i;
}


celula * buscaNivel(celula * x, item chave, int k) {
  if (x == NULL)
    return NULL;
  if (chave == x->chave)
    return x;
  if (x->prox[k] == NULL || chave < x->prox[k]->chave) {
    if (k > 0)
      return buscaNivel(x, chave, k - 1);   
    else
      return NULL;
  }
  return buscaNivel(x->prox[k], chave, k);  
}


celula * busca(skiplist * lista, item chave) {
  return buscaNivel(lista->cabeca, chave, lista->qtdNiveis);
}


/* insere uma celula buscando no nivel k */
void insercaoCelula(celula * inicio, celula * x, int k) {

  item chaveBuscada = x->chave;
  if (inicio->prox[k] == NULL || chaveBuscada < inicio->prox[k]->chave) {
    if (k < x->qtdNiveis) {
      x->prox[k] = inicio->prox[k];
      inicio->prox[k] = x;
    }
    if (k > 0)
      insercaoCelula(inicio, x, k-1);
  }
  else {
    insercaoCelula(inicio->prox[k], x, k);
  }
}
    

void insercao(skiplist * lista, item chave) {
  celula * nova;
  nova = novaCelula(chave, nivelAleatorio());
  lista->N = lista->N + 1;
  insercaoCelula(lista->cabeca, nova, lista->qtdNiveis);
}


void imprime(skiplist * lista) {
  int i;
  celula * x = lista->cabeca->prox[0];
  
  for (i = 0; i < lista->N; i++) {
    printf("%d(%d) ", x->chave, x->qtdNiveis);
    x = x->prox[0];
  }
  printf("\n");
}





int main() {


  celula * aux;
  int chave;
  
  skiplist lista;

  srand(time(NULL));
    
  criaSkiplist(&lista);
  insercao(&lista, 2);
  insercao(&lista, 3);
  insercao(&lista, 1);
  insercao(&lista, 4);
  insercao(&lista, 5);
  insercao(&lista, 2);
  insercao(&lista, 1);

  
  
  
  imprime(&lista);


  chave = 10;
  aux = busca(&lista, chave);
  if (aux != NULL)
    printf("busca por %d: encontrado\n", aux->chave);
  else
    printf("busca por %d: NAO encontrado\n", chave);
  
    

  
  
  return 0;
}

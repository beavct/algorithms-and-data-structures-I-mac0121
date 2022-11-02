#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/* Counting sort 

Considere um vetor v com n elementos no intervalo [0,LIMITE) 
(o intervalo é conhecido a priori). Queremos ordenar os elementos 
do vetor em ordem crescente. 

*/
     
#define LIMITE 999
     
void countingsort (int v[], int n) {
  int conta[LIMITE], i;
  int * B = malloc (n * sizeof(int));
  
  for (i = 0; i < LIMITE; i++)
    conta[i] = 0;
  /* C[i] vai guardar qtd ocorrencias de i */
  for (i = 0; i < n; i++)
    conta[v[i]]++;
  
  /* C[i] vai guardar qtd ocorrencias <= i */
  for (i = 1; i < LIMITE; i++)
    conta[i] = conta[i] + conta[i-1];

  for (i = n - 1; i >= 0; i--){
    B[conta[v[i]]-1] = v[i];
    conta[v[i]]--;
  }

   
  /* copia B para A */
  for (i = 0; i < n; i++)
    v[i] = B[i];

  free(B);
}


int main() {
  int i, n = 0;
  int * v;

  /* deve ser executada somente uma vez */
  srand(time(NULL));

  printf("Digite n: ");
  scanf("%d",&n);
  v = malloc (n * sizeof(int));
  
  for (i = 0; i < n; i++)
    v[i] = rand() % LIMITE;
  
  for (i = 0; i < n; i++)
    printf("%d ", v[i]);
  printf("\n\n");

  countingsort(v, n);
  
  for (i = 0; i < n; i++)
    printf("%d ", v[i]);
  printf("\n");
  
  free(v);
  return 0;
}

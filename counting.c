#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/* Counting sort 

Considere um vetor v com n elementos no intervalo [0,LIMITE) 
(o intervalo é conhecido a priori). Queremos ordenar os elementos 
do vetor em ordem crescente. 

*/
     
#define LIMITE 9999
     
void countingsort (int v[], int n) {
  int conta[LIMITE], i, k;
  
  for (i = 0; i < LIMITE; i++)
    conta[i] = 0;
  for (i = 0; i < n; i ++)
    conta[v[i]]++;
  /* na posição conta[i] temos o número de ocorrências de i no vetor v */
  k = 0;
  for (i = 0; i < LIMITE; i++)
    while(conta[i] > 0){
      v[k] = i;
      k++;
      conta[i]--;
    }
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

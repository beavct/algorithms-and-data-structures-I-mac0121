/* Dijkstra pra grafo NAO orientado - com vertice inicial sendo o 0 */

#include <stdio.h> 
#include <stdlib.h> 

#include "prioridade.h"
#include "listasligadas.h"

#define INF 100

int main() {
  filaPrior * f; 
  int i, n, m, u, v, cuv, custo[50][50], dist[50]; 
  item novo; 
  celula * *a;
  celula * w;

  /*
    lê grafo 
    qtd_vert qtd_arestas
    v1 v2 peso_(v1v2)
    v1 v2 peso_(v1v2)
    ...
  */
  
  scanf("%d %d", &n, &m);

  /* aloca vetor de "ponteiros para celula" */
  a = malloc(n * sizeof(celula*));

  /* inicializa as listas */
  for (i = 0; i < n; i++)
    a[i] = NULL;

  
  /* adiciona as arestas na lista de adjacencia */
  for (i = 0; i < m; i++){
    scanf("%d %d %d ", &u, &v, &cuv);
    a[u] = insereNoInicio(a[u], v);
    a[v] = insereNoInicio(a[v], u);
    custo[u][v] = cuv;
    custo[v][u] = cuv;
  }
  printf("** Lista de adjacencias**\n");
  for (i=0; i<n; i++){
    printf("%d: ",i);
    imprimeLista(a[i]);
  }



  

  /* Cria fila de prioridades com 1 elemento e capacidade para n */
  f = criaFilaPrior (1, n);
  /* insere todos menos o inicial na fila de prioridades */
  for (i = 1; i < n; i++){
    novo.elem = i;
    novo.prior = -INF;
    insereFilaPrior(f, novo);
  }
  /* insere vertice 0 na fila de prioridades */
  novo.elem = 0;
  novo.prior = 0;
  insereFilaPrior(f, novo);

  

   
  /* inicializa as distancias */
  for (i = 1; i < n; i++){
    dist[i] = INF;
  }
  dist[0] = 0;


  while (!filaPriorVazia (f)){
    u = removeFilaPrior(f);
    w = a[u];
  
    while (w != NULL){
      
     if (dist[w->info] > dist[u] + custo[u][w->info]){
	mudaPrior(f, f->ind[w->info],  -(dist[u] + custo[u][w->info]));
	dist[w->info] = dist[u] + custo[u][w->info];
      }
      w = w->prox;
    }
  }

  printf("\n\ndistancias: "); 
  for (i = 0; i < n; i++) 
    printf("%3d ", dist[i]);
  printf("\n");

    
  return 0;
} 

/*Aula do dia 01/09/2022
É possível partir com um cavalo de uma dada posição em um tabuleiro n X n e depois de n^2 - 1 movimentos, visitar todas as casas. (ou seja, sem repetir).
Usando backtrack de novo.
Grafo G = conjunto de vértices, interconados dois a dois por arestas.
Problema do caminho Hamiltoniano
Dois vetores (linha e colula) para armazenar os 8 movimentos em L do cavalo, identificação do movimento: indice dos vetores
Pilha: (coordenada x anterior, coordenada y anterior, mov
Não da para fazer um novo movimento e não andou todo o tabuleiro: desempilha a posição antiga e tenta o movimento antigo + 1 a partir dessa posição.
Testou tudo e a pilha ta vazia == não nenhuma solução. */

#include 'pilha.h'
/*Mudanças: typedef struct {
                int linha;
                int coluna;
                int mov;
             } cavalo;

             typedef cavalo item;*/
#include <stdio.h>

cavalo proximo (cavalo atual) {
    cavalo prox;

    int plinha[9] = {0, -2, -1, 1, 2, 2, 1, -1, -2}
    int pcolunq[9] = {0, 1, 2, 2, 1, -1, -2, -2, -1}

    prox.lin = atual.lin + plinha[atual.mov];
    prox.col = atual.col + pcoluna[atual.mov];
    prox.mov = 1;
    /*Convenção: sempre q chegamos em uma nova posição, começamos testando pelo movimento 1*/
    
    return prox; 
}

int pulaCavalo (int ** tab, int n, cavalo x) {
    cavalo prox = proximo(x);
    /*Verificar se a posição é válida*/

    if (prox.lin >= 0 && prox.col >= 0 && prox.lin < n && prox.col < n && tab[prox.lin][prox.col] == 0) {
        return 1
    }
    
    return 0;
}

void passeioCavalo (int n, int lin, int col) {
    pilha * posicoes = cria (n * n); /*não usamos resize (pilha.c)*/
    cavalo atual;
    int ** tab = alocaMatriz(n,n);
    int i, j, ok, npulos; 

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            tab[i][j] = 0;
        }
    }
    atual.lin = lin;
    atual.col = col;
    atual.mov = 1;
    npulos = 0; 
    
    while (npulos < (n * n) - 1) {
        ok = 0;
        
        while (!ok && atual.mov <= 8) {
            if puloCavalo((tab, n, atual)) {
                ok = 1;
            }
            else {
                atual.mov++;
            }
        }
        
        if (ok) {
            npulos++;
            empilha(posicoes, atual);
            tab[atual.lin][atual.col] = npulos;
            atual = proximo(atual);
        }
        else {
            if (pilhaVazia(posicoes)) {
                printf ("Não há passeio");
                liberaMatriz(tab, n);
                destroi(posicoes);
                return;
            }
            else { /*backtrack*/
                atual = desempilha(posicoes);
                atual.mov++;
                tab[atual.lin][atual.col] = 0;
                npulos--;
            }
        }
    }
    npulos++;
    tab[atual.lin][atual.col] = npulos; /*ou n*n*/
    imprimeMatriz (tab);
    liberaMatriz(tab, n);
    destroi(posicoes);
}

int main (int argc, char *argv []) { /*ex: ./cavalo.exe 8 0 0*/
    int l, c, n;
  
    n = atoi (argv[1]);
    l = atoi (argv[2]);
    c = atoi (argv[3]);

    passeioCavalo(n, l, c);
    return 0;
}




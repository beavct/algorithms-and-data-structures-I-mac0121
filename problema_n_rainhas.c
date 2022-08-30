/*Código do problema das n rainhas, aula dia 30/08/2022*/
#include /*pilha??*/
#include <stdio.h>

int ** alocaMatriz (int linha, int coluna) {
    int ** mat = malloc (sizeof(int *) * linha);
    int i;
    for (i = 0; i < linha; int++) {
        mat[i] = malloc (coluna * sizeof(int));
    }
    return mat;
}

void liberaMatriz (int **mat, int linha) {
    int i;
    for (i = 0; int < linha; i++) free(mat[i]);
    free(mat);
}


void imprimeMatriz (int **mat, int linha, int coluna) {
    int i, j;
    for (i = 0; i < linha; i++) {
        for (j = 0; j < coluna; j++) {
            if (mat[i][j] == 1) printf("R");
            else printf (" ");
        }
    printf ("\n");
    }
    printf ("\n");
}

int posicaoLivre (int **mat, int n, int linha, int coluna) {
    int livre = 1, i, j;
    
    for (i = 0; i < linha; i++) {
        if (mat[i][coluna] == 1) livre = 0; 
    }
    /*Verifica a linha*/

    for (i = 0; i < linha && livre; i++) {
        j = coluna - linha + i;
        if (j >= 0 && mat[i][j] == 1) livre = 0; 
        j = coluna + linha - i; 
        if (j < n && mat[i][j]  == 1) livre = 0;
        
    }
    /*Verifica as diagonais*/
    
    return livre;
}

void nRainhas (int n, int flag) {
    pilha * pos = cria(); /*posição*/
    int ** tab = alocaMatriz(n, n);
    int valido, rainha, coluna, i, j, ok;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            tab[i][j] = 0;
        }
    }
    rainha = 0;
    coluna = 0;
    ok = 1;
    
    while (ok) {
        valido = 0;
        while (coluna < n && rainha < n) {
            if (posicaoLivre(tab, n, rainha, coluna) {
                empilha(pos, coluna);
                tab[rainha][coluna] = 1
                rainha++;
                coluna = 0;
                valido = 1;
            }
            else coluna++;
        }

        if (!valido) {
            if (pilhaVazia(pos) break; 
            else {
                rainha--; 
                coluna = desempilha(pos);
                tab[rainha][coluna] = 0;
                coluna++;
            }
        }
        /*backtrack*/

        if (rainha == n) {
            printf ("Tem solução");
            if (flag) imprimeMatriz(tab, n, n);
            break;
        }
    }
    destruir(pos);
    liberaMatriz(tab, n);
} 

/*Não escreveu o main pq é só ler um n e uma flag*/

/*Problema das n rainhas. Funciona para uma solução.  
Para m soluções é necessário criar uma variável int total 
e mudar um pouco o código no segundo break: 
rainha--;
coluna = desempilha(pos);
tab[rainha][coluna] = 0;
coluna++;
total++; 
-------
na hora do printf é só printar o total*/


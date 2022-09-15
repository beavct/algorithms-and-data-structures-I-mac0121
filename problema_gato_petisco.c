//Algoritmo:
//*insere posição do gato na fila.
//* marca essa posição no labirinto com 1.
//*posição atual é a do gato.
//*enquanto atual ≠ posição do petisco:
//   *para cada uma das 4 posições possíveis:
//      *se atual pode andar na direção (**M[i,j] == 0):
//         *prox recebe posição após andar.
//         *marca a quantidade de passos na matriz. 
//         *insere prox na fila.
//   *se fila vazia:
//      *não tem solução.
//   *se fila não vazia:
//      *atual recebe primeira da fila. -> remove


void labirinto (int **lab, int m, int n, pos gato, pos petisco) {
    fila *caminho = criaFila();
    int plinha[4] = [1, 0, -1, 0]
    int pcoluna[4] = [0, 1, 0, -1]
    int d;
    pos atual, prox;

    insereFila(caminho,  gato); //nem precisava colocar na fila, motivos didáticos,  primeiro passo: colocar o gato 
    lab[gato.l][gato.c] = 1;
    atual = removeFila(caminho);

    while (diferente(atual, petisco)) {
        for (d = 0; d < 4; d++) {
            prox.l = atual.l + plinha[d];
            prox.c = atual.c + pcoluna[d];

            if (prox.l >= 0 && prox.l < m && prox.c >= 0 && prox.c < n && lab[prox.l][prox.c]) {
                lab[prox.l][prox.c] = lab[atual.l][atual.c] + 1;
                insereFila(caminho, prox);
            }
        }
        
        if (filaVazia(caminho)) {
            printf("Não tem solução \n");
            destroiFila(caminho);
            return;
        }
        
        atual = removeFila(caminho);
    }
    
    imprimeMatriz(lab, m, n);
    destroiFila(caminho);
}

diferente(pos a, pos b) {
    if ([a.l] == [b.c] && [a.c] == [b.c]) return 1;
    return 0;
}

imprimeMatriz (int **M, m, n) {
    int i, j;

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d", M[i][j]);
        }
        printf("\n");
    }
}

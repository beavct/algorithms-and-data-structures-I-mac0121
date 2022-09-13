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

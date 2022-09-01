/*Aula do dia 01/09/2022*/
/*É possível partir com um cavalo de uma dada posição em um tabuleiro n X n e depois de n^2 - 1 movimentos, visitar todas as casas. (ou seja, sem repetir).*/
/*Usando backtrack de novo.*/
/*Grafo G = conjunto de vértices, interconados dois a dois por arestas.*/
/*Problema do caminho Hamiltoniano*/
/*Dois vetores (linha e colula) para armazenar os 8 movimentos em L do cavalo, identificação do movimento: indice dos vetores*/
/*pilha: (coordenada x anterior, coordenada y anterior, mov n*/
/*Não da para fazer um novo movimento e não andou todo o tabuleiro: desempilha a posição antiga e tenta o movimento antigo + 1 a partir dessa posição. */
/*Testou tudo e a pilha ta vazia == não nenhuma solução. */










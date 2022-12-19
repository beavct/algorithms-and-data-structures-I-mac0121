

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabelaSimbolos.h"

/* Abaixo encontramos as palavras mais frequentes com pelo menos 
   "qtdLetras" letras */


int main() {
  
  int qtdLetras = 3;
  


  no * p = NULL;
  no * aux = NULL;
  int valor = 0;
  
  char palavra[100];

  while (scanf("%[A-Za-z]%*[^a-zA-Z]", palavra) > 0){
    if (strlen(palavra) >= qtdLetras){
      valor = 1;
      aux = busca(p, palavra);
       
      if (aux != NULL)
	valor = ++aux->valor;
           
      p = insercao(p, palavra, valor);
    }
  }

  /* Neste ponto temos nossa tabela de símbolos criada e com as
     frequencias no texto */

  preordem(p);

  free(p);
  return 0;
}


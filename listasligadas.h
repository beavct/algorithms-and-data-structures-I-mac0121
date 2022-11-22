/* Iniciar com celula * p = NULL; */

typedef int chave;

typedef struct cel {
  chave info;
  int indice;
  
  struct cel * prox;
} celula; 


void imprimeLista (celula * inicio);
void imprimeListaIterativo (celula * inicio);
celula * busca (celula * inicio, chave x);
celula * buscaIterativa (celula * inicio, chave x);
celula * insereNoInicio(celula *inicio, chave x);
celula * insereNoFim (celula * inicio, chave x);
celula * insereNoFimRec (celula * inicio, chave x);
celula * removelista (celula * inicio, chave x);
  
  




  




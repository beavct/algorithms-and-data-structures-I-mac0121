typedef int item;

typedef struct cel {
  item info;
  struct cel * prox;
} celula; 


void imprimeLista (celula * inicio);
void imprimeListaIterativo (celula * inicio);
celula * busca (celula * inicio, item x);
celula * buscaIterativa (celula * inicio, item x);
celula * insereNoInicio(celula *inicio, item x);
celula * insereNoFim (celula * inicio, item x);
celula * insereNoFimRec (celula * inicio, item x);
celula * removelista (celula * inicio, item x);
  
  




  




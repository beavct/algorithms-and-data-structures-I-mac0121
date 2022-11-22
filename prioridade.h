typedef struct {
  int elem;
  int prior;
} item;

typedef struct {
  item *vet; /* armazena o heap */
  int  *ind; /* armazena os índices dos elem no heap */ 
  int n;     /* número de elem na fila (heap)     */
  int max;   /* tamanho da fila             */
  int tam;   /* número total de elementos (vetor ind) */
} filaPrior; 

filaPrior * criaFilaPrior (int max, int tam);
filaPrior * resizeFilaPrior (filaPrior * f); 
void destroiFilaPrior (filaPrior * f);
int filaPriorVazia (filaPrior *f); 

int removeFilaPrior (filaPrior * f);
void insereFilaPrior (filaPrior *f, item x);
void mudaPrior (filaPrior *f, int indice, int novapr); 


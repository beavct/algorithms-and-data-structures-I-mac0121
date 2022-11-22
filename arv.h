typedef struct cel {
  char * chave;
  int valor;
  struct cel * esq;
  struct cel * dir; 
} no;

no * minimo (no * raiz);

int contaNo (no *raiz);
int altura (no *raiz);
int ehDescendente (no *x, no *y);


void inordem (no *raiz);
void preordem (no *raiz);
void posordem (no *raiz);
void folhasDescendentes (no *x);


typedef struct {
    item *v;
    int ini;
    int fim;
    int max;
} fila;

typedef struct {
    int l;
    int c;
} pos;

typedef pos item;

fila *criafila();
void destroifila(fila *f);
int filaVazia(fila *f);
item primeiroFila(fila *f);
void insereFila(fila *f, item x);
void aumentaFila(fila *f);
item removeFil(fila *f);

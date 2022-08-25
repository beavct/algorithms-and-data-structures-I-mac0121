/*arquivo de header com as funções necessárias para resolver o problema Bem formado*/
#define ERRO '\0'

typedef char item

typedef struct {
    item *v;
    int topo;
    int max;
} pilha;

void empilha (pilha *p, item x);
item desempilha (pilha *p);
item topoPilha (pilha *p);
int pilhaVazia (pilha *p);
void resize (pilha *p);
void *cria ();
void destroi (pilha *p);

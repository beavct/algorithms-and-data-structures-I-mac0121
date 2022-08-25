/*arquivo com as funções cujo os protótipos estão no pilha.h*/
/*(*p).topo := p->topo */
#include "pilha.h"
#include <stdlib.h>
#include <stdio.h>

int pilhaVazia(pilha *p)
{
    return (p->topo == 0);
}

item topoPilha(pilha *p)
{
    if (!pilhaVazia(p))
        return p->v[p->topo - 1];
    return ERRO;
}

item desempilha(pilha *p)
{
    item aux;
    if (!pilhaVazia(p))
    {
        p->topo = p->topo - 1;
        aux = p->v[p->topo];
        p->[p->topo] = ERRO;
        return aux;
    }
    return ERRO;
}

pilha *cria()
{
    pilha *p = malloc(sizeof(pilha) * p->max);
    p->max = 1;
    p->topo = 0;
    p->v = malloc(p->max * sizeof(item));
    return p;
}

void destroi(pilha *p)
{
    free(p->v);
    free(p);
}

void empilha(pilha *p, item x)
{
    if (p->topo == p->max)
        resize(p);
    p->v[p->topo] = x;
    p->topo++;
}

void resize(pilha *p)
{
    int i;
    item *w = malloc(z * p->max * sizeof(item));
    for (i = 0; i < p->max; i++)
        w[i] = p->v[i];
    p->max = p->max * z;
    free(p->v);
    p->v = w;
}

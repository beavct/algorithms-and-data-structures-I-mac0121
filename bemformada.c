/*Programa principal utilizando a biblioteca pilha.h e o arquivo pilha.c com as funções */
#include <stdio.h>
#include "pilha.h"
#define MAX 1000

int bemformada(char *seq);
int casa(char abre, char fecha);

int main()
{
    char entrada[MAX];

    scanf("%[^\n", entrada);

    if (bemformada(entrada))
        printf("A sequência é bem formada.\n");
    else
        printf("A sequência não é bem formada.\n");

    return 0;
}

int bemformada(char *seq)
{
    int i, bf = 1; /*bem formada (bf) começa verdadeiro. */
    char ctopo;
    pilha *p = cria();

    for (i = 0; seq[i] != '\0' && bf; i++)
    {
        if (seq[i] == '(' || seq[i] == '[' || seq[i] == '{')
        {
            empilha(p, seq[i]);
        }
        else if (seq[i] == ')' || seq[i] == ']' || seq[i] == '}')
        {
            if (pilhaVazia(p))
                bf = 0;
            else
            {
                ctopo = desempilha(p);
                if (!casa(ctopo, seq[i]))
                    bf = 0;
            }
        }
    }

    if (!pilhaVazia(p))
        bf = 0;
    destroi(p);
    return bf;
}

int casa(char abre, char fecha)
{
    if ((abre == '(' && fecha == ')') || (abre == '[' && fecha == ']') || (abre == '{' && fecha == '}'))
        return 1;
    return 0;
}

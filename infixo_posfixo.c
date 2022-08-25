#include <stdio.h>
#include <string.h>
#include "pilha.h"
#define MAX 1000

int operador(char C)
{
    return (C == '(' || C == ')' || C == '+' || C == '-' || C == '*' || C == '/');
}

int precedencia(char C)
{
    if (C == '(')
        return 0;
    if (C == '+' || C == '-')
        return 1;
    return 2; /* se C == ')'*/
}

void posfixa(char exp[])
{
    pilha *pilhaOp = cria() char cTopo;
    int i;

    for (i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == ' ')
            continue; /*caso não usuário coloque espaço em branco, 'continue' continua para a próxima interação do laço*/
        if (!operador(exp[i]))
            printf("%c", exp[i]);
        else if (exp[i] == '(')
            empilha(pilhaOp, exp[i]);
        else if (exp[i] == ')')
            cTopo = desempilha(pilhaOp)
            {
                while (cTopo != '(')
                {
                    printf("%c", cTopo);
                    cTopo = desempilha(pilhaOp);
                }
                else
                { /*leu operador e tem que comparar a precedência */
                    while (!pilhaVazia(pilhaOp) && precedencia(topoPilha(pilhaOp)) = > precedencia(exp[i])))
                        {
                            cTopo = desempilha(pilhaOp);
                            printf("%c", cTopo);
                        }
                    empilha(pilhaOp, exp[i]);
                }
            }

        while (!pilhaVazia(pilhaOp))
        {
            cTopo = desempilha(pilhaOp);
            printf("%c", cTopo);
        }

        printf("\n");
        destroi(pilhaOp);
    }

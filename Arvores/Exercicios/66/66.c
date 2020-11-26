#include <stdio.h>
#include "66.h"

int calcula_tamanho_nao_recurssivo(Arvore *arvore)
{
    Node *node = arvore->raiz;
    Pilha *pilha = cria_pilha();
    int tamanho = 0;

    if (node)
    {
        push(pilha, node);
    }

    while (!vazia(pilha))
    {
        node = pop(pilha);
        tamanho++;

        if (node->esq)
        {
            push(pilha, node->esq);
        }

        if (node->dir)
        {
            push(pilha, node->dir);
        }
    }

    return tamanho;
}

#include <stdio.h>
#include "29.h"

bool busca_nao_recurssiva(Arvore *arvore, int x)
{
    Node *node = arvore->raiz;
    Pilha *pilha = cria_pilha();

    if (node)
    {
        push(pilha, node);
    }

    while (!vazia(pilha))
    {
        node = pop(pilha);

        if (node->valor == x)
        {
            libera_pilha(pilha);
            return true;
        }

        if (node->dir)
        {
            push(pilha, node->dir);
        }

        if (node->esq)
        {
            push(pilha, node->esq);
        }
    }

    libera_pilha(pilha);
    return false;
}

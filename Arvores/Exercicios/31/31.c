#include <stdio.h>
#include "31.h"

bool verifica_abb_nao_recurssiva(Arvore *arvore)
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

        if (node->dir)
        {
            if (node->dir->valor < node->valor)
            {
                libera_pilha(pilha);
                return false;
            }

            push(pilha, node->dir);
        }

        if (node->esq)
        {
            if (node->esq->valor > node->valor)
            {
                libera_pilha(pilha);
                return false;
            }

            push(pilha, node->esq);
        }
    }

    return true;
}

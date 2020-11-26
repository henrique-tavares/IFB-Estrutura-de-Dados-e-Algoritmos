#include <stdio.h>
#include "33.h"

int altura_nao_recurssiva(Arvore *arvore)
{
    Node *node = arvore->raiz, *node_aux = arvore->raiz;
    Pilha *pilha = cria_pilha();
    int tam_pilha_max = -1;

    while (node)
    {
        while (node->esq)
        {
            push(pilha, node);
            node = node->esq;
        }

        tam_pilha_max = (tamanho(pilha) > tam_pilha_max) ? tamanho(pilha) : tam_pilha_max;

        while (node && (!node->dir || node_aux == node->dir))
        {
            if (vazia(pilha))
            {
                return tam_pilha_max;
            }

            node_aux = node;
            node = pop(pilha);
        }

        push(pilha, node);
        node = node->dir;
    }

    return tam_pilha_max;
}

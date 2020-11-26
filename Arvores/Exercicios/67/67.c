#include <stdio.h>
#include "67.h"

void imprime_red_nao_recurssiva(Arvore *arvore)
{
    printf("[ ");

    Node *node = arvore->raiz;
    Pilha *pilha = cria_pilha();

    if (node)
    {
        push(pilha, node);
    }

    while (!vazia(pilha))
    {
        node = pop(pilha);

        printf("%d ", node->valor);

        if (node->dir)
        {
            push(pilha, node->dir);
        }

        if (node->esq)
        {
            push(pilha, node->esq);
        }
    }

    printf("]");
}

void imprime_erd_nao_recurssiva(Arvore *arvore)
{
    printf("[");

    Node *node = arvore->raiz;
    Pilha *pilha = cria_pilha();

    while (node)
    {
        while (node)
        {
            if (node->dir)
            {
                push(pilha, node->dir);
            }
            push(pilha, node);

            node = node->esq;
        }

        if (!vazia(pilha))
        {
            node = pop(pilha);
        }

        while (!vazia(pilha) && !node->dir)
        {
            printf(" %d", node->valor);

            node = pop(pilha);
        }

        printf(" %d", node->valor);

        node = (!vazia(pilha)) ? pop(pilha) : NULL;
    }

    printf(" ]");
}

void imprime_edr_nao_recurssiva(Arvore *arvore)
{
    printf("[");

    Node *node = arvore->raiz, *node_aux = arvore->raiz;
    Pilha *pilha = cria_pilha();

    while (node)
    {
        while (node->esq)
        {
            push(pilha, node);
            node = node->esq;
        }

        while (node && (!node->dir || node->dir == node_aux))
        {
            printf(" %d", node->valor);

            if (vazia(pilha))
            {
                printf(" ]");
                return;
            }

            node_aux = node;
            node = pop(pilha);
        }

        push(pilha, node);
        node = node->dir;
    }
    printf(" ]");
}

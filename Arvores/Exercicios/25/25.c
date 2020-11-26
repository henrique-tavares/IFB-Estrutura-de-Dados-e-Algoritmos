#include <stdio.h>
#include <stdlib.h>
#include "25.h"

int menor_nao_recurssiva(Arvore *arvore)
{
    if (!arvore->raiz)
    {
        perror("\nERRO: Árvore vazia.\n");
        exit(EXIT_FAILURE);
    }

    Node *node = arvore->raiz;
    Pilha *pilha = cria_pilha();
    int menor = node->valor;

    push(pilha, node);

    while (!vazia(pilha))
    {
        node = pop(pilha);

        if (node->valor < menor)
        {
            menor = node->valor;
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

    return menor;
}

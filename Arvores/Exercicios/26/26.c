#include <stdio.h>
#include <stdlib.h>
#include "26.h"

int menor_nao_recurssiva(Arvore *arvore)
{
    if (!arvore->raiz)
    {
        perror("\nERRO: Árvore vazia.\n");
        exit(EXIT_FAILURE);
    }

    int menor = arvore->raiz->valor;
    for (Node *node = arvore->raiz; node != NULL; node = node->esq)
    {
        if (node->valor < menor)
        {
            menor = node->valor;
        }
    }

    return menor;
}

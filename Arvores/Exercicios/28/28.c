#include <stdio.h>
#include <stdlib.h>
#include "28.h"

int _menor_que(Node *node, int x)
{
    if (!node)
    {
        perror("\nNúmero não encontrado\n");
        exit(EXIT_FAILURE);
    }

    if (node->dir && node->dir->valor < x)
    {
        return _menor_que(node->dir, x);
    }

    if (node->valor < x)
    {
        return node->valor;
    }

    return _menor_que(node->esq, x);
}

int menor_que(Arvore *arvore, int x)
{
    return _menor_que(arvore->raiz, x);
}

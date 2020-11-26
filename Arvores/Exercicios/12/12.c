#include <stdio.h>
#include "12.h"

void _espelho(Node *node)
{
    if (node == NULL)
    {
        return;
    }

    Node *swap = NULL;

    swap = node->esq;
    node->esq = node->dir;
    node->dir = swap;

    _espelho(node->esq);
    _espelho(node->dir);
}

void espelho(Arvore *arvore)
{
    _espelho(arvore->raiz);
}

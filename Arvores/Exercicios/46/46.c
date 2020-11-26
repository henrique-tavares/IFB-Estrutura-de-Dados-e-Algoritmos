#include <stdio.h>
#include "46.h"

bool _binaria_estrita(Node *node)
{
    if (node == NULL)
    {
        return true;
    }

    if ((node->esq == NULL) ^ (node->dir == NULL))
    {
        return false;
    }

    return (_binaria_estrita(node->esq) && _binaria_estrita(node->dir));
}

bool binaria_estrita(Arvore *arvore)
{
    return _binaria_estrita(arvore->raiz);
}

#include <stdio.h>
#include "02.h"

int _conta_nodes(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }

    return 1 + _conta_nodes(node->esq) + _conta_nodes(node->dir);
}

int conta_nodes(Arvore *arvore)
{
    return _conta_nodes(arvore->raiz);
}

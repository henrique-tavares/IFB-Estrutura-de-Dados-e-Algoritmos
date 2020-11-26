#include <stdio.h>
#include "36.h"

int _conta_nodes_um_filho(Node *node)
{
    if (!node)
    {
        return 0;
    }

    if ((node->esq == NULL) ^ (node->dir == NULL))
    {
        return 1 + _conta_nodes_um_filho(node->esq) + _conta_nodes_um_filho(node->dir);
    }

    return _conta_nodes_um_filho(node->esq) + _conta_nodes_um_filho(node->dir);
}

int conta_nodes_um_filho(Arvore *arvore)
{
    return _conta_nodes_um_filho(arvore->raiz);
}

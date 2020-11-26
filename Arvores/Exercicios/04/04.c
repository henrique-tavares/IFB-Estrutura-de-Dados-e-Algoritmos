#include <stdio.h>
#include "04.h"

int _conta_nodes_folhas(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    else if (node->folha(node))
    {
        return 1;
    }
    else
    {
        return _conta_nodes_folhas(node->esq) + _conta_nodes_folhas(node->dir);
    }
}

int conta_nodes_folhas(Arvore *arvore)
{
    return _conta_nodes_folhas(arvore->raiz);
}

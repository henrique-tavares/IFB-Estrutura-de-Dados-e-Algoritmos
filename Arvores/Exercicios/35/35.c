#include <stdio.h>
#include "35.h"

int _folhas_qtd(Node *node)
{
    if (!node)
    {
        return 0;
    }

    if (node->folha(node))
    {
        return 1;
    }

    return _folhas_qtd(node->esq) + _folhas_qtd(node->dir);
}

int folhas_qtd(Arvore *arvore)
{
    return _folhas_qtd(arvore->raiz);
}

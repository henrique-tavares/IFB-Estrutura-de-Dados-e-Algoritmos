#include <stdio.h>
#include <stdlib.h>
#include "60.h"

int _divisor_soma_filhos(Node *node)
{
    if (!node)
    {
        return 0;
    }

    return (node->esq != NULL &&
            node->dir != NULL &&
            node->valor != 0 &&
            ((node->esq->valor + node->dir->valor) % node->valor) == 0)
               ? 1 + _divisor_soma_filhos(node->esq) + _divisor_soma_filhos(node->dir)
               : _divisor_soma_filhos(node->esq) + _divisor_soma_filhos(node->dir);
}

int divisor_soma_filhos(Arvore *arvore)
{
    return _divisor_soma_filhos(arvore->raiz);
}

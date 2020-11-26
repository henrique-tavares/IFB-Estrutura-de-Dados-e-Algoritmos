#include <stdio.h>
#include "10.h"

bool _verifica_binaria_busca(Node *node)
{
    if (node == NULL)
    {
        return true;
    }

    if ((node->esq != NULL && (node->esq->valor > node->valor)) || (node->dir != NULL && (node->dir->valor < node->valor)))
    {
        return false;
    }

    return (_verifica_binaria_busca(node->esq) && _verifica_binaria_busca(node->dir));
}

bool verifica_binaria_busca(Arvore *a)
{
    return _verifica_binaria_busca(a->raiz);
}

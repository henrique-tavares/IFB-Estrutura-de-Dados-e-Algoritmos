#include <stdio.h>
#include "16.h"

bool _verifica_abb(Node *node)
{
    if (node == NULL)
    {
        return true;
    }

    if ((node->esq != NULL && (node->esq->valor > node->valor)) || (node->dir != NULL && (node->dir->valor < node->valor)))
    {
        return false;
    }

    return (_verifica_abb(node->esq) && _verifica_abb(node->dir));
}

bool verifica_abb(Arvore *a)
{
    return _verifica_abb(a->raiz);
}

#include <stdio.h>
#include "30.h"

bool _verifica_negativo(Node *node)
{
    if (!node)
    {
        return false;
    }

    return (node->valor < 0) ? true : (_verifica_negativo(node->esq) || _verifica_negativo(node->dir));
}

bool verifica_negativo(Arvore *arvore)
{
    return _verifica_negativo(arvore->raiz);
}

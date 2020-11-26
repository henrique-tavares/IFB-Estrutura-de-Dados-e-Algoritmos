#include <stdio.h>
#include "65.h"

int _soma_nodes_impares(Node *node, int soma, int nivel)
{
    if (!node)
    {
        return soma;
    }

    soma = _soma_nodes_impares(node->esq, soma, nivel + 1);
    soma = _soma_nodes_impares(node->dir, soma, nivel + 1);

    return (nivel % 2 == 1) ? soma + node->valor : soma;
}

int soma_nodes_impares(Arvore *arvore)
{
    return _soma_nodes_impares(arvore->raiz, 0, 0);
}

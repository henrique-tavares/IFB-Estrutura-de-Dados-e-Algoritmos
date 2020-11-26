#include <stdio.h>
#include <stdlib.h>
#include "61.h"

int _ancestral_comum(Node *node, int valor1, int valor2, Node **ancestral)
{
    if (!node)
    {
        return 0;
    }

    if (node->valor == valor1 || node->valor == valor2)
    {
        return 1 + _ancestral_comum(node->esq, valor1, valor2, ancestral) + _ancestral_comum(node->dir, valor1, valor2, ancestral);
    }

    if (_ancestral_comum(node->esq, valor1, valor2, ancestral) + _ancestral_comum(node->dir, valor1, valor2, ancestral) == 2)
    {
        *ancestral = node;
    }

    return _ancestral_comum(node->esq, valor1, valor2, ancestral) + _ancestral_comum(node->dir, valor1, valor2, ancestral);
}

int ancestral_comum(Arvore *arvore, int node1, int node2)
{
    Node *ancestral = NULL;
    _ancestral_comum(arvore->raiz, node1, node2, &ancestral);

    if (ancestral == NULL)
    {
        printf("\nNão foi possível encontrar o ancestral comum entre %d e %d\n", node1, node2);
        exit(EXIT_FAILURE);
    }

    return ancestral->valor;
}

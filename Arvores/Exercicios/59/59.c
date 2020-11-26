#include <stdio.h>
#include "59.h"

void _imprime_nivel(Node *node, int nivel_atual, int nivel)
{
    if (!node)
    {
        return;
    }

    if (nivel_atual == nivel)
    {
        printf(" %d", node->valor);
    }

    if ((nivel_atual + 1) <= nivel)
    {
        _imprime_nivel(node->esq, nivel_atual + 1, nivel);
        _imprime_nivel(node->dir, nivel_atual + 1, nivel);
    }
}

void imprime_nivel(Arvore *arvore, int nivel)
{
    printf("[");
    _imprime_nivel(arvore->raiz, 0, nivel);
    printf(" ]");
}

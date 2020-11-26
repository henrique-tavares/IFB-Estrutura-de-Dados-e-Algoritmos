#include <stdio.h>
#include <stdlib.h>
#include "08.h"

void _exclui_pares(Node **node)
{
    if (*node == NULL)
    {
        return;
    }

    if ((*node)->valor % 2 == 0)
    {
        (*node)->libera(*node);
        *node = NULL;
        return;
    }

    _exclui_pares(&((*node)->esq));
    _exclui_pares(&((*node)->dir));
}

void exclui_pares(Arvore *arvore)
{
    _exclui_pares(&(arvore->raiz));
}

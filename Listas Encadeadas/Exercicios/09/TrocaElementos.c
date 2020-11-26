#include <stdio.h>
#include <stdlib.h>
#include "TrocaElementos.h"

bool troca_elementos(Lista *lista, int v1, int v2)
{
    Elemento *e1 = busca(lista, v1), *e2 = busca(lista, v2);

    if (e1 == NULL || e2 == NULL)
    {
        return false;
    }

    e1->valor = v2;
    e2->valor = v1;

    return true;
}

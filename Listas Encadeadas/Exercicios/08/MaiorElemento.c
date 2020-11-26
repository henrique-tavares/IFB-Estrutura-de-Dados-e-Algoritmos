#include <stdio.h>
#include <stdlib.h>
#include "MaiorElemento.h"

bool maior_elemento(Lista *lista, int *maior, int *pos)
{
    if (vazio(lista))
    {
        return false;
    }

    int i = 0;
    for (Elemento *e = lista->primeiro; e != NULL; e = e->prox, i++)
    {
        if (e == lista->primeiro || e->valor > *maior)
        {
            *pos = i;
            *maior = e->valor;
        }
    }

    return true;
}

#include <stdio.h>
#include <stdlib.h>
#include "RetiraElementos.h"

bool retira_elementos(Lista *lista, int n)
{
    if (n < 0 || n > lista->tamanho)
    {
        return false;
    }

    for (int i = 0; i < n; i++)
    {
        Elemento *e = lista->primeiro;
        lista->primeiro = lista->primeiro->prox;

        lista->tamanho--;

        libera_elemento(e);
    }

    return true;
}

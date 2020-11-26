#include <stdio.h>
#include <stdlib.h>
#include "ConcatenaLista.h"

Lista *concatena_lista(Lista *lista1, Lista *lista2)
{
    Lista *lista = cria_lista();
    Elemento *atual = NULL;

    for (Elemento *e = lista1->primeiro; e != NULL; e = e->prox)
    {
        Elemento *aux = cria_elemento(e->valor);

        if (vazio(lista))
        {
            lista->primeiro = aux;
            atual = aux;
        }
        else
        {
            atual->prox = aux;
            atual = aux;
        }
    }

    for (Elemento *e = lista2->primeiro; e != NULL; e = e->prox)
    {
        Elemento *aux = cria_elemento(e->valor);

        if (vazio(lista))
        {
            lista->primeiro = aux;
            atual = aux;
        }
        else
        {
            atual->prox = aux;
            atual = aux;
        }
    }

    return lista;
}

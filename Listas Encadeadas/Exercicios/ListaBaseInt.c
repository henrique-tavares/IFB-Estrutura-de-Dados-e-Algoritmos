#include <stdio.h>
#include <stdlib.h>
#include "ListaBaseInt.h"

Elemento *cria_elemento(int valor)
{
    Elemento *elemento = (Elemento *)malloc(sizeof(Elemento));

    if (elemento == NULL)
    {
        printf("\nERRO: Memória insuficiente!\n");
        exit(1);
    }

    elemento->prox = NULL;
    elemento->valor = valor;

    return elemento;
}

void libera_elemento(Elemento *elemento)
{
    elemento->prox = NULL;
    free(elemento);
}

Lista *cria_lista()
{
    Lista *lista = (Lista *)malloc(sizeof(Lista));

    if (lista == NULL)
    {
        printf("\nERRO: Memória insuficiente!\n");
        exit(1);
    }

    lista->primeiro = NULL;
    lista->tamanho = 0;

    return lista;
}

void libera_lista(Lista *lista)
{
    for (Elemento *e = NULL; lista->primeiro != NULL; libera_elemento(e))
    {
        e = lista->primeiro;
        lista->primeiro = lista->primeiro->prox;
    }

    free(lista);
}

bool contem(Lista *lista, int valor)
{
    for (Elemento *e = lista->primeiro; e != NULL; e = e->prox)
    {
        if (e->valor == valor)
        {
            return true;
        }
    }

    return false;
}

void listar(Lista *lista)
{
    printf("\n[ ");

    for (Elemento *e = lista->primeiro; e != NULL; e = e->prox)
    {
        printf("%d ", e->valor);
    }

    printf("]\n");
}

void insere(Lista *lista, int valor)
{
    Elemento *elemento = cria_elemento(valor);

    elemento->prox = lista->primeiro;
    lista->primeiro = elemento;

    lista->tamanho++;
}

void retira(Lista *lista, int valor)
{
    if (vazio(lista))
        return;

    if (lista->primeiro->valor == valor)
    {
        Elemento *e = lista->primeiro;

        lista->primeiro = lista->primeiro->prox;
        libera_elemento(e);

        lista->tamanho--;
        return;
    }

    for (Elemento *ant = lista->primeiro, *e = lista->primeiro->prox; e != NULL; ant = e, e = e->prox)
    {
        if (e->valor == valor)
        {
            ant->prox = e->prox;
            libera_elemento(e);

            lista->tamanho--;
            return;
        }
    }

    printf("\nO valor %d já não está na lista\n", valor);
}

Elemento *busca(Lista *lista, int busca)
{
    for (Elemento *e = lista->primeiro; e != NULL; e = e->prox)
    {
        if (e->valor == busca)
        {
            return e;
        }
    }

    printf("\nO valor %d não foi encontrado\n", busca);
    return NULL;
}

bool vazio(Lista *lista)
{
    return (lista->primeiro == NULL) ? true : false;
}
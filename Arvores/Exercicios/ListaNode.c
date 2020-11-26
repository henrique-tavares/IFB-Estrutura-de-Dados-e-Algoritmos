#include <stdio.h>
#include <stdlib.h>
#include "ListaNode.h"

Elemento *cria_elemento(Node *valor)
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

void listar(Lista *lista)
{
    printf("[ ");

    for (Elemento *e = lista->primeiro; e != NULL; e = e->prox)
    {
        printf("%d ", e->valor->valor);
    }

    printf("]");
}

void insere(Lista *lista, Node *valor)
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

    if (lista->primeiro->valor->valor == valor)
    {
        Elemento *e = lista->primeiro;

        lista->primeiro = lista->primeiro->prox;
        libera_elemento(e);

        lista->tamanho--;
        return;
    }

    for (Elemento *ant = lista->primeiro, *e = lista->primeiro->prox; e != NULL; ant = e, e = e->prox)
    {
        if (e->valor->valor == valor)
        {
            ant->prox = e->prox;
            libera_elemento(e);

            lista->tamanho--;
            return;
        }
    }

    printf("\nO valor %d já não está na lista\n", valor);
}

bool vazio(Lista *lista)
{
    return (lista->primeiro == NULL) ? true : false;
}
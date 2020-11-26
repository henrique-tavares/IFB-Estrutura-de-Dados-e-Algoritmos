#include <stdio.h>
#include <stdlib.h>
#include "ListaPoligono.h"

Elemento *cria_elemento(float x, float y)
{
    Elemento *elemento = (Elemento *)malloc(sizeof(Elemento));

    if (elemento == NULL)
    {
        printf("\nERRO: Memória insuficiente!\n");
        exit(1);
    }

    elemento->ant = NULL;
    elemento->prox = NULL;

    elemento->vertice = (Vertice *)malloc(sizeof(Vertice));

    if (elemento->vertice == NULL)
    {
        printf("\nERRO: Memória insuficiente!\n");
        exit(1);
    }

    elemento->vertice->x = x;
    elemento->vertice->y = y;

    return elemento;
}

void libera_elemento(Elemento *elemento)
{
    elemento->ant = NULL;
    elemento->prox = NULL;
    free(elemento->vertice);
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
    while (lista->tamanho > 0)
    {
        apaga_vertice(lista, 0);
    }

    free(lista);
}

bool contem(Lista *lista, float x, float y)
{
    if (vazio(lista))
    {
        return false;
    }

    Elemento *e = lista->primeiro;
    do
    {
        if (e->vertice->x == x && e->vertice->y == y)
        {
            return true;
        }

        e = e->prox;

    } while (e != lista->primeiro);

    return false;
}

void listar(Lista *lista)
{
    printf("\n[ ");

    Elemento *e = lista->primeiro;
    do
    {
        printf("(%.1f, %.1f) ", e->vertice->x, e->vertice->y);

        e = e->prox;

    } while (e != lista->primeiro);

    printf("]\n");
}

void adiciona_vertice(Lista *lista, float x, float y)
{
    if (contem(lista, x, y))
    {
        printf("\nO vértice (%.1f, %.1f) já existe na lista\n", x, y);
        return;
    }

    Elemento *novo = cria_elemento(x, y);

    if (vazio(lista))
    {
        lista->primeiro = novo;
        lista->primeiro->ant = lista->primeiro;
        lista->primeiro->prox = lista->primeiro;
    }
    else
    {
        novo->ant = lista->primeiro->ant;
        novo->prox = lista->primeiro;

        lista->primeiro->ant->prox = novo;
        lista->primeiro->ant = novo;
    }

    lista->tamanho++;
}

void insere_vertice(Lista *lista, float x, float y, int pos)
{
    if (pos < 0 || pos >= lista->tamanho)
    {
        printf("\nERRO: Posição inválida\n");
        return;
    }

    if (contem(lista, x, y))
    {
        printf("\nO vértice (%.1f, %.1f) já existe na lista\n", x, y);
        return;
    }

    Elemento *novo = cria_elemento(x, y);

    if (pos == 0)
    {
        Elemento *primeiro = lista->primeiro;
        Elemento *primeiro_ant = lista->primeiro->ant;

        novo->ant = primeiro_ant;
        novo->prox = primeiro;

        primeiro_ant->prox = novo;
        primeiro->ant = novo;

        lista->primeiro = novo;
        lista->tamanho++;

        return;
    }

    Elemento *e = lista->primeiro->prox;
    for (int i = 1; i < pos; i++)
    {
        e = e->prox;
    }

    novo->ant = e->ant;
    novo->prox = e;

    e->ant->prox = novo;
    e->ant = novo;

    lista->tamanho++;
}

void apaga_vertice(Lista *lista, int pos)
{
    if (pos < 0 || pos >= lista->tamanho)
    {
        return;
    }

    if (pos == 0)
    {
        Elemento *e = lista->primeiro;
        Elemento *primeiro_prox = lista->primeiro->prox;
        Elemento *primeiro_ant = lista->primeiro->ant;

        primeiro_prox->ant = primeiro_ant;
        primeiro_ant->prox = primeiro_prox;

        lista->primeiro = primeiro_prox;
        lista->tamanho--;

        libera_elemento(e);
        return;
    }
    else
    {
        Elemento *e = lista->primeiro->prox;
        for (int i = 1; i < pos; i++)
        {
            e = e->prox;
        }

        Elemento *e_prox = e->prox;
        Elemento *e_ant = e->ant;

        e_prox->ant = e_ant;
        e_ant->prox = e->prox;

        lista->tamanho--;

        libera_elemento(e);
        return;
    }
}

void remove_vertice(Lista *lista, float x, float y)
{
    if (vazio(lista))
    {
        return;
    }

    if (lista->primeiro->vertice->x == x && lista->primeiro->vertice->y == y)
    {
        apaga_vertice(lista, 0);
        return;
    }

    Elemento *e = lista->primeiro;
    for (int i = 0; i < lista->tamanho; i++)
    {
        if (e->vertice->x == x && e->vertice->y == y)
        {
            apaga_vertice(lista, i);
            return;
        }

        e = e->prox;
    }

    printf("\nO vértice (%.1f, %.1f) já não está na lista\n", x, y);
}

bool vazio(Lista *lista)
{
    return (lista->primeiro == NULL) ? true : false;
}

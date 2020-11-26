#include <stdlib.h>
#include <stdio.h>
#include "FilaListaNode.h"

Fila *cria_fila()
{
	Fila *fila = (Fila *)malloc(sizeof(Fila));

	if (fila == NULL)
	{
		printf("\nErro: Memória insuficiente!\n");
		exit(1);
	}

	fila->primeiro = NULL;
	fila->ultimo = NULL;
	fila->tam = 0;

	return fila;
}

void libera_fila(Fila *fila)
{
	while (!vazia(fila))
	{
		dequeue(fila);
	}

	free(fila);
}

ElementoLista *cria_elemento_lista(Lista *lista)
{
	ElementoLista *elemento = (ElementoLista *)malloc(sizeof(ElementoLista));

	if (elemento == NULL)
	{
		printf("\nErro: Memória insuficiente!\n");
		exit(1);
	}

	elemento->lista = lista;
	elemento->ant = NULL;
	elemento->prox = NULL;

	return elemento;
}

void libera_elemento_lista(ElementoLista *elemento)
{
	elemento->ant = NULL;
	elemento->prox = NULL;
	free(elemento);
}

void enqueue(Fila *fila, Lista *valor)
{
	ElementoLista *new_ultimo = cria_elemento_lista(valor);

	if (vazia(fila))
	{
		fila->primeiro = new_ultimo;
	}
	else
	{
		new_ultimo->prox = fila->ultimo;
		fila->ultimo->ant = new_ultimo;
	}

	fila->ultimo = new_ultimo;
	fila->tam++;
}

Lista *dequeue(Fila *fila)
{
	if (vazia(fila))
	{
		printf("\nErro: Fila vazia!\n");
		exit(1);
	}

	ElementoLista *old_primeiro = fila->primeiro;

	fila->primeiro = fila->primeiro->ant;
	fila->tam--;

	if (fila->primeiro == NULL)
	{
		fila->ultimo = NULL;
	}
	else
	{
		fila->primeiro->prox = NULL;
	}

	Lista *old_primeiro_lista = old_primeiro->lista;

	libera_elemento_lista(old_primeiro);

	return old_primeiro_lista;
}

Lista *first(Fila *fila)
{
	if (vazia(fila))
	{
		printf("\nErro: Fila vazia!\n");
		exit(1);
	}

	return fila->primeiro->lista;
}

Lista *last(Fila *fila)
{
	if (vazia(fila))
	{
		printf("\nErro: Fila vazia!\n");
		exit(1);
	}

	return fila->ultimo->lista;
}

int tamanho(Fila *fila)
{
	return fila->tam;
}

bool vazia(Fila *fila)
{
	return (fila->primeiro == NULL && fila->ultimo == NULL) ? true : false;
}

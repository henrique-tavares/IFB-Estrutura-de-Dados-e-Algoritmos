#include <stdlib.h>
#include <stdio.h>
#include "FilaNode.h"

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

Elemento *cria_elemento(Node *valor)
{
	Elemento *elemento = (Elemento *)malloc(sizeof(Elemento));

	if (elemento == NULL)
	{
		printf("\nErro: Memória insuficiente!\n");
		exit(1);
	}

	elemento->valor = valor;
	elemento->ant = NULL;
	elemento->prox = NULL;

	return elemento;
}

void libera_elemento(Elemento *elemento)
{
	elemento->ant = NULL;
	elemento->prox = NULL;
	free(elemento);
}

void enqueue(Fila *fila, Node *valor)
{
	Elemento *new_ultimo = cria_elemento(valor);

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

Node *dequeue(Fila *fila)
{
	if (vazia(fila))
	{
		printf("\nErro: Fila vazia!\n");
		exit(1);
	}

	Elemento *old_primeiro = fila->primeiro;

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

	Node *old_primeiro_valor = old_primeiro->valor;

	libera_elemento(old_primeiro);

	return old_primeiro_valor;
}

Node *first(Fila *fila)
{
	if (vazia(fila))
	{
		printf("\nErro: Fila vazia!\n");
		exit(1);
	}

	return fila->primeiro->valor;
}

Node *last(Fila *fila)
{
	if (vazia(fila))
	{
		printf("\nErro: Fila vazia!\n");
		exit(1);
	}

	return fila->ultimo->valor;
}

int tamanho(Fila *fila)
{
	return fila->tam;
}

bool vazia(Fila *fila)
{
	return (fila->primeiro == NULL && fila->ultimo == NULL) ? true : false;
}

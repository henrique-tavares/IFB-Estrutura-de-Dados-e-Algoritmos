#include <stdlib.h>
#include <stdio.h>
#include "Fila.h"

Fila *cria_fila()
{
	Fila *fila = (Fila *)malloc(sizeof(Fila));

	if (fila == NULL)
	{
		printf("\nErro: Memória insufiente!\n");
		exit(1);
	}

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

Elemento *cria_elemento(int valor)
{
	Elemento *elemento = (Elemento *)malloc(sizeof(Elemento));

	if (elemento == NULL)
	{
		printf("\nErro: Memória insuficiente!\n");
		exit(1);
	}

	elemento->valor = valor;
	elemento->prox = NULL;

	return elemento;
}

void libera_elemento(Elemento *elemento)
{
	elemento->prox = NULL;
	free(elemento);
}

void enqueue(Fila *fila, int valor)
{
	Elemento *new_ultimo = cria_elemento(valor);

	if (vazia(fila))
	{
		fila->ultimo = new_ultimo;
		fila->ultimo->prox = fila->ultimo;
	}
	else
	{
		new_ultimo->prox = fila->ultimo->prox;
		fila->ultimo->prox = new_ultimo;

		fila->ultimo = new_ultimo;
	}

	fila->tam++;
}

int dequeue(Fila *fila)
{
	if (vazia(fila))
	{
		printf("\nErro: Fila vazia!\n");
		exit(1);
	}

	Elemento *old_primeiro = fila->ultimo->prox;

	fila->ultimo->prox = fila->ultimo->prox->prox;
	fila->tam--;

	int old_primeiro_valor = old_primeiro->valor;

	libera_elemento(old_primeiro);

	if (fila->tam == 0)
	{
		fila->ultimo = NULL;
	}

	return old_primeiro_valor;
}

int first(Fila *fila)
{
	if (vazia(fila))
	{
		printf("\nErro: Memória insuficiente!\n");
		exit(1);
	}

	return fila->ultimo->prox->valor;
}

int last(Fila *fila)
{
	if (vazia(fila))
	{
		printf("\nErro: Memória insuficiente!\n");
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
	return (fila->ultimo == NULL) ? true : false;
}

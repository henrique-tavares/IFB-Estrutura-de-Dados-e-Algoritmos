#include <stdlib.h>
#include <stdio.h>
#include "Fila.h"

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
	while (!fila_vazia(fila))
	{
		dequeue(fila);
	}

	free(fila);
}

FilaElemento *fila_cria_elemento(int valor)
{
	FilaElemento *elemento = (FilaElemento *)malloc(sizeof(FilaElemento));

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

void fila_libera_elemento(FilaElemento *elemento)
{
	elemento->ant = NULL;
	elemento->prox = NULL;
	free(elemento);
}

void enqueue(Fila *fila, int valor)
{
	FilaElemento *new_ultimo = fila_cria_elemento(valor);

	new_ultimo->prox = fila->ultimo;

	if (fila_vazia(fila))
	{
		fila->primeiro = new_ultimo;
	}
	else
	{
		fila->ultimo->ant = new_ultimo;
	}

	fila->ultimo = new_ultimo;
	fila->tam++;
}

int dequeue(Fila *fila)
{
	if (fila_vazia(fila))
	{
		printf("\nErro: Fila vazia!\n");
		exit(1);
	}

	FilaElemento *old_primeiro = fila->primeiro;

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

	int old_primeiro_valor = old_primeiro->valor;

	fila_libera_elemento(old_primeiro);

	return old_primeiro_valor;
}

int first(Fila *fila)
{
	if (fila_vazia(fila))
	{
		printf("\nErro: Fila vazia!\n");
		exit(1);
	}

	return fila->primeiro->valor;
}

int last(Fila *fila)
{
	if (fila_vazia(fila))
	{
		printf("\nErro: Fila vazia!\n");
		exit(1);
	}

	return fila->ultimo->valor;
}

int fila_tamanho(Fila *fila)
{
	return fila->tam;
}

bool fila_vazia(Fila *fila)
{
	return (fila->primeiro == NULL && fila->ultimo == NULL) ? true : false;
}

void fila_imprime(Fila *fila)
{
	FilaElemento *e = fila->primeiro;

	printf("\n[ ");
	for (int i = 0; i < fila->tam; i++)
	{
		printf("%d ", e->valor);

		e = e->ant;
	}
	printf("]\n");
}

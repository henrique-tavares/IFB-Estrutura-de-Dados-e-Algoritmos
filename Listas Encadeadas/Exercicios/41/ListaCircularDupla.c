#include <stdio.h>
#include <stdlib.h>
#include "ListaCircularDupla.h"

Elemento *cria_elemento(int valor)
{
	Elemento *elemento = (Elemento *)malloc(sizeof(Elemento));

	if (elemento == NULL)
	{
		printf("\nERRO: Memória insuficiente\n");
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

Lista *cria_lista()
{
	Lista *lista = (Lista *)malloc(sizeof(Lista));

	if (lista == NULL)
	{
		printf("\nERRO: Memória insuficiente\n");
		exit(1);
	}

	lista->primeiro = NULL;
	lista->ultimo = NULL;
	lista->tamanho = 0;
}

void libera_lista(Lista *lista)
{
	for (Elemento *e = NULL; lista->primeiro != lista->ultimo; libera_elemento(e))
	{
		Elemento *primeiro = lista->primeiro;
		Elemento *ultimo = lista->ultimo;

		e = primeiro;

		primeiro->prox->ant = ultimo;
		ultimo->prox = primeiro->prox;

		primeiro = primeiro->prox;
	}

	lista->primeiro->ant = NULL;
	lista->primeiro->prox = NULL;

	free(lista->primeiro);

	free(lista);
}

void adiciona(Lista *lista, int valor)
{
	Elemento *elemento = cria_elemento(valor);

	if (vazio(lista))
	{
		lista->primeiro = elemento;
		lista->ultimo = elemento;

		lista->primeiro->ant = lista->ultimo;
		lista->primeiro->prox = lista->ultimo;

		lista->ultimo->prox = lista->primeiro;
		lista->ultimo->ant = lista->primeiro;
	}
	else
	{
		elemento->prox = lista->primeiro;
		lista->primeiro->ant = elemento;

		elemento->ant = lista->ultimo;
		lista->ultimo->prox = elemento;

		lista->primeiro = elemento;
	}

	lista->tamanho++;
}

void retira(Lista *lista, int valor)
{
	if (vazio(lista))
	{
		return;
	}

	Elemento *e = lista->primeiro;
	do
	{
		if (e->valor == valor)
		{
			Elemento *aux = e;

			if (e == lista->primeiro)
			{
				lista->primeiro->prox->ant = lista->ultimo;
				lista->ultimo->prox = lista->primeiro->prox;

				lista->primeiro = lista->primeiro->prox;
			}
			else if (e == lista->ultimo)
			{
				lista->primeiro->ant = lista->ultimo->ant;
				lista->ultimo->ant->prox = lista->primeiro;

				lista->ultimo = lista->ultimo->ant;
			}
			else
			{
				e->ant->prox = e->prox;
				e->prox->ant = e->ant;
			}

			lista->tamanho--;
			libera_elemento(aux);

			return;
		}

		e = e->prox;
	} while (e != lista->primeiro);
}

void imprime(Lista *lista)
{
	if (vazio(lista))
	{
		printf("\n[ ]\n");
		return;
	}

	printf("\n[ ");

	Elemento *e = lista->primeiro;

	do
	{
		if (e == lista->primeiro)
		{
			printf("%d", e->valor);
		}
		else
		{
			printf(", %d", e->valor);
		}

		e = e->prox;
	} while (e != lista->primeiro);

	printf(" ]\n");
}

bool contem(Lista *lista, int valor)
{
	if (vazio(lista))
	{
		return false;
	}

	Elemento *e = lista->primeiro;

	do
	{
		if (e->valor == valor)
		{
			return true;
		}

		e = e->prox;
	} while (e != lista->primeiro);

	return false;
}

Elemento *busca(Lista *lista, int valor)
{
	if (vazio(lista))
	{
		return NULL;
	}

	Elemento *e = lista->primeiro;

	do
	{
		if (e->valor == valor)
		{
			return e;
		}

		e = e->prox;
	} while (e != lista->primeiro);

	return NULL;
}

int tamanho(Lista *lista)
{
	return lista->tamanho;
}

bool vazio(Lista *lista)
{
	return (lista->primeiro == NULL) ? true : false;
}

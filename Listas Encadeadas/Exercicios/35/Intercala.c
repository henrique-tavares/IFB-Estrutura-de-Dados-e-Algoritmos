#include <stdio.h>
#include <stdlib.h>
#include "Intercala.h"

Elemento *_insere(Lista *lista, Elemento *e, int valor)
{
	Elemento *aux = cria_elemento(valor);

	if (vazio(lista))
	{
		lista->primeiro = aux;
		e = aux;
	}
	else
	{
		e->prox = aux;
		e = aux;
	}

	lista->tamanho++;

	return e;
}

Lista *intercala(Lista *l1, Lista *l2)
{
	Lista *l3 = cria_lista();
	Elemento *e3 = NULL;

	Elemento *e1 = l1->primeiro;
	Elemento *e2 = l2->primeiro;

	while (e1 != NULL && e2 != NULL)
	{
		e3 = _insere(l3, e3, e1->valor);
		e3 = _insere(l3, e3, e2->valor);

		e1 = e1->prox;
		e2 = e2->prox;
	}

	while (e1 != NULL)
	{
		e3 = _insere(l3, e3, e1->valor);

		e1 = e1->prox;
	}

	while (e2 != NULL)
	{
		e3 = _insere(l3, e3, e2->valor);

		e2 = e2->prox;
	}

	return l3;
}

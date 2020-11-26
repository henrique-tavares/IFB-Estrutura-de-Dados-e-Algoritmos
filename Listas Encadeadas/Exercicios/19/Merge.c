#include <stdio.h>
#include <stdlib.h>
#include "Merge.h"

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

Lista *merge(Lista *l1, Lista *l2)
{
	Lista *lm = cria_lista();

	Elemento *em = NULL, *e1 = l1->primeiro, *e2 = l2->primeiro;

	while (e1 != NULL && e2 != NULL)
	{
		if (e1->valor < e2->valor)
		{
			em = _insere(lm, em, e1->valor);

			e1 = e1->prox;
		}
		else if (e2->valor < e1->valor)
		{
			em = _insere(lm, em, e2->valor);

			e2 = e2->prox;
		}
		else
		{
			em = _insere(lm, em, e1->valor);
			em = _insere(lm, em, e2->valor);

			e1 = e1->prox;
			e2 = e2->prox;
		}
	}

	while (e1 != NULL)
	{
		em = _insere(lm, em, e1->valor);
		e1 = e1->prox;
	}

	while (e2 != NULL)
	{
		em = _insere(lm, em, e2->valor);
		e2 = e2->prox;
	}

	return lm;
}

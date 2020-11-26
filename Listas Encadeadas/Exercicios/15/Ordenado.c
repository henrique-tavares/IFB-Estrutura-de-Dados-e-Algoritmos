#include <stdio.h>
#include <stdlib.h>
#include "Ordenado.h"

bool crescente(Lista *lista)
{
	for (Elemento *ant = lista->primeiro, *atual = lista->primeiro->prox; atual != NULL; ant = atual, atual = atual->prox)
	{
		if (atual->valor < ant->valor)
		{
			return false;
		}
	}

	return true;
}

bool decrescente(Lista *lista)
{
	for (Elemento *ant = lista->primeiro, *atual = lista->primeiro->prox; atual != NULL; ant = atual, atual = atual->prox)
	{
		if (atual->valor > ant->valor)
		{
			return false;
		}
	}

	return true;
}

bool ordenado(Lista *lista)
{
	if (vazio(lista))
	{
		return false;
	}

	if (crescente(lista) || decrescente(lista))
	{
		return true;
	}

	return false;
}

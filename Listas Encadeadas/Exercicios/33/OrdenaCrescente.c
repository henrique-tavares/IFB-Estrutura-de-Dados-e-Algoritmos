#include <stdio.h>
#include <stdlib.h>
#include "OrdenaCrescente.h"

bool testa_ordem(Lista *lista)
{
	for (Elemento *ant = lista->primeiro, *atual = lista->primeiro->prox; atual != NULL; ant = atual, atual = atual->prox)
	{
		if (ant->valor > atual->valor)
		{
			return false;
		}
	}

	return true;
}

void ordena_crescente(Lista *lista)
{
	if (vazio(lista))
	{
		return;
	}

	while (!testa_ordem(lista))
	{
		for (Elemento *ant = lista->primeiro, *atual = lista->primeiro->prox; atual != NULL; ant = atual, atual = atual->prox)
		{
			if (ant->valor > atual->valor)
			{
				int aux = ant->valor;
				ant->valor = atual->valor;
				atual->valor = aux;
			}
		}
	}
}

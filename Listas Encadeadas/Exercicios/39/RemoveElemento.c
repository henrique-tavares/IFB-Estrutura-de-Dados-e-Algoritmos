#include <stdio.h>
#include <stdlib.h>
#include "RemoveElemento.h"

bool remove_elemento(Lista *lista, int k)
{
	if (k < 0 || k >= lista->tamanho)
	{
		return false;
	}

	int i = 0;
	for (Elemento *ant = NULL, *atual = lista->primeiro; atual != NULL; ant = atual, atual = atual->prox, i++)
	{
		if (i == k)
		{
			Elemento *aux = atual;

			if (atual == lista->primeiro)
			{
				lista->primeiro = lista->primeiro->prox;
			}
			else
			{
				ant->prox = atual->prox;
			}

			lista->tamanho--;
			libera_elemento(aux);

			return true;
		}
	}
}

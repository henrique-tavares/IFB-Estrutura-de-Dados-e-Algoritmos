#include <stdio.h>
#include <stdlib.h>
#include "ListaPares.h"

Lista *lista_pares(Lista *lista)
{
	if (vazio(lista))
	{
		return NULL;
	}

	Lista *lista_pares = cria_lista();
	Elemento *atual = NULL;

	for (Elemento *e = lista->primeiro; e != NULL; e = e->prox)
	{
		if (e->valor % 2 == 0)
		{
			Elemento *aux = cria_elemento(e->valor);

			if (vazio(lista_pares))
			{
				lista_pares->primeiro = aux;
				atual = aux;
			}
			else
			{
				atual->prox = aux;
				atual = aux;
			}
		}
	}

	return lista_pares;
}

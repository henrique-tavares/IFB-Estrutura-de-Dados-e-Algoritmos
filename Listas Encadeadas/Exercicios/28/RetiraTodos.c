#include <stdio.h>
#include <stdlib.h>
#include "RetiraTodos.h"

void retira_todos(Lista *lista, int n)
{
	if (vazio(lista))
	{
		return;
	}

	for (Elemento *ant = NULL, *e = lista->primeiro; e != NULL;)
	{
		if (n == e->valor)
		{
			Elemento *aux = e;

			if (ant == NULL)
			{
				lista->primeiro = lista->primeiro->prox;
				e = lista->primeiro;
			}
			else
			{
				ant->prox = e->prox;
				e = e->prox;
			}

			libera_elemento(aux);

			lista->tamanho--;
		}
		else
		{
			ant = e;
			e = e->prox;
		}
	}
}

#include <stdio.h>
#include <stdlib.h>
#include "QuantidadePares.h"

int quantidade_pares(Lista *lista)
{
	if (vazio(lista))
	{
		return 0;
	}

	int qtd = 0;

	for (Elemento *e = lista->primeiro; e != NULL; e = e->prox)
	{
		if (e->valor % 2 == 0)
		{
			qtd++;
		}
	}

	return qtd;
}

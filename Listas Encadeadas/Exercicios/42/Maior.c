#include <stdio.h>
#include <stdlib.h>
#include "Maior.h"

int maior(Lista *lista, int n)
{
	int qtd = 0;

	for (Elemento *e = lista->primeiro; e != NULL; e = e->prox)
	{
		if (e->valor > n)
		{
			qtd++;
		}
	}

	return qtd;
}

#include <stdio.h>
#include <stdlib.h>
#include "ImprimeRecurssivo.h"

void _imprime_recurssivo(Elemento *elemento)
{
	if (elemento == NULL)
	{
		return;
	}

	if (elemento->prox == NULL)
	{
		printf("%d", elemento->valor);
	}
	else
	{
		printf("%d, ", elemento->valor);
	}

	_imprime_recurssivo(elemento->prox);
}

void imprime_recurssivo(Lista *lista)
{
	printf("\n[ ");
	_imprime_recurssivo(lista->primeiro);
	printf(" ]\n");
}

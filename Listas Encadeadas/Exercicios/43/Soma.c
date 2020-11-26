#include <stdio.h>
#include <stdlib.h>
#include "Soma.h"

int soma(Lista *lista)
{
	int soma = 0;

	for (Elemento *e = lista->primeiro; e != NULL; e = e->prox)
	{
		soma += e->valor;
	}

	return soma;
}

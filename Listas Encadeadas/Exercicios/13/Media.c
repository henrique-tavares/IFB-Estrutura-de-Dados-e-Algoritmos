#include <stdio.h>
#include <stdlib.h>
#include "Media.h"

float media(Lista *lista)
{
	if (vazio(lista))
	{
		return 0;
	}

	float media = 0;

	for (Elemento *e = lista->primeiro; e != NULL; e = e->prox)
	{
		media += e->valor;
	}

	media /= lista->tamanho;

	return media;
}

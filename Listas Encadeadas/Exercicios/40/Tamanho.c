#include <stdio.h>
#include <stdlib.h>
#include "Tamanho.h"

int tamanho(Lista *lista)
{
	int qtd = 0;

	for (Elemento *e = lista->primeiro; e != NULL; e = e->prox)
	{
		qtd++;
	}

	return qtd;
}

int _tamanho_recurssivo(Elemento *elemento)
{
	return (elemento == NULL) ? 0 : 1 + _tamanho_recurssivo(elemento->prox);
}

int tamanho_recurssivo(Lista *lista)
{
	return _tamanho_recurssivo(lista->primeiro);
}

#include <stdio.h>
#include <stdlib.h>
#include "TamanhoRecurssivo.h"

int _tamanho_recurssivo(Elemento *elemento)
{
	return (elemento != NULL) ? 1 + _tamanho_recurssivo(elemento->prox) : 0;
}

int tamanho_recurssivo(Lista *lista)
{
	return _tamanho_recurssivo(lista->primeiro);
}

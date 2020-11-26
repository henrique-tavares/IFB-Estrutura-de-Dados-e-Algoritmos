#include <stdio.h>
#include <stdlib.h>
#include "Inverte.h"

void inverte(Lista *lista)
{
	if (vazio(lista))
	{
		return;
	}

	for (Elemento *primeiro = lista->primeiro; primeiro->prox != NULL;)
	{
		Elemento *aux = primeiro->prox;

		primeiro->prox = aux->prox;
		aux->prox = lista->primeiro;
		lista->primeiro = aux;
	}
}

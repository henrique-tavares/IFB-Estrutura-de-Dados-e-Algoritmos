#include <stdio.h>
#include <stdlib.h>
#include "Copia.h"

Lista *copia(Lista *lista)
{
	Lista *lista_copia = cria_lista();

	for (Elemento *e = lista->primeiro, *atual_copia = NULL; e != NULL; e = e->prox)
	{
		Elemento *aux = cria_elemento(e->valor);

		if (vazio(lista_copia))
		{
			lista_copia->primeiro = aux;
			atual_copia = lista_copia->primeiro;
		}
		else
		{
			atual_copia->prox = aux;
			atual_copia = aux;
		}
	}

	lista_copia->tamanho = lista->tamanho;

	return lista_copia;
}

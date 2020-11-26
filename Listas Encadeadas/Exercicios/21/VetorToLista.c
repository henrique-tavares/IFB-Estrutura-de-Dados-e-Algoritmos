#include <stdio.h>
#include <stdlib.h>
#include "VetorToLista.h"

Lista *vetor_to_lista(int *vetor, int tam)
{
	Lista *lista = cria_lista();
	Elemento *atual = NULL;

	for (int i = 0; i < tam; i++)
	{
		Elemento *aux = cria_elemento(vetor[i]);

		if (vazio(lista))
		{
			lista->primeiro = aux;
			atual = aux;
		}
		else
		{
			atual->prox = aux;
			atual = aux;
		}

		lista->tamanho++;
	}

	return lista;
}

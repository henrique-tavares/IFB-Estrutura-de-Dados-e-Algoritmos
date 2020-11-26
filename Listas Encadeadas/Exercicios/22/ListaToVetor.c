#include <stdio.h>
#include <stdlib.h>
#include "ListaToVetor.h"

int *lista_to_vetor(Lista *lista)
{
	int *vetor = (int *)malloc(lista->tamanho * sizeof(int));

	if (vetor == NULL)
	{
		printf("\nERRO: Memória insuficiente\n");
		exit(1);
	}

	int i = 0;
	for (Elemento *e = lista->primeiro; e != NULL; e = e->prox)
	{
		vetor[i++] = e->valor;
	}

	return vetor;
}

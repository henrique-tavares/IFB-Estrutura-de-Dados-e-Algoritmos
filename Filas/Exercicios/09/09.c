#include <stdio.h>
#include "09.h"

void imprime_fila(Fila *fila)
{
	Fila *fila_aux = cria_fila();

	for (int i = 0; i < tamanho(fila); i++)
	{
		enqueue(fila_aux, first(fila));
		enqueue(fila, dequeue(fila));
	}

	printf("[ ");
	while (!vazia(fila_aux))
	{
		printf("%d ", dequeue(fila_aux));
	}
	printf("]");

	libera_fila(fila_aux);
}

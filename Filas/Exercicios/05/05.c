#include <stdio.h>
#include "05.h"

void info(Fila *fila, int *maior, int *menor, float *media)
{
	Fila *fila_aux = cria_fila();

	*maior = first(fila);
	*menor = first(fila);
	*media = 0;

	for (int i = 0; i < tamanho(fila); i++)
	{
		if (first(fila) < *menor)
		{
			*menor = first(fila);
		}

		if (first(fila) > *maior)
		{
			*maior = first(fila);
		}

		*media += first(fila);

		enqueue(fila, dequeue(fila));
	}

	*media /= tamanho(fila);
}

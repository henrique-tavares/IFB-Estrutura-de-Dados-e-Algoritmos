#include <stdio.h>
#include "16.h"

int conta_impar(Fila *fila)
{
	int impar = 0;

	for (int i = 0; i < tamanho(fila); i++)
	{
		if (first(fila) % 2 != 0)
		{
			impar++;
		}

		enqueue(fila, dequeue(fila));
	}

	return impar;
}

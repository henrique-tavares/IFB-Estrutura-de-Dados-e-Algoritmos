#include <stdio.h>
#include "17.h"

int conta_par(Fila *fila)
{
	int par = 0;

	for (int i = 0; i < tamanho(fila); i++)
	{
		if (first(fila) % 2 == 0)
		{
			par++;
		}

		enqueue(fila, dequeue(fila));
	}

	return par;
}

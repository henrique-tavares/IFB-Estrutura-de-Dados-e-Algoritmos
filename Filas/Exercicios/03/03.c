#include <stdio.h>
#include "03.h"

void reverso(Fila *fila)
{
	Fila *fila_aux1 = cria_fila(), *fila_aux2 = cria_fila(), *fila_swap = NULL;

	int tam_final = tamanho(fila);

	while (tamanho(fila) > 1)
	{
		enqueue(fila_aux1, dequeue(fila));
	}

	while (tamanho(fila) < tam_final)
	{
		while (tamanho(fila_aux1) > 1)
		{
			enqueue(fila_aux2, dequeue(fila_aux1));
		}
		enqueue(fila, dequeue(fila_aux1));

		fila_swap = fila_aux1;
		fila_aux1 = fila_aux2;
		fila_aux2 = fila_swap;
	}

	libera_fila(fila_aux1);
	libera_fila(fila_aux2);
}

#include <stdio.h>
#include "08.h"

void merge(Fila *fila_final, Fila *fila_ord1, Fila *fila_ord2)
{
	Fila *fila_aux1 = cria_fila(), *fila_aux2 = cria_fila();

	for (int i = 0; i < tamanho(fila_ord1); i++)
	{
		enqueue(fila_aux1, first(fila_ord1));
		enqueue(fila_ord1, dequeue(fila_ord1));
	}

	for (int i = 0; i < tamanho(fila_ord2); i++)
	{
		enqueue(fila_aux2, first(fila_ord2));
		enqueue(fila_ord2, dequeue(fila_ord2));
	}

	while (!vazia(fila_aux1) && !vazia(fila_aux2))
	{
		if (first(fila_aux1) < first(fila_aux2))
		{
			enqueue(fila_final, dequeue(fila_aux1));
		}
		else if (first(fila_aux2) < first(fila_aux1))
		{
			enqueue(fila_final, dequeue(fila_aux2));
		}
		else
		{
			enqueue(fila_final, dequeue(fila_aux1));
			dequeue(fila_aux2);
		}
	}

	while (!vazia(fila_aux1))
	{
		enqueue(fila_final, dequeue(fila_aux1));
	}

	while (!vazia(fila_aux2))
	{
		enqueue(fila_final, dequeue(fila_aux2));
	}

	libera_fila(fila_aux1);
	libera_fila(fila_aux2);
}

#include <stdio.h>
#include "07.h"

void exclui_negativo(Fila *fila)
{
	Fila *fila_aux = cria_fila();

	while (!vazia(fila))
	{
		if (first(fila) < 0)
		{
			dequeue(fila);
		}
		else
		{
			enqueue(fila_aux, dequeue(fila));
		}
	}

	while (!vazia(fila_aux))
	{
		enqueue(fila, dequeue(fila_aux));
	}

	libera_fila(fila_aux);
}

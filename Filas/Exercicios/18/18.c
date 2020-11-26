#include <stdio.h>
#include "18.h"

Fila *intercala_filas(Fila *f1, Fila *f2)
{
	Fila *fila_intercalada = cria_fila();

	Fila *f1_aux = cria_fila(), *f2_aux = cria_fila();

	for (int i = 0; i < tamanho(f1); i++)
	{
		enqueue(f1_aux, first(f1));
		enqueue(f1, dequeue(f1));
	}

	for (int i = 0; i < tamanho(f2); i++)
	{
		enqueue(f2_aux, first(f2));
		enqueue(f2, dequeue(f2));
	}

	while (!vazia(f1_aux) && !vazia(f2_aux))
	{
		enqueue(fila_intercalada, dequeue(f1_aux));
		enqueue(fila_intercalada, dequeue(f2_aux));
	}

	while (!vazia(f1_aux))
	{
		enqueue(fila_intercalada, dequeue(f1_aux));
	}

	while (!vazia(f2_aux))
	{
		enqueue(fila_intercalada, dequeue(f2_aux));
	}

	libera_fila(f1_aux);
	libera_fila(f2_aux);

	return fila_intercalada;
}

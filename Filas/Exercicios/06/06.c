#include <stdio.h>
#include "06.h"

bool maior(Fila *f1, Fila *f2)
{
	Fila *f1_aux = cria_fila(), *f2_aux = cria_fila();

	int tam_f1 = 0, tam_f2 = 0;

	while (!vazia(f1))
	{
		enqueue(f1_aux, dequeue(f1));
		tam_f1++;
	}
	while (!vazia(f1_aux))
	{
		enqueue(f1, dequeue(f1_aux));
	}

	while (!vazia(f2))
	{
		enqueue(f2_aux, dequeue(f2));
		tam_f2++;
	}
	while (!vazia(f2_aux))
	{
		enqueue(f2, dequeue(f2_aux));
	}

	libera_fila(f1_aux);
	libera_fila(f2_aux);

	return (tam_f1 > tam_f2) ? true : false;
}

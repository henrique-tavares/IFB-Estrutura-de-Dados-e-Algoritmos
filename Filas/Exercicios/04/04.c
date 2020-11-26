#include <stdio.h>
#include "04.h"

void ordena_fila(Fila *fila)
{
	Fila *fila_aux1 = cria_fila(), *fila_aux2 = cria_fila();

	int tam_final = tamanho(fila);

	int menor = first(fila), maior = first(fila);

	while (!vazia(fila))
	{
		if (first(fila) < menor)
		{
			menor = first(fila);
		}

		if (first(fila) > maior)
		{
			maior = first(fila);
		}

		enqueue(fila_aux1, dequeue(fila));
	}

	while (tamanho(fila) < tam_final)
	{
		while (!vazia(fila_aux1))
		{
			if (first(fila_aux1) == menor)
			{
				enqueue(fila, dequeue(fila_aux1));
			}
			else
			{
				enqueue(fila_aux2, dequeue(fila_aux1));
			}
		}

		menor = maior;
		while (!vazia(fila_aux2))
		{
			if (first(fila_aux2) < menor)
			{
				menor = first(fila_aux2);
			}

			enqueue(fila_aux1, dequeue(fila_aux2));
		}
	}

	libera_fila(fila_aux1);
	libera_fila(fila_aux2);
}

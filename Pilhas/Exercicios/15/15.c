#include <stdio.h>
#include "../PilhaInt.h"
#include "../fila/Fila.h"

void inverte_fila(Fila *fila)
{
	Pilha *pilha = cria_pilha();

	while (!fila_vazia(fila))
	{
		push(pilha, dequeue(fila));
	}

	while (!vazia(pilha))
	{
		enqueue(fila, pop(pilha));
	}

	libera_pilha(pilha);
}

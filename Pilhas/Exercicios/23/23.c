#include <stdio.h>
#include "23.h"

int conta_impar(Pilha *pilha)
{
	int impar = 0;
	Pilha *pilha_aux = cria_pilha();

	while (!vazia(pilha))
	{
		if (peek(pilha) % 2 != 0)
		{
			impar++;
		}

		push(pilha_aux, pop(pilha));
	}

	while (!vazia(pilha_aux))
	{
		push(pilha, pop(pilha_aux));
	}

	free(pilha_aux);

	return impar;
}

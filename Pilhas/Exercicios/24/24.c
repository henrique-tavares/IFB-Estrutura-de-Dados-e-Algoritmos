#include <stdio.h>
#include "24.h"

int conta_par(Pilha *pilha)
{
	int par = 0;
	Pilha *pilha_aux = cria_pilha();

	while (!vazia(pilha))
	{
		if (peek(pilha) % 2 == 0)
		{
			par++;
		}

		push(pilha_aux, pop(pilha));
	}

	while (!vazia(pilha_aux))
	{
		push(pilha, pop(pilha_aux));
	}

	free(pilha_aux);

	return par;
}

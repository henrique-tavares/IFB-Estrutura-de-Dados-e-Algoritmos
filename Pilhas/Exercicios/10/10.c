#include <stdio.h>
#include "10.h"

void info(Pilha *pilha, int *max, int *min, float *media)
{
	if (vazia(pilha))
	{
		return;
	}

	Pilha *pilha_aux = cria_pilha();

	*min = peek(pilha);
	*max = peek(pilha);
	*media = peek(pilha);

	push(pilha_aux, pop(pilha));

	while (!vazia(pilha))
	{
		if (peek(pilha) < *min)
		{
			*min = peek(pilha);
		}
		else if (peek(pilha) > *max)
		{
			*max = peek(pilha);
		}

		*media += peek(pilha);
		push(pilha_aux, pop(pilha));
	}

	while (!vazia(pilha_aux))
	{
		push(pilha, pop(pilha_aux));
	}

	*media /= tamanho(pilha);
}

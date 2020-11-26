#include <stdio.h>
#include "09.h"

void ordena_pilha(Pilha *pilha)
{
	Pilha *pilha_aux1 = cria_pilha(), *pilha_aux2 = cria_pilha(), *pilha_swap = NULL;

	int maior;
	int tam_final = tamanho(pilha);

	for (int i = 0; !vazia(pilha); i++)
	{
		if (i == 0 || peek(pilha) > maior)
		{
			maior = peek(pilha);
		}

		push(pilha_aux1, pop(pilha));
	}

	while (tamanho(pilha) < tam_final)
	{
		while (!vazia(pilha_aux1))
		{
			if (peek(pilha_aux1) == maior)
			{
				push(pilha, pop(pilha_aux1));
			}
			else
			{
				push(pilha_aux2, pop(pilha_aux1));
			}
		}

		for (int i = 0; !vazia(pilha_aux2); i++)
		{
			if (i == 0 || peek(pilha_aux2) > maior)
			{
				maior = peek(pilha_aux2);
			}

			push(pilha_aux1, pop(pilha_aux2));
		}
	}

	libera_pilha(pilha_aux1);
	libera_pilha(pilha_aux2);
}

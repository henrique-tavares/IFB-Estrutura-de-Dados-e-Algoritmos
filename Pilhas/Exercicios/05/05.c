#include <stdio.h>
#include <string.h>
#include "05.h"

bool compara_pilhas(Pilha *p1, Pilha *p2)
{
	while (!vazia(p1) && !vazia(p2))
	{
		if (pop(p1) != pop(p2))
		{
			return false;
		}
	}

	return true;
}

bool formato_xy(Pilha *pilha)
{
	if (tamanho(pilha) % 2 != 0)
	{
		return false;
	}

	int tam_metade = tamanho(pilha) / 2;

	Pilha *pilha_aux = cria_pilha();
	Pilha *pilha_y = cria_pilha();
	Pilha *pilha_x = cria_pilha();

	for (int i = 0; i < tam_metade; i++)
	{
		int valor = pop(pilha);

		push(pilha_x, valor);
		push(pilha_aux, valor);
	}

	for (int i = 0; i < tam_metade; i++)
	{
		push(pilha_aux, pop(pilha));
	}

	for (int i = 0; i < tam_metade * 2; i++)
	{
		if (i < tam_metade)
		{
			push(pilha_y, peek(pilha_aux));
		}

		push(pilha, pop(pilha_aux));
	}

	bool xy = compara_pilhas(pilha_x, pilha_y);

	libera_pilha(pilha_aux);
	libera_pilha(pilha_x);
	libera_pilha(pilha_y);

	return xy;
}

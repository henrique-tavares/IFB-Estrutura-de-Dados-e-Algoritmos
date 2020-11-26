#include <stdio.h>
#include "13.h"

bool igual(Pilha *p1, Pilha *p2)
{
	Pilha *p1_aux = cria_pilha(), *p2_aux = cria_pilha();
	bool igual = true;

	while (!vazia(p1) && !vazia(p2))
	{
		if (peek(p1) != peek(p2))
		{
			igual = false;
			break;
		}

		push(p1_aux, pop(p1));
		push(p2_aux, pop(p2));
	}

	if (igual)
	{
		igual = (vazia(p1) && vazia(p2)) ? true : false;
	}

	while (!vazia(p1))
	{
		push(p1_aux, pop(p1));
	}

	while (!vazia(p1_aux))
	{
		push(p1, pop(p1_aux));
	}

	while (!vazia(p2))
	{
		push(p2_aux, pop(p2));
	}

	while (!vazia(p2_aux))
	{
		push(p2, pop(p2_aux));
	}

	libera_pilha(p1_aux);
	libera_pilha(p2_aux);

	return igual;
}

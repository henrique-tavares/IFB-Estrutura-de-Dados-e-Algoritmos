#include <stdio.h>
#include "12.h"

bool maior(Pilha *pilha1, Pilha *pilha2)
{
	Pilha *pilha1_aux = cria_pilha(), *pilha2_aux = cria_pilha();

	int tam_pilha1 = 0, tam_pilha2 = 0;

	while (!vazia(pilha1))
	{
		push(pilha1_aux, pop(pilha1));
		tam_pilha1++;
	}

	while (!vazia(pilha1_aux))
	{
		push(pilha1, pop(pilha1_aux));
	}

	while (!vazia(pilha2))
	{
		push(pilha2_aux, pop(pilha2));
		tam_pilha2++;
	}

	while (!vazia(pilha2_aux))
	{
		push(pilha2, pop(pilha2_aux));
	}

	libera_pilha(pilha1_aux);
	libera_pilha(pilha2_aux);

	return (tam_pilha1 > tam_pilha2) ? true : false;
}

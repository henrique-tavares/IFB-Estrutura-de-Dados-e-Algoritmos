#include <stdio.h>
#include "11.h"

void inverte_pilha(Pilha *pilha)
{
	Pilha *pilha_aux1 = cria_pilha(), *pilha_aux2 = cria_pilha();

	while (!vazia(pilha))
	{
		push(pilha_aux1, pop(pilha));
	}

	while (!vazia(pilha_aux1))
	{
		push(pilha_aux2, pop(pilha_aux1));
	}

	while (!vazia(pilha_aux2))
	{
		push(pilha, pop(pilha_aux2));
	}

	libera_pilha(pilha_aux1);
	libera_pilha(pilha_aux2);
}

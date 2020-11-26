#include <stdio.h>
#include "14.h"

void copia(Pilha *pilha_src, Pilha *pilha_dest)
{
	Pilha *pilha_aux = cria_pilha();

	while (!vazia(pilha_src))
	{
		push(pilha_aux, pop(pilha_src));
	}

	while (!vazia(pilha_aux))
	{
		push(pilha_src, peek(pilha_aux));
		push(pilha_dest, pop(pilha_aux));
	}

	libera_pilha(pilha_aux);
}

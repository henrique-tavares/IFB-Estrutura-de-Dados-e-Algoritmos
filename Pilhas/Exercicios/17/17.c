#include <stdio.h>
#include "17.h"

Pilha *fibonacci(int n)
{
	Pilha *pilha = cria_pilha();

	if (n <= 0)
	{
		return pilha;
	}

	push(pilha, 0);

	if (n == 1)
	{
		return pilha;
	}

	push(pilha, 1);

	if (n == 2)
	{
		return pilha;
	}

	for (int i = 3; i <= n; i++)
	{
		int n1 = pop(pilha);
		int n2 = pop(pilha);

		push(pilha, n2);
		push(pilha, n1);
		push(pilha, n1 + n2);
	}

	return pilha;
}

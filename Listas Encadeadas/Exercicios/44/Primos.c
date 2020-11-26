#include <stdio.h>
#include <stdlib.h>
#include "Primos.h"

int max(Lista *lista)
{
	int max = 0;
	for (Elemento *e = lista->primeiro; e != NULL; e = e->prox)
	{
		if (e == lista->primeiro || abs(e->valor) > max)
		{
			max = abs(e->valor);
		}
	}

	return max;
}

bool testa_primo(int *primos, int tam, int k)
{
	if (k <= 0 || k == 1)
	{
		return false;
	}

	for (int j = 0; j < tam; j++)
	{
		if (k == primos[j])
		{
			return true;
		}

		if (k % primos[j] == 0)
		{
			return false;
		}
	}

	return true;
}

int *calcula_primos(int maior, int *tam)
{
	int *primos = (int *)malloc(sizeof(int));
	*tam = 0;

	primos[0] = 2;
	(*tam)++;

	for (int i = 0, k = 3; (primos[i] * primos[i]) <= maior; k++)
	{
		if (testa_primo(primos, *tam, k))
		{
			primos = (int *)realloc(primos, (*tam + 1) * sizeof(int));
			primos[i + 1] = k;

			(*tam)++, i++;
		}
	}

	return primos;
}

int primos(Lista *lista)
{
	int qtd = 0, tam = 0;
	int maior = max(lista);
	int *vetPrimos = calcula_primos(maior, &tam);

	for (Elemento *e = lista->primeiro; e != NULL; e = e->prox)
	{
		if (testa_primo(vetPrimos, tam, e->valor))
		{
			qtd++;
		}
	}

	return qtd;
}

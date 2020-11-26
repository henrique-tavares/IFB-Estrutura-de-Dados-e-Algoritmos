#include <stdio.h>

#include "./05.h"

void ordena_decrescente(int *vet, int tam)
{
	for (int i = 1; i < tam; i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (vet[j] > vet[j - 1])
			{
				int aux = vet[j];
				vet[j] = vet[j - 1];
				vet[j - 1] = aux;
			}
		}
	}
}

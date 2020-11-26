#include <stdio.h>
#include <stdlib.h>

#include "./06.h"

int *insere_ordenado(int *vet, int *tam, int num)
{
	int index = 0;

	for (int i = 0; i < *tam; i++)
	{
		if (num > vet[i])
		{
			index++;
		}
		else
		{
			break;
		}
	}

	vet = (int *)realloc(vet, (++(*tam)) * sizeof(int));

	for (int i = *tam - 1; i > index; i--)
	{
		vet[i] = vet[i - 1];
	}

	vet[index] = num;

	return vet;
}

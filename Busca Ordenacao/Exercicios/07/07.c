#include <stdio.h>

#include "./07.h"

bool contem(int *vet, int tam, int num)
{
	for (int i = 0; i < tam; i++)
	{
		if (vet[i] == num)
		{
			return true;
		}
	}

	return false;
}

#include <stdio.h>
#include <stdbool.h>

#include "./04.h"

bool _ordenado(int *vet, int tam)
{
    for (int i = 1; i < tam; i++)
    {
        if (vet[i] < vet[i - 1])
        {
            return false;
        }
    }

    return true;
}

void ordenado(int *vet, int tam)
{
    if (_ordenado(vet, tam))
    {
        printf("\nORDENADO\n");
    }
}

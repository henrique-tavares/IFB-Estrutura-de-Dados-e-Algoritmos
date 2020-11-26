#include <stdio.h>
#include <stdlib.h>
#include "Igual.h"

bool igual(Lista *l1, Lista *l2)
{
	if (l1->tamanho != l2->tamanho)
	{
		return false;
	}

	for (Elemento *e1 = l1->primeiro, *e2 = l2->primeiro; e1 != NULL; e1 = e1->prox, e2 = e2->prox)
	{
		if (!(contem(l2, e1->valor) && contem(l1, e2->valor)))
		{
			return false;
		}
	}

	return true;
}

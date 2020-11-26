#include <stdio.h>
#include <stdlib.h>
#include "IdentidadeRecurssiva.h"

bool _identidade_recurssiva(Elemento *e1, Elemento *e2)
{
	if (e1 == NULL && e2 == NULL)
	{
		return true;
	}
	if ((e1 == NULL && e2 != NULL) || (e1 != NULL && e2 == NULL))
	{
		return false;
	}
	if (e1->valor != e2->valor)
	{
		return false;
	}

	_identidade_recurssiva(e1->prox, e2->prox);
}

bool identidade_recurssiva(Lista *l1, Lista *l2)
{
	return _identidade_recurssiva(l1->primeiro, l2->primeiro);
}

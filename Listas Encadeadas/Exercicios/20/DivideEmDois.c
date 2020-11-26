#include <stdio.h>
#include <stdlib.h>
#include "DivideEmDois.h"

Lista *divide_em_dois(Lista *l1, int n)
{
	Lista *l2 = cria_lista();

	Elemento *e1 = busca(l1, n);

	if (e1 == NULL)
	{
		return l2;
	}

	e1 = e1->prox;
	for (Elemento *e2 = NULL; e1 != NULL; e1 = e1->prox)
	{
		Elemento *aux = cria_elemento(e1->valor);

		if (vazio(l2))
		{
			l2->primeiro = aux;
			e2 = l2->primeiro;
		}
		else
		{
			e2->prox = aux;
			e2 = e2->prox;
		}

		l2->tamanho++;
	}

	return l2;
}

#include <stdio.h>
#include <stdlib.h>
#include "Uniao.h"

Lista *uniao(Lista *l1, Lista *l2)
{
	Lista *l3 = cria_lista();
	Elemento *e3 = NULL;

	for (Elemento *e1 = l1->primeiro; e1 != NULL; e1 = e1->prox)
	{
		Elemento *aux = cria_elemento(e1->valor);

		if (vazio(l3))
		{
			l3->primeiro = aux;
			e3 = aux;
		}
		else
		{
			e3->prox = aux;
			e3 = aux;
		}

		l3->tamanho++;
	}

	for (Elemento *e2 = l2->primeiro; e2 != NULL; e2 = e2->prox)
	{
		if (contem(l3, e2->valor))
		{
			continue;
		}

		Elemento *aux = cria_elemento(e2->valor);

		if (vazio(l3))
		{
			l3->primeiro = aux;
			e3 = aux;
		}
		else
		{
			e3->prox = aux;
			e3 = aux;
		}

		l3->tamanho++;
	}

	return l3;
}

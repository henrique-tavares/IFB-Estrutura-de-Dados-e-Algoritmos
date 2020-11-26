#include <stdio.h>
#include <stdlib.h>
#include "CopiaSemRepeticao.h"

Lista *copia_sem_repeticao(Lista *l1)
{
	Lista *l2 = cria_lista();

	for (Elemento *e1 = l1->primeiro, *e2 = NULL; e1 != NULL; e1 = e1->prox)
	{
		if (contem(l2, e1->valor))
		{
			continue;
		}

		Elemento *aux = cria_elemento(e1->valor);

		if (vazio(l2))
		{
			l2->primeiro = aux;
			e2 = aux;
		}
		else
		{
			e2->prox = aux;
			e2 = aux;
		}

		l2->tamanho++;
	}

	return l2;
}

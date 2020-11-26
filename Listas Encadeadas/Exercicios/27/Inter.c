#include <stdio.h>
#include <stdlib.h>
#include "Inter.h"

Lista *inter(Lista *l1, Lista *l2)
{
	Lista *l3 = cria_lista();
	Elemento *e3 = NULL;

	Lista *l_menor = NULL, *l_maior = NULL;

	if (l1->tamanho < l2->tamanho)
	{
		l_menor = l1;
		l_maior = l2;
	}
	else if (l2->tamanho < l1->tamanho)
	{
		l_menor = l2;
		l_maior = l1;
	}
	else
	{
		l_menor = l1;
		l_maior = l2;
	}

	for (Elemento *e_menor = l_menor->primeiro; e_menor != NULL; e_menor = e_menor->prox)
	{
		if (contem(l_maior, e_menor->valor))
		{
			Elemento *aux = cria_elemento(e_menor->valor);

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
	}

	return l3;
}

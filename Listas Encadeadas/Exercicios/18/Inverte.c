#include <stdio.h>
#include <stdlib.h>
#include "Inverte.h"

Lista *inverte(Lista *l1)
{
	Lista *l2 = cria_lista();

	for (Elemento *e1 = l1->primeiro; e1 != NULL; e1 = e1->prox)
	{
		insere(l2, e1->valor);
	}

	return l2;
}

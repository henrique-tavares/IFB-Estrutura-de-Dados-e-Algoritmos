#include <stdio.h>
#include <stdlib.h>
#include "SeparaParImpar.h"

void separa_par_impar(Lista *lista, Lista *lista_par, Lista *lista_impar)
{
	lista_par->primeiro = NULL;
	lista_par->tamanho = 0;

	lista_impar->primeiro = NULL;
	lista_impar->tamanho = 0;

	Elemento *e_par = lista_par->primeiro;
	Elemento *e_impar = lista_impar->primeiro;

	for (Elemento *e = lista->primeiro; e != NULL; e = e->prox)
	{
		Elemento *aux = cria_elemento(e->valor);

		if (e->valor % 2 == 0)
		{
			if (vazio(lista_par))
			{
				lista_par->primeiro = aux;
				e_par = aux;
			}
			else
			{
				e_par->prox = aux;
				e_par = aux;
			}

			lista_par->tamanho++;
		}
		else
		{
			if (vazio(lista_impar))
			{
				lista_impar->primeiro = aux;
				e_impar = aux;
			}
			else
			{
				e_impar->prox = aux;
				e_impar = aux;
			}

			lista_impar->tamanho++;
		}
	}
}

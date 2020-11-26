#include <stdio.h>
#include <stdlib.h>
#include "TransformaParImpar.h"

void transforma_par_impar(Lista *lista, Lista *lista_par, Lista *lista_impar)
{
	lista_par->primeiro = NULL;
	lista_par->tamanho = 0;
	Elemento *e_par = NULL;

	lista_impar->primeiro = NULL;
	lista_impar->tamanho = 0;
	Elemento *e_impar = NULL;

	for (Elemento *e = NULL; lista->primeiro != NULL;)
	{
		e = lista->primeiro;
		lista->primeiro = lista->primeiro->prox;
		lista->tamanho--;
		e->prox = NULL;

		if (e->valor % 2 == 0)
		{
			if (vazio(lista_par))
			{
				lista_par->primeiro = e;
				e_par = e;
			}
			else
			{
				e_par->prox = e;
				e_par = e;
			}

			lista_par->tamanho++;
		}
		else
		{
			if (vazio(lista_impar))
			{
				lista_impar->primeiro = e;
				e_impar = e;
			}
			else
			{
				e_impar->prox = e;
				e_impar = e;
			}

			lista_impar->tamanho++;
		}
	}
}

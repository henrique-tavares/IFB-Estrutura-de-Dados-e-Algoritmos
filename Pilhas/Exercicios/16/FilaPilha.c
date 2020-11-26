#include <stdlib.h>
#include <stdio.h>
#include "FilaPilha.h"

Fila *cria_fila()
{
	Fila *fila = (Fila *)malloc(sizeof(Fila));

	if (fila == NULL)
	{
		printf("\nErro: Memória insuficiente!\n");
		exit(1);
	}

	fila->primeiro = NULL;
	fila->ultimo = NULL;
	fila->tam = 0;

	return fila;
}

void libera_fila(Fila *fila)
{
	while (!vazia_fila(fila))
	{
		dequeue(fila);
	}

	free(fila);
}

Elemento_Pilha *cria_elemento_pilha(Pilha *pilha)
{
	Elemento_Pilha *elemento_pilha = (Elemento_Pilha *)malloc(sizeof(Elemento_Pilha));

	if (elemento_pilha == NULL)
	{
		printf("\nErro: Memória insuficiente!\n");
		exit(1);
	}

	elemento_pilha->pilha = copia_pilha(pilha);
	elemento_pilha->prox = NULL;

	return elemento_pilha;
}

void libera_elemento_pilha(Elemento_Pilha *elemento_pilha)
{
	elemento_pilha->prox = NULL;
	libera_pilha(elemento_pilha->pilha);
	free(elemento_pilha);
}

void enqueue(Fila *fila, Pilha *pilha)
{
	Elemento_Pilha *new_pilha = cria_elemento_pilha(pilha);

	if (vazia_fila(fila))
	{
		fila->primeiro = new_pilha;
		fila->ultimo = new_pilha;
	}
	else
	{
		fila->ultimo->prox = new_pilha;
		fila->ultimo = new_pilha;
	}

	fila->tam++;
}

Pilha *dequeue(Fila *fila)
{
	if (vazia_fila(fila))
	{
		printf("\nErro: Fila vazia!\n");
		exit(1);
	}

	Elemento_Pilha *old_pilha = fila->primeiro;

	fila->primeiro = fila->primeiro->prox;
	fila->tam--;

	if (fila->primeiro == NULL)
	{
		fila->ultimo = NULL;
	}

	Pilha *pilha = copia_pilha(old_pilha->pilha);

	libera_elemento_pilha(old_pilha);

	return pilha;
}

Pilha *first(Fila *fila)
{
	if (vazia_fila(fila))
	{
		printf("\nErro: Fila vazia!\n");
		exit(1);
	}

	return fila->primeiro->pilha;
}

Pilha *last(Fila *fila)
{
	if (vazia_fila(fila))
	{
		printf("\nErro: Fila vazia!\n");
		exit(1);
	}

	return fila->ultimo->pilha;
}

Pilha *copia_pilha(Pilha *pilha)
{
	Pilha *pilha_aux = cria_pilha(), *pilha_copia = cria_pilha();

	while (!vazia(pilha))
	{
		push(pilha_aux, pop(pilha));
	}

	while (!vazia(pilha_aux))
	{
		push(pilha_copia, peek(pilha_aux));
		push(pilha, pop(pilha_aux));
	}

	libera_pilha(pilha_aux);

	return pilha_copia;
}

int tamanho_fila(Fila *fila)
{
	return fila->tam;
}

bool vazia_fila(Fila *fila)
{
	return (fila->primeiro == NULL && fila->ultimo == NULL) ? true : false;
}

void imprime_fila(Fila *fila)
{
	Elemento_Pilha *e_pilha = fila->primeiro;

	printf("\n{");
	for (int i = 0; i < fila->tam; i++)
	{
		imprime(e_pilha->pilha);

		e_pilha = e_pilha->prox;
	}
	printf("}\n");
}

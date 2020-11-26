#include <stdlib.h>
#include <stdio.h>
#include "PilhaChar.h"

Pilha *cria_pilha()
{
	Pilha *pilha = (Pilha *)malloc(sizeof(Pilha));

	if (pilha == NULL)
	{
		printf("\nErro: Memória insuficiente!\n");
		exit(1);
	}

	pilha->topo = NULL;
	pilha->tam = 0;

	return pilha;
}

void libera_pilha(Pilha *pilha)
{
	while (!vazia(pilha))
	{
		pop(pilha);
	}

	free(pilha);
}

Elemento *cria_elemento(char valor)
{
	Elemento *elemento = (Elemento *)malloc(sizeof(Elemento));

	if (elemento == NULL)
	{
		printf("\nErro: Memória insuficiente!\n");
		exit(1);
	}

	elemento->valor = valor;
	elemento->ant = NULL;

	return elemento;
}

void libera_elemento(Elemento *elemento)
{
	elemento->ant = NULL;
	free(elemento);
}

void push(Pilha *pilha, char valor)
{
	Elemento *new_topo = cria_elemento(valor);

	new_topo->ant = pilha->topo;
	pilha->topo = new_topo;

	pilha->tam++;
}

char pop(Pilha *pilha)
{
	if (vazia(pilha))
	{
		printf("\nErro: Pilha vazia!\n");
		exit(1);
	}

	Elemento *old_topo = pilha->topo;

	char old_topo_valor = old_topo->valor;

	pilha->topo = pilha->topo->ant;

	libera_elemento(old_topo);
	pilha->tam--;

	return old_topo_valor;
}

char peek(Pilha *pilha)
{
	if (vazia(pilha))
	{
		printf("\nErro: Pilha vazia!\n");
		exit(1);
	}

	return pilha->topo->valor;
}

void pull(Pilha *pilha, char valor)
{
	if (vazia(pilha))
	{
		printf("\nErro: Pilha vazia!\n");
		exit(1);
	}

	pilha->topo->valor = valor;
}

int tamanho(Pilha *pilha)
{
	return pilha->tam;
}

bool vazia(Pilha *pilha)
{
	return (pilha->topo == NULL) ? true : false;
}

void imprime(Pilha *pilha)
{
	Pilha *pilha_aux = cria_pilha();

	while (!vazia(pilha))
	{
		push(pilha_aux, pop(pilha));
	}

	printf("\n[ ");
	while (!vazia(pilha_aux))
	{
		printf("%c ", peek(pilha_aux));
		push(pilha, pop(pilha_aux));
	}
	printf("]\n");
}

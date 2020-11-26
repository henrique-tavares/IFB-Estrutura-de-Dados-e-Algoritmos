#include <stdlib.h>
#include <stdio.h>
#include "PilhaNode.h"

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

Elemento *cria_elemento(Node *valor)
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

void push(Pilha *pilha, Node *valor)
{
	Elemento *new_topo = cria_elemento(valor);

	new_topo->ant = pilha->topo;
	pilha->topo = new_topo;

	pilha->tam++;
}

Node *pop(Pilha *pilha)
{
	if (vazia(pilha))
	{
		printf("\nErro: Pilha vazia!\n");
		exit(1);
	}

	Elemento *old_topo = pilha->topo;

	Node *old_topo_valor = old_topo->valor;

	pilha->topo = pilha->topo->ant;

	libera_elemento(old_topo);
	pilha->tam--;

	return old_topo_valor;
}

Node *peek(Pilha *pilha)
{
	if (vazia(pilha))
	{
		printf("\nErro: Pilha vazia!\n");
		exit(1);
	}

	return pilha->topo->valor;
}

void pull(Pilha *pilha, Node *valor)
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

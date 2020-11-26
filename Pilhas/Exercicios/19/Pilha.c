#include <stdlib.h>
#include <stdio.h>
#include "./Pilha.h"

struct Elemento
{
	int valor;
	Elemento *ant;
	Elemento *prox;
};

struct Pilha
{
	Elemento *topo;
	int tam;
};

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

Elemento *cria_elemento(int valor)
{
	Elemento *elemento = (Elemento *)malloc(sizeof(Elemento));

	if (elemento == NULL)
	{
		printf("\nErro: Memória insuficiente!\n");
		exit(1);
	}

	elemento->valor = valor;
	elemento->ant = NULL;
	elemento->prox = NULL;

	return elemento;
}

void libera_elemento(Elemento *elemento)
{
	elemento->ant = NULL;
	elemento->prox = NULL;
	free(elemento);
}

void push(Pilha *pilha, int valor)
{
	Elemento *new_topo = cria_elemento(valor);

	if (!vazia(pilha))
	{
		new_topo->ant = pilha->topo;
		pilha->topo->prox = new_topo;
	}

	pilha->topo = new_topo;
	pilha->tam++;
}

int pop(Pilha *pilha)
{
	if (vazia(pilha))
	{
		printf("\nErro: Pilha vazia!\n");
		exit(1);
	}

	Elemento *old_topo = pilha->topo;

	pilha->topo = pilha->topo->ant;

	if (pilha->topo != NULL)
	{
		pilha->topo->prox = NULL;
	}

	pilha->tam--;

	int old_topo_valor = old_topo->valor;

	libera_elemento(old_topo);

	return old_topo_valor;
}

int peek(Pilha *pilha)
{
	if (vazia(pilha))
	{
		printf("\nErro: Pilha vazia!\n");
		exit(1);
	}

	return pilha->topo->valor;
}

void pull(Pilha *pilha, int valor)
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

	printf("[");
	while (!vazia(pilha_aux))
	{
		printf(" %d", peek(pilha_aux));
		push(pilha, pop(pilha_aux));
	}
	printf(" ]");
}

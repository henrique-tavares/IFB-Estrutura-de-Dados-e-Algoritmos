#include <stdlib.h>
#include <stdio.h>
#include "Pilha.h"

enum Tipo
{
	inteiro,
	caractere
};

typedef union Valor {
	int _int;
	char _char;

} Valor;

struct Elemento
{
	Tipo tipo;
	Valor valor;
	Elemento *ant;
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
}

void libera_pilha(Pilha *pilha)
{
	while (!vazia(pilha))
	{
		switch (peek_tipo(pilha))
		{
		case inteiro:
			pop_int(pilha);
			break;

		case caractere:
			pop_char(pilha);
			break;
		}
	}
}

Elemento *cria_elemento_int(int valor)
{
	Elemento *elemento = (Elemento *)malloc(sizeof(Elemento));

	if (elemento == NULL)
	{
		printf("\nErro: Memória insuficiente!\n");
		exit(1);
	}

	elemento->valor._int = valor;
	elemento->tipo = inteiro;
	elemento->ant = NULL;

	return elemento;
}

Elemento *cria_elemento_char(char valor)
{
	Elemento *elemento = (Elemento *)malloc(sizeof(Elemento));

	if (elemento == NULL)
	{
		printf("\nErro: Memória insuficiente!\n");
		exit(1);
	}

	elemento->valor._char = valor;
	elemento->tipo = caractere;
	elemento->ant = NULL;

	return elemento;
}

void libera_elemento(Elemento *elemento)
{
	elemento->ant = NULL;
	free(elemento);
}

void push_int(Pilha *pilha, int valor)
{
	Elemento *new_topo = cria_elemento_int(valor);

	new_topo->ant = pilha->topo;
	pilha->topo = new_topo;

	pilha->tam++;
}

void push_char(Pilha *pilha, char valor)
{
	Elemento *new_topo = cria_elemento_char(valor);

	new_topo->ant = pilha->topo;
	pilha->topo = new_topo;

	pilha->tam++;
}

int pop_int(Pilha *pilha)
{
	if (vazia(pilha))
	{
		printf("\nErro: Pilha vazia!\n");
		exit(1);
	}

	Elemento *old_topo = pilha->topo;

	pilha->topo = pilha->topo->ant;
	pilha->tam--;

	int old_topo_valor = old_topo->valor._int;

	libera_elemento(old_topo);

	return old_topo_valor;
}

char pop_char(Pilha *pilha)
{
	if (vazia(pilha))
	{
		printf("\nErro: Pilha vazia!\n");
		exit(1);
	}

	Elemento *old_topo = pilha->topo;

	pilha->topo = pilha->topo->ant;
	pilha->tam--;

	char old_topo_valor = old_topo->valor._char;

	libera_elemento(old_topo);

	return old_topo_valor;
}

int peek_int(Pilha *pilha)
{
	if (vazia(pilha))
	{
		printf("\nErro: Pilha vazia!\n");
		exit(1);
	}

	return pilha->topo->valor._int;
}

char peek_char(Pilha *pilha)
{
	if (vazia(pilha))
	{
		printf("\nErro: Pilha vazia!\n");
		exit(1);
	}

	return pilha->topo->valor._char;
}

Tipo peek_tipo(Pilha *pilha)
{
	return pilha->topo->tipo;
}

void pull_int(Pilha *pilha, int valor)
{
	if (vazia(pilha))
	{
		printf("\nErro: Pilha vazia!\n");
		exit(1);
	}

	pilha->topo->valor._int = valor;
}

void pull_char(Pilha *pilha, char valor)
{
	if (vazia(pilha))
	{
		printf("\nErro: Pilha vazia!\n");
		exit(1);
	}

	pilha->topo->valor._char = valor;
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
		switch (peek_tipo(pilha))
		{
		case inteiro:
			push_int(pilha_aux, pop_int(pilha));
			break;

		case caractere:
			push_char(pilha_aux, pop_char(pilha));
		}
	}

	printf("[");
	while (!vazia(pilha_aux))
	{
		switch (peek_tipo(pilha_aux))
		{
		case inteiro:
			printf(" %d", peek_int(pilha_aux));
			push_int(pilha, pop_int(pilha_aux));
			break;

		case caractere:
			printf(" %c", peek_char(pilha_aux));
			push_char(pilha, pop_char(pilha_aux));
		}
	}
	printf(" ]");
}

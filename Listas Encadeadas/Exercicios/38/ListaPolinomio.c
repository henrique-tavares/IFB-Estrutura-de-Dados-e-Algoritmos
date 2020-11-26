#include <stdio.h>
#include <stdlib.h>
#include "ListaPolinomio.h"

ListaPolinomio *cria_polinomio()
{
	ListaPolinomio *polinomio = (ListaPolinomio *)malloc(sizeof(ListaPolinomio));

	if (polinomio == NULL)
	{
		printf("\nERRO: Memória insuficiente\n");
		exit(1);
	}

	polinomio->primeiro = NULL;
	polinomio->tamanho = 0;

	return polinomio;
}

void libera_polinomio(ListaPolinomio *polinomio)
{
	reinicia_polinomio(polinomio);
	free(polinomio);
}

Termo *cria_termo(int coeficiente)
{
	Termo *termo = (Termo *)malloc(sizeof(Termo));

	if (termo == NULL)
	{
		printf("\nERRO: Memória insuficiente\n");
		exit(1);
	}

	termo->coeficiente = coeficiente;
	termo->potencia = 0;
	termo->prox = NULL;

	return termo;
}

void libera_termo(Termo *termo)
{
	termo->prox = NULL;

	free(termo);
}

void insere_termo(ListaPolinomio *polinomio, int coeficiente)
{
	if (coeficiente == 0)
	{
		return;
	}

	Termo *termo = cria_termo(coeficiente);
	termo->potencia = polinomio->tamanho;

	termo->prox = polinomio->primeiro;
	polinomio->primeiro = termo;

	polinomio->tamanho++;
}

void substitui_termo(ListaPolinomio *polinomio, int potencia, int coeficiente)
{
	if (potencia < 0 || potencia >= polinomio->tamanho || coeficiente == 0)
	{
		return;
	}

	for (Termo *t = polinomio->primeiro; t != NULL; t = t->prox)
	{
		if (t->potencia == potencia)
		{
			t->coeficiente = coeficiente;
			return;
		}
	}
}

void imprime(ListaPolinomio *polinomio)
{
	putchar('\n');

	for (Termo *t = polinomio->primeiro; t != NULL; t = t->prox)
	{
		if (t->coeficiente != 0)
		{
			char signal = (t->coeficiente > 0) ? '+' : '\0';

			if (t->potencia == 0)
			{
				printf("%c%d", signal, t->coeficiente);
			}
			else if (t->potencia == 1)
			{
				printf("%c%dx ", signal, t->coeficiente);
			}
			else
			{
				printf("%c%dx^%d ", signal, t->coeficiente, t->potencia);
			}
		}
	}

	putchar('\n');
}

void elimina_termo(ListaPolinomio *polinomio, int potencia)
{
	if (potencia < 0 || potencia >= polinomio->tamanho)
	{
		return;
	}

	for (Termo *t = polinomio->primeiro; t != NULL; t = t->prox)
	{
		if (t->potencia == potencia)
		{
			t->coeficiente = 0;
			return;
		}
	}
}

void reinicia_polinomio(ListaPolinomio *polinomio)
{
	for (Termo *t = NULL; polinomio->primeiro != NULL; libera_termo(t))
	{
		t = polinomio->primeiro;

		polinomio->primeiro = polinomio->primeiro->prox;
		polinomio->tamanho--;
	}
}

bool vazio(ListaPolinomio *polinomio)
{
	return (polinomio->primeiro == NULL) ? true : false;
}

#include <stdio.h>
#include "26.h"

enum Base
{
	binario,
	octal,
	hexadecimal
};

void decimal_conversao(int num, Base base_tipo)
{
	if (num < 0)
	{
		printf("\nInforme um número positivo\n");
		return;
	}

	int base;

	switch (base_tipo)
	{
	case binario:
		base = 2;
		printf("\nbinário: ");
		break;

	case octal:
		base = 8;
		printf("\noctal: ");
		break;

	case hexadecimal:
		base = 16;
		printf("\nhexadecimal: ");
		break;
	}

	Pilha *pilha = cria_pilha();

	while (num >= base)
	{
		push(pilha, num % base);
		num /= base;
	}

	push(pilha, num);

	while (!vazia(pilha))
	{
		if (base_tipo == hexadecimal && peek(pilha) >= 10)
		{
			printf("%c", 'a' + (pop(pilha) - 10));
		}
		else
		{
			printf("%d", pop(pilha));
		}
	}
}

int main()
{
	int num, op;

	printf("\n\tCONVERSÃO DE BASES\n");

	printf("\nDigite um número: ");
	scanf("%d", &num);

	printf("\n(1) Binário");
	printf("\n(2) Octal");
	printf("\n(3) Hexadecimal\n");
	printf("\nDigite uma base para a conversão: ");
	scanf("%d", &op);

	switch (op)
	{
	case 1:
		printf("\n");
		decimal_conversao(num, binario);
		printf("\n");
		break;

	case 2:
		printf("\n");
		decimal_conversao(num, octal);
		printf("\n");
		break;

	case 3:
		printf("\n");
		decimal_conversao(num, hexadecimal);
		printf("\n");
		break;

	default:
		printf("\nOpção inválida\n");
	}
	printf("\n");

	return 0;
}
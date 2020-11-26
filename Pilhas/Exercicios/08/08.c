#include <stdio.h>
#include <string.h>
#include "08.h"

bool verifica_expressao(char *expressao)
{
	Pilha *pilha = cria_pilha();

	for (int i = 0; i < strlen(expressao); i++)
	{
		if (expressao[i] == '(')
		{
			push(pilha, expressao[i]);
		}
		else if (expressao[i] == ')')
		{
			if (vazia(pilha))
			{
				return false;
			}

			pop(pilha);
		}
	}

	return (vazia(pilha)) ? true : false;
}

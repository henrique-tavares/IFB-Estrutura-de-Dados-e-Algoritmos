#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "06.h"

char *inverte_palavras(char *txt)
{
	char *txt_inv = (char *)malloc((strlen(txt) - 1) * sizeof(char));
	int j = 0;

	Pilha *pilha = cria_pilha();

	for (int i = 0; i < strlen(txt); i++)
	{
		if (txt[i] == ' ' || txt[i] == '.')
		{
			while (!vazia(pilha))
			{
				txt_inv[j++] = pop(pilha);
			}

			if (txt[i] == '.')
			{
				break;
			}

			txt_inv[j++] = ' ';
		}
		else
		{
			push(pilha, txt[i]);
		}
	}

	libera_pilha(pilha);

	return txt_inv;
}

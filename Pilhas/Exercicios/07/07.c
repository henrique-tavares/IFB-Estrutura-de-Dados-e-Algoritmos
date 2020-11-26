#include <stdio.h>
#include <string.h>
#include "07.h"

bool palindromo(char *txt)
{
	Pilha *pilha = cria_pilha();

	for (int i = 0; i < strlen(txt); i++)
	{
		push(pilha, txt[i]);
	}

	for (int i = 0; i < strlen(txt); i++)
	{
		if (txt[i] != pop(pilha))
		{
			return false;
		}
	}

	return true;
}

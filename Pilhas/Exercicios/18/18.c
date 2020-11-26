#include <stdio.h>
#include "../PilhaInt.h"
#include "../fila/Fila.h"

int main()
{
	Fila *fila_impar = cria_fila(), *fila_par = cria_fila();
	Pilha *pilha = cria_pilha();

	int num;

	while (true)
	{
		printf("\nDigite um número (0 para parar): ");
		scanf("%d", &num);

		if (num == 0)
		{
			break;
		}

		if (num % 2 == 0)
		{
			enqueue(fila_par, num);
		}
		else
		{
			enqueue(fila_impar, num);
		}
	}

	while (!fila_vazia(fila_impar) || !fila_vazia(fila_par))
	{
		if (!fila_vazia(fila_impar))
		{
			if (first(fila_impar) > 0)
			{
				push(pilha, first(fila_impar));
			}
			else if (!vazia(pilha))
			{
				pop(pilha);
			}

			dequeue(fila_impar);
		}

		if (!fila_vazia(fila_par))
		{
			if (first(fila_par) > 0)
			{
				push(pilha, first(fila_par));
			}
			else if (!vazia(pilha))
			{
				pop(pilha);
			}

			dequeue(fila_par);
		}
	}

	printf("\nConteúdo final da pilha: ");

	imprime(pilha);

	libera_pilha(pilha);
	libera_fila(fila_impar);
	libera_fila(fila_par);

	return 0;
}
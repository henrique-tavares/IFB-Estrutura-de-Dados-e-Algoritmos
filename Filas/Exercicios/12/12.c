#include <stdio.h>
#include "12.h"

void concatena_fila(Fila *f1, Fila *f2)
{
	while (!vazia(f2))
	{
		enqueue(f1, dequeue(f2));
	}
}

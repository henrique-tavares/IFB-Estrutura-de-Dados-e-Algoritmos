#include <stdio.h>
#include "40.h"

void percorre_nivel(Arvore *arvore)
{
    Fila *fila = cria_fila();
    Node *node = arvore->raiz;

    if (node)
    {
        enqueue(fila, node);
    }

    printf("[");
    while (!vazia(fila))
    {
        node = dequeue(fila);

        printf(" %d", node->valor);

        if (node->esq)
        {
            enqueue(fila, node->esq);
        }

        if (node->dir)
        {
            enqueue(fila, node->dir);
        }
    }
    printf(" ]");

    libera_fila(fila);
}

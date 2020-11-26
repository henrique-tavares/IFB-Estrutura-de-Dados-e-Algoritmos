#include <stdio.h>
#include <stdlib.h>
#include "06.h"

Node *_busca_impar(Node *node)
{
    if (node == NULL)
    {
        return NULL;
    }

    if (node->valor % 2 == 1)
    {
        return node;
    }

    Node *busca_esq = _busca_impar(node->esq);
    Node *busca_dir = _busca_impar(node->dir);

    if (busca_esq)
    {
        return busca_esq;
    }
    else
    {
        return busca_dir;
    }
}

int busca_impar(Arvore *arvore)
{
    Node *busca = _busca_impar(arvore->raiz);

    if (!busca)
    {
        perror("\nERRO: Nenhum ímpar encontrado\n");
        exit(EXIT_FAILURE);
    }

    return busca->valor;
}

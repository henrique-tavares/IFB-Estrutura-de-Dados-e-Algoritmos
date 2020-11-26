#include <stdio.h>
#include <stdlib.h>
#include "07.h"

int _maior(Node *node)
{
    if (node == NULL)
    {
        perror("ERRO: Árvore vazia");
        exit(EXIT_FAILURE);
    }

    if (node->folha(node))
    {
        return node->valor;
    }

    int *maior_esq = NULL;
    int aux_esq;
    if (node->esq != NULL)
    {
        aux_esq = _maior(node->esq);
        maior_esq = &aux_esq;
    }

    int *maior_dir = NULL;
    int aux_dir;
    if (node->dir != NULL)
    {
        aux_dir = _maior(node->dir);
        maior_dir = &aux_dir;
    }

    int maior_filho;

    if (maior_esq == NULL)
    {
        maior_filho = *maior_dir;
    }
    else if (maior_dir == NULL)
    {
        maior_filho = *maior_esq;
    }
    else
    {
        maior_filho = (*maior_esq > *maior_dir) ? *maior_esq : *maior_dir;
    }

    return (node->valor > maior_filho) ? node->valor : maior_filho;
}

int maior(Arvore *arvore)
{
    return _maior(arvore->raiz);
}

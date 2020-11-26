#include <stdio.h>
#include <stdlib.h>
#include "11.h"

Node *_maior_binaria_de_busca(Node *node)
{
    if (node == NULL)
    {
        return NULL;
    }

    return (node->dir) ? _maior_binaria_de_busca(node->dir) : node;
}

int maior_binaria_de_busca(Arvore *arvore)
{
    Node *maior = _maior_binaria_de_busca(arvore->raiz);

    if (!maior)
    {
        perror("ERRO: Árvore vazia");
        exit(EXIT_FAILURE);
    }

    return maior->valor;
}

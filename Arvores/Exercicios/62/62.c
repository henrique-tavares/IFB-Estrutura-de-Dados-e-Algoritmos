#include <stdio.h>
#include "62.h"

Node *_no_igual_soma_filhos(Node *node)
{
    if (!node)
    {
        return NULL;
    }

    if (node->folha(node))
    {
        return node;
    }

    Node *soma_esq, *soma_dir;

    soma_esq = _no_igual_soma_filhos(node->esq);
    soma_dir = _no_igual_soma_filhos(node->dir);

    node->valor = ((soma_esq) ? soma_esq->valor : 0) + ((soma_dir) ? soma_dir->valor : 0);

    return node;
}

void no_igual_soma_filhos(Arvore *arvore)
{
    _no_igual_soma_filhos(arvore->raiz);
}

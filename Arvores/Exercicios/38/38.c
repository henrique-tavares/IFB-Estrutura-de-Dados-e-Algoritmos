#include <stdio.h>
#include "38.h"

bool _igual(Node *n1, Node *n2)
{
    if ((n1 == NULL) ^ (n2 == NULL))
    {
        return false;
    }

    if (n1 == NULL && n2 == NULL)
    {
        return true;
    }

    if (n1->valor != n2->valor)
    {
        return false;
    }

    return (_igual(n1->esq, n2->esq) && _igual(n1->dir, n2->dir));
}

bool igual(Arvore *arv1, Arvore *arv2)
{
    return _igual(arv1->raiz, arv2->raiz);
}
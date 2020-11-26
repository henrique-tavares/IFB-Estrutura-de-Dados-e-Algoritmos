#include <stdio.h>
#include "13.h"

bool _similar(Node *n1, Node *n2)
{
    if ((n1 == NULL) ^ (n2 == NULL))
    {
        return false;
    }

    if (n1 == NULL && n2 == NULL)
    {
        return true;
    }

    return (_similar(n1->esq, n2->esq) && _similar(n1->dir, n2->dir));
}

bool similar(Arvore *arv1, Arvore *arv2)
{
    return _similar(arv1->raiz, arv2->raiz);
}

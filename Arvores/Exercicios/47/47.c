#include <stdio.h>
#include "47.h"

void _copia_arvore(Node *self, Node **other)
{
    if (!self)
    {
        return;
    }

    *other = cria_node(self->valor, NULL, NULL);

    _copia_arvore(self->esq, &((*other)->esq));
    _copia_arvore(self->dir, &((*other)->dir));
}

Arvore *copia_arvore(Arvore *arvore)
{
    Arvore *copia = cria_arvore_vazia();

    _copia_arvore(arvore->raiz, &(copia->raiz));

    return copia;
}

int main()
{
    Arvore *a = cria_arvore_vazia();

    a->adiciona(a, 4);
    a->adiciona(a, 2);
    a->adiciona(a, 6);
    a->adiciona(a, 1);
    a->adiciona(a, 3);
    a->adiciona(a, 5);
    a->adiciona(a, 10);
    a->adiciona(a, 8);

    Arvore *b = copia_arvore(a);

    printf("\n%s: ", variable(a));
    a->imprime(a, ERD);
    printf("\n%s: ", variable(b));
    b->imprime(b, ERD);
    printf("\n\n");

    a->libera(a);
    b->libera(b);
}
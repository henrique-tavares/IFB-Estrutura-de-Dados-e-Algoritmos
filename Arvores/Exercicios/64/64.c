#include <stdio.h>
#include "64.h"

Lista *_arvore_to_lista_erd(Node *node, Lista **lista)
{
    if (!node)
    {
        return *lista;
    }

    *lista = _arvore_to_lista_erd(node->esq, lista);

    if (vazio(*lista))
    {
        (*lista)->primeiro = cria_elemento(node);
        (*lista)->tamanho++;
    }
    else
    {
        Elemento *e = (*lista)->primeiro;
        for (int i = 0; i < (*lista)->tamanho; i++)
        {
            if (i == (*lista)->tamanho - 1)
            {
                e->prox = cria_elemento(node);
                (*lista)->tamanho++;
                break;
            }
            else
            {
                e = e->prox;
            }
        }
    }

    *lista = _arvore_to_lista_erd(node->dir, lista);
}

Lista *arvore_to_lista_erd(Arvore *arvore)
{
    Lista *lista = cria_lista();

    lista = _arvore_to_lista_erd(arvore->raiz, &lista);

    return lista;
}

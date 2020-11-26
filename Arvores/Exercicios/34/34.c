#include <stdio.h>
#include <stdlib.h>
#include "34.h"

void _percorre_red(Node *node, int *vet, int *tam)
{
    if (!node)
    {
        return;
    }

    _percorre_red(node->esq, vet, tam);

    vet = (int *)realloc(vet, (++(*tam)) * sizeof(int));
    vet[*tam - 1] = node->valor;

    _percorre_red(node->dir, vet, tam);
}

int *_vet_remove(int *vet, int *tam, int index)
{
    for (int i = index; i < *tam - 1; i++)
    {
        vet[i] = vet[i + 1];
    }

    return (int *)realloc(vet, (--(*tam)) * sizeof(int));
}

Arvore *copia_quase_completa(Arvore *arvore)
{
    Arvore *arv_copia = cria_arvore_vazia();

    int *arv_vet = (int *)malloc(0 * sizeof(int));
    int tam_vet = 0;

    _percorre_red(arvore->raiz, arv_vet, &tam_vet);

    if (tam_vet > 0)
    {
        arv_copia->adiciona(arv_copia, arv_vet[(tam_vet - 1) / 2]);
    }

    while (tam_vet > 0)
    {
        arv_copia->adiciona(arv_copia, arv_vet[((tam_vet - 1) - (tam_vet - 1) / 4)]);
        arv_vet = _vet_remove(arv_vet, &tam_vet, ((tam_vet - 1) - (tam_vet - 1) / 4));

        if (tam_vet > 0)
        {
            arv_copia->adiciona(arv_copia, arv_vet[(tam_vet - 1) / 4]);
            arv_vet = _vet_remove(arv_vet, &tam_vet, (tam_vet - 1) / 4);
        }
    }

    return arv_copia;
}

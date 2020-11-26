#include <stdio.h>
#include <stdlib.h>
#include "27.h"

int _menor(Arvore *arvore)
{
    int menor = arvore->raiz->valor;

    for (Node *node = arvore->raiz; node != NULL; node = node->esq)
    {
        menor = node->valor;
    }

    return menor;
}

int _maior(Arvore *arvore)
{
    int maior = arvore->raiz->valor;

    for (Node *node = arvore->raiz; node != NULL; node = node->dir)
    {
        maior = node->valor;
    }

    return maior;
}

int k_menor_nao_recurssivo(Arvore *arvore, int k)
{
    if (!arvore->raiz)
    {
        perror("\nERRO: Arvore vazia\n");
        exit(EXIT_FAILURE);
    }

    int *menores = (int *)malloc(sizeof(int));
    menores[0] = _menor(arvore);
    int tam = 1;

    int maior = _maior(arvore);

    for (int i = 1; i < k && menores[i - 1] != maior; i++)
    {
        Node *node = arvore->raiz;
        Pilha *pilha = cria_pilha();

        int menor_atual = maior;

        push(pilha, node);

        while (!vazia(pilha))
        {
            node = pop(pilha);

            if (node->valor < menor_atual && node->valor > menores[i - 1])
            {
                menor_atual = node->valor;
            }

            if (node->dir)
            {
                push(pilha, node->dir);
            }

            if (node->esq)
            {
                push(pilha, node->esq);
            }
        }

        menores = (int *)realloc(menores, (++tam) * sizeof(int));
        menores[i] = menor_atual;

        libera_pilha(pilha);
    }

    if ((k - 1) < tam && (k - 1) >= 0)
    {
        return menores[k - 1];
    }

    printf("\nNão foi possínel encontrar o %d-ésimo menor\n", k);
    exit(EXIT_FAILURE);
}

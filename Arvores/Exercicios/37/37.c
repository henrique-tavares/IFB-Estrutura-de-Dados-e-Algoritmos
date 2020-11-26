#include <stdio.h>
#include <stdlib.h>
#include "37.h"

Node *_maior(Node *node)
{
    if (!node)
    {
        return NULL;
    }

    return (node->dir) ? _maior(node->dir) : node;
}

bool testa_primo(int *primos, int tam, int x)
{
    if (x <= 1)
    {
        return false;
    }

    for (int i = 0; i < tam; i++)
    {
        if (primos[i] == x)
        {
            return true;
        }

        if (x % primos[i] == 0)
        {
            return false;
        }
    }

    return true;
}

int *gera_primos(int maior, int *tam)
{
    *tam = 0;
    int *primos = (int *)malloc((++(*tam)) * sizeof(int));
    primos[*tam - 1] = 2;

    for (int i = 0, k = 3; primos[i] * primos[i] <= maior; k++)
    {
        if (testa_primo(primos, *tam, k))
        {
            primos = (int *)realloc(primos, (++(*tam)) * sizeof(int));
            primos[*tam - 1] = k;
            i++;
        }
    }

    return primos;
}

int _conta_nodes_primos(Node *node, int *primos, int *tam)
{
    if (!node)
    {
        return 0;
    }

    if (testa_primo(primos, *tam, node->valor))
    {
        return 1 + _conta_nodes_primos(node->esq, primos, tam) + _conta_nodes_primos(node->dir, primos, tam);
    }

    return _conta_nodes_primos(node->esq, primos, tam) + _conta_nodes_primos(node->dir, primos, tam);
}

int conta_nodes_primos(Arvore *arvore)
{
    Node *maior = _maior(arvore->raiz);

    if (!maior)
    {
        perror("Não foi possível encontrar o maior");
        exit(EXIT_FAILURE);
    }

    int tam;
    int *primos = gera_primos(maior->valor, &tam);

    return _conta_nodes_primos(arvore->raiz, primos, &tam);
}

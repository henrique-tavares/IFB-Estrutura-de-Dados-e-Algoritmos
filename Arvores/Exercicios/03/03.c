#include <stdio.h>
#include "03.h"

int _conta_nodes_nao_folhas(Node *node)
{
    if (node == NULL || node->folha(node))
    {
        return 0;
    }

    return 1 + _conta_nodes_nao_folhas(node->esq) + _conta_nodes_nao_folhas(node->dir);
}

int conta_nodes_nao_folhas(Arvore *arvore)
{
    return _conta_nodes_nao_folhas(arvore->raiz);
}

void main()
{
    Arvore *a = cria_arvore_vazia();

    putchar('\n');
    a->imprime(a, ERD);
    printf(" Nodes não folhas: %d\n", conta_nodes_nao_folhas(a));

    a->cria_raiz(a, 10);

    putchar('\n');
    a->imprime(a, ERD);
    printf(" Nodes não folhas: %d\n", conta_nodes_nao_folhas(a));

    a->adiciona(a, a->raiz, 15, DIR);
    a->adiciona(a, a->raiz, 5, ESQ);

    a->adiciona(a, a->busca(a, 5), 7, DIR);
    a->adiciona(a, a->busca(a, 15), 12, ESQ);

    putchar('\n');
    a->imprime(a, ERD);
    printf(" Nodes não folhas: %d\n", conta_nodes_nao_folhas(a));

    a->libera(a);
}
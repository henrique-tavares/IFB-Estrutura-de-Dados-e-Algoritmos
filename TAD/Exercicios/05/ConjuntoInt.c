#include <stdio.h>
#include <stdlib.h>
#include "ConjuntoInt.h"

struct ConjuntoInt
{
    int *e;
    int tam;
};

ConjuntoInt *cria_conjunto()
{
    ConjuntoInt *conjunto = (ConjuntoInt *)malloc(sizeof(ConjuntoInt));

    if (conjunto == NULL)
    {
        printf("\nERRO: Memória insuficiente\n");
        exit(1);
    }

    conjunto->e = (int *)malloc(0 * sizeof(int));
    conjunto->tam = 0;

    return conjunto;
}

void libera_conjunto(ConjuntoInt *conjunto)
{
    free(conjunto->e);
    free(conjunto);
}

bool contem(ConjuntoInt *conjunto, int num)
{
    for (int i = 0; i < conjunto->tam; i++)
    {
        if (conjunto->e[i] == num)
        {
            return true;
        }
    }

    return false;
}

int indice(ConjuntoInt *conjunto, int num)
{
    for (int i = 0; i < conjunto->tam; i++)
    {
        if (conjunto->e[i] == num)
        {
            return i;
        }
    }

    return -1;
}

void insere(ConjuntoInt *conjunto, int num)
{
    if (contem(conjunto, num))
    {
        printf("\nO número %d já está no conjunto!\n", num);
        return;
    }

    conjunto->e = (int *)realloc(conjunto->e, (++conjunto->tam) * sizeof(int));
    conjunto->e[conjunto->tam - 1] = num;
}

void retira(ConjuntoInt *conjunto, int num)
{
    int in = indice(conjunto, num);

    if (in == -1)
    {
        printf("\nO número %d não foi encontrado!\n", num);
        return;
    }

    for (int i = in + 1; i < conjunto->tam; i++)
    {
        conjunto->e[i - 1] = conjunto->e[i];
    }

    conjunto->e = (int *)realloc(conjunto->e, (--conjunto->tam) * sizeof(int));
}

ConjuntoInt *uniao(ConjuntoInt *c1, ConjuntoInt *c2)
{
    ConjuntoInt *uniao = cria_conjunto();

    for (int i = 0; i < c1->tam; i++)
    {
        insere(uniao, c1->e[i]);
    }

    for (int i = 0; i < c2->tam; i++)
    {
        if (!contem(uniao, c2->e[i]))
        {
            insere(uniao, c2->e[i]);
        }
    }

    return uniao;
}

ConjuntoInt *intersecao(ConjuntoInt *c1, ConjuntoInt *c2)
{
    ConjuntoInt *intersecao = cria_conjunto();

    for (int i = 0; i < c1->tam; i++)
    {
        if (contem(c2, c1->e[i]))
        {
            insere(intersecao, c1->e[i]);
        }
    }

    return intersecao;
}

ConjuntoInt *diferenca(ConjuntoInt *c1, ConjuntoInt *c2)
{
    ConjuntoInt *diferenca = cria_conjunto();

    for (int i = 0; i < c1->tam; i++)
    {
        if (!contem(c2, c1->e[i]))
        {
            insere(diferenca, c1->e[i]);
        }
    }

    return diferenca;
}

int max(ConjuntoInt *conjunto)
{
    int max;

    for (int i = 0; i < conjunto->tam; i++)
    {
        if ((i == 0) || (conjunto->e[i] > max))
        {
            max = conjunto->e[i];
        }
    }

    return max;
}

int min(ConjuntoInt *conjunto)
{
    int min;

    for (int i = 0; i < conjunto->tam; i++)
    {
        if ((i == 0) || (conjunto->e[i] < min))
        {
            min = conjunto->e[i];
        }
    }

    return min;
}

int tamanho(ConjuntoInt *conjunto)
{
    return conjunto->tam;
}

void lista_conjunto(ConjuntoInt *conjunto)
{
    printf("\n[");
    for (int i = 0; i < conjunto->tam; i++)
    {
        if (i == 0)
        {
            printf("%d", conjunto->e[i]);
            continue;
        }

        printf(", %d", conjunto->e[i]);
    }
    printf("]\n");
}

bool igual(ConjuntoInt *c1, ConjuntoInt *c2)
{
    if (c1->tam != c2->tam)
    {
        return false;
    }

    for (int i = 0; i < c1->tam; i++)
    {
        if (!contem(c2, c1->e[i]))
        {
            return false;
        }
    }

    return true;
}

bool vazio(ConjuntoInt *conjunto)
{
    return (conjunto->tam == 0) ? true : false;
}

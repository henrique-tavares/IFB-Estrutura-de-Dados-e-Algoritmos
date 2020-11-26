#include <stdio.h>
#include <stdlib.h>
#include "ReservasClube.h"

struct Clube
{
    Quadra *quadras;
    int qtd;
};

enum Quadra
{
    LIVRE,
    RESERVADO
};

Clube *cria_clube(int qtd)
{
    Clube *clube = (Clube *)malloc(sizeof(Clube));

    if (clube == NULL)
    {
        printf("\nERRO: Memória insuficiente\n");
        exit(1);
    }

    clube->quadras = (Quadra *)calloc(qtd, sizeof(Quadra));
    clube->qtd = qtd;

    if (clube->quadras == NULL)
    {
        printf("\nERRO: Memória insuficiente\n");
        exit(1);
    }

    return clube;
}

void libera_clube(Clube *clube)
{
    free(clube->quadras);
    free(clube);
}

void lista_clube(Clube *clube)
{
    printf("\n------------------------------\n");

    for (int i = 0; i < clube->qtd; i++)
    {
        if (clube->quadras[i] == RESERVADO)
        {
            printf("\nQuadra %d - reservada\n", i);
        }
        else
        {
            printf("\nQuadra %d - livre\n", i);
        }
    }

    printf("\n------------------------------\n");
}

void reserva_quadra(Clube *clube, int quadra)
{
    if (quadra < 0 || quadra >= clube->qtd)
    {
        printf("\nQuadra %d inexistente!\n", quadra);
        return;
    }

    if (clube->quadras[quadra] == RESERVADO)
    {
        printf("\nA quadra %d já foi reservada!\n", quadra);
        return;
    }

    clube->quadras[quadra] = RESERVADO;
}

void libera_quadra(Clube *clube, int quadra)
{
    if (quadra < 0 || quadra >= clube->qtd)
    {
        printf("\nQuadra %d inexistente!\n", quadra);
        return;
    }

    if (clube->quadras[quadra] == LIVRE)
    {
        printf("\nA quadra %d já está livre!\n", quadra);
        return;
    }

    clube->quadras[quadra] = LIVRE;
}

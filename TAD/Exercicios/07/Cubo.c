#include <stdio.h>
#include <stdlib.h>
#include "Cubo.h"

struct Cubo
{
    float comprimento;
    float largura;
    float altura;
};

Cubo *cria_cubo(float comprimento, float largura, float altura)
{
    Cubo *cubo = (Cubo *)malloc(sizeof(Cubo));

    if (cubo == NULL)
    {
        printf("\nERRO: Memória insuficiente\n");
        exit(1);
    }

    cubo->comprimento = comprimento;
    cubo->largura = largura;
    cubo->altura = altura;

    return cubo;
}

void liberaCubo(Cubo *cubo)
{
    free(cubo);
}

float comprimento(Cubo *cubo)
{
    return cubo->comprimento;
}

float largura(Cubo *cubo)
{
    return cubo->largura;
}

float altura(Cubo *cubo)
{
    return cubo->altura;
}

float area(Cubo *cubo)
{
    return (
        (2 * (cubo->comprimento * cubo->altura)) +
        (2 * (cubo->largura * cubo->altura)) +
        (2 * (cubo->comprimento * cubo->largura)));
}

float volume(Cubo *cubo)
{
    return (cubo->comprimento * cubo->largura * cubo->altura);
}
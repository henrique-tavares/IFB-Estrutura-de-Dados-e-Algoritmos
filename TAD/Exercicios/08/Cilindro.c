#include <stdio.h>
#include <stdlib.h>
#include "Cilindro.h"

#define PI 3.14159

struct Cilindro
{
    float raio;
    float altura;
};

Cilindro *cria_cilindro(float raio, float altura)
{
    Cilindro *cilindro = (Cilindro *)malloc(sizeof(Cilindro));

    if (cilindro == NULL)
    {
        printf("\nERRO: Memória insuficiente\n");
        exit(1);
    }

    cilindro->raio = raio;
    cilindro->altura = altura;

    return cilindro;
}

void liberaCilindro(Cilindro *cilindro)
{
    free(cilindro);
}

float raio(Cilindro *cilindro)
{
    return cilindro->raio;
}

float altura(Cilindro *cilindro)
{
    return cilindro->altura;
}

float area(Cilindro *cilindro)
{
    float area_base = PI * (cilindro->raio * cilindro->raio);
    float area_lateral = 2 * PI * cilindro->raio * cilindro->altura;

    return 2 * area_base + area_lateral;
}

float volume(Cilindro *cilindro)
{
    return PI * (cilindro->raio * cilindro->raio) * cilindro->altura;
}
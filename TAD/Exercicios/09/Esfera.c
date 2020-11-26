#include <stdio.h>
#include <stdlib.h>
#include "Esfera.h"

#define PI 3.14159

struct Esfera
{
    float raio;
};

Esfera *cria_esfera(float raio)
{
    Esfera *esfera = (Esfera *)malloc(sizeof(Esfera));

    if (esfera == NULL)
    {
        printf("\nERRO: Memória insuficiente\n");
        exit(1);
    }

    esfera->raio = raio;

    return esfera;
}

void libera_esfera(Esfera *esfera)
{
    free(esfera);
}

float raio(Esfera *esfera)
{
    return esfera->raio;
}

float area(Esfera *esfera)
{
    return 4 * PI * (esfera->raio * esfera->raio);
}

float volume(Esfera *esfera)
{
    return (4.0 / 3.0) * PI * (esfera->raio * esfera->raio * esfera->raio);
}
#include <stdio.h>
#include <stdlib.h>
#include "Complexo.h"

struct Complexo
{
    float real;
    float imaginario;
};

Complexo *cria(float real, float imaginario)
{
    Complexo *complexo = (Complexo *)malloc(sizeof(Complexo));

    if (complexo == NULL)
    {
        printf("\nERRO: Memória insuficiente\n");
        exit(1);
    }

    complexo->real = real;
    complexo->imaginario = imaginario;

    return complexo;
}

void libera(Complexo *complexo)
{
    free(complexo);
}

float real(Complexo *complexo)
{
    return complexo->real;
}

float imaginario(Complexo *complexo)
{
    return complexo->imaginario;
}

Complexo *conjugado(Complexo *complexo)
{
    return cria(complexo->real, -complexo->imaginario);
}

Complexo *soma(Complexo *c1, Complexo *c2)
{
    return cria(c1->real + c2->real, c1->imaginario + c2->imaginario);
}

Complexo *subtrai(Complexo *c1, Complexo *c2)
{
    return cria(c1->real - c2->real, c1->imaginario - c2->imaginario);
}

Complexo *multiplica(Complexo *c1, Complexo *c2)
{
    Complexo *mul = cria(0, 0);

    mul->real = (c1->real * c2->real) - (c1->imaginario * c2->imaginario);
    mul->imaginario = (c1->real * c2->imaginario) + (c1->imaginario * c2->real);

    return mul;
}

Complexo *divide(Complexo *c1, Complexo *c2)
{
    Complexo *div, *conj, *t_c1, *t_c2;

    div = cria(0, 0);
    conj = conjugado(c2);

    t_c1 = multiplica(c1, conj);
    t_c2 = multiplica(c2, conj);

    div->real = t_c1->real / t_c2->real;
    div->imaginario = t_c1->imaginario / t_c2->real;

    free(conj);
    free(t_c1);
    free(t_c2);

    return div;
}
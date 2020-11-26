#include <stdio.h>
#include <stdlib.h>
#include "Racional.h"

struct Racional
{
    int numerador;
    int denominador;
};

Racional *cria_racional(int numerador, int denominador)
{
    Racional *racional = (Racional *)malloc(sizeof(Racional));

    if (racional == NULL)
    {
        printf("\nERRO: Memória insuficiente!\n");
        exit(1);
    }

    if (denominador == 0)
    {
        printf("\nERRO: Denominador não pode ser zero!\n");
        return NULL;
    }

    racional->numerador = numerador;
    racional->denominador = denominador;

    return racional;
}

void libera_racional(Racional *racional)
{
    free(racional);
}

int numerador(Racional *racional)
{
    return racional->numerador;
}

int denominador(Racional *racional)
{
    return racional->denominador;
}

Racional *reduz(Racional *racional)
{
    Racional *reduzido = cria_racional(racional->numerador, racional->denominador);

    int min = (reduzido->numerador < reduzido->denominador) ? reduzido->numerador : reduzido->denominador;

    int tam = 1;
    int *vet = (int *)malloc(tam * sizeof(int));

    vet[0] = 2;

    for (int i = 0, j = 3; vet[i] <= min; j++)
    {
        bool status = true;
        for (int k = 0; k < tam; k++)
        {
            if (j % vet[k] == 0)
            {
                status = false;
                break;
            }
        }

        if (status)
        {
            vet = (int *)realloc(vet, (++tam) * sizeof(int));
            vet[++i] = j;
        }
    }

    for (int i = tam - 1; i >= 0; i--)
    {
        while ((reduzido->numerador % vet[i] == 0) && (reduzido->denominador % vet[i] == 0))
        {
            reduzido->numerador /= vet[i];
            reduzido->denominador /= vet[i];
        }
    }

    free(vet);

    return reduzido;
}

Racional *inverte(Racional *racional)
{
    return cria_racional(racional->denominador, racional->numerador);
}

Racional *soma_racional(Racional *r1, Racional *r2)
{
    Racional *soma = cria_racional(0, 1);

    if (r1->denominador == r2->denominador)
    {
        soma->denominador = r1->denominador;
        soma->numerador = r1->numerador + r2->numerador;
    }
    else
    {
        soma->denominador = r1->denominador * r2->denominador;
        soma->numerador = (r1->numerador * r2->denominador) + (r2->numerador * r1->denominador);
    }

    Racional *re_soma = reduz(soma);

    free(soma);

    return re_soma;
}

Racional *multiplica_racional(Racional *r1, Racional *r2)
{
    Racional *mul = cria_racional(0, 1);

    mul->numerador = r1->numerador * r2->numerador;
    mul->denominador = r1->denominador * r2->denominador;

    Racional *re_mul = reduz(mul);

    free(mul);

    return re_mul;
}

Racional *divide_racional(Racional *r1, Racional *r2)
{
    Racional *r2_inv, *div, *re_div;

    r2_inv = inverte(r2);

    div = multiplica_racional(r1, r2_inv);

    re_div = reduz(div);

    free(r2_inv);
    free(div);

    return re_div;
}

bool igual(Racional *r1, Racional *r2)
{
    if ((r1->numerador / r2->numerador == r1->denominador / r2->denominador) &&
        (r2->numerador / r1->numerador == r2->denominador / r1->denominador))
    {
        return true;
    }

    return false;
}

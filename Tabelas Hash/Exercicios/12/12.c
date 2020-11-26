#include <stdio.h>

int hashing(int chave, const int table_size)
{
    const double A = 0.6180339887498949; // (√5 - 1)/2

    double valor = chave * A;
    valor = valor - (int)valor;

    return (int)(table_size * valor);
}

void main()
{
    const int table_size = 1000;
    int chaves[] = {61, 62, 63, 64, 65};

    for (int i = 0; i < 5; i++)
    {
        printf("\n%d -> %d\n", chaves[i], hashing(chaves[i], table_size));
    }
}
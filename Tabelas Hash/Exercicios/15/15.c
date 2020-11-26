#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int sondagem_linear(int chave, int i, int table_size)
{
    return (chave + i) % table_size;
}

int sondagem_quadatica1(int chave, int i, int table_size)
{
    return (chave + i * i) % table_size;
}

int sondagem_quadratica2(int chave, int i, int table_size)
{
    return (chave + 2 * i + i * i) % table_size;
}

int hashing_aux1(int chave, int table_size)
{
    return chave % table_size;
}

int hashing_aux2(int chave)
{
    return 7 - (chave % 7);
}

int duplo_hash(int chave, int i, int table_size)
{
    return (hashing_aux1(chave, table_size) + i * hashing_aux2(chave)) % table_size;
}

void imprime_enderecamento_aberto(int chaves[], int table_size, int (*hashing)(int chave, int i, int table_size))
{
    for (int i = 0; i < 6; i++)
    {
        printf("\n%d ->", chaves[i]);

        for (int j = 0; j < table_size; j++)
        {
            printf(" %d", hashing(chaves[i], j, table_size));
        }
    }
}

void main()
{
    int m = 10;
    int chaves[] = {371, 121, 173, 203, 11, 24};

    printf("\nSondagem linear:");
    imprime_enderecamento_aberto(chaves, m, sondagem_linear);
    printf("\n");

    printf("\nSondagem quadrática 1:");
    imprime_enderecamento_aberto(chaves, m, sondagem_quadatica1);
    printf("\n");

    printf("\nSondagem quadrática 2:");
    imprime_enderecamento_aberto(chaves, m, sondagem_quadratica2);
    printf("\n");

    printf("\nHash duplo:");
    imprime_enderecamento_aberto(chaves, m, duplo_hash);
    printf("\n");
}
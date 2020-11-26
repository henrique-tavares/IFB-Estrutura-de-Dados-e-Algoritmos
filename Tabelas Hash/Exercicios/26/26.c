#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int hashing(int chave, int table_size)
{
    return chave % table_size;
}

int sondagem_linear(int chave, int i, int table_size)
{
    return hashing(chave + i, table_size);
}

int sondagem_quadatica(int chave, int i, int table_size)
{
    return hashing(chave + 3 * i + 7 * i * i, table_size);
}

int hashing_aux(int chave)
{
    return 1 + (chave % 13);
}

int duplo_hash(int chave, int i, int table_size)
{
    return (hashing(chave, table_size) + i * hashing_aux(chave)) % table_size;
}

void imprime_enderecamento_aberto(int chaves[], int table_size, int (*hashing)(int chave, int i, int table_size))
{
    for (int i = 0; i < 10; i++)
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
    int m = 17;
    int chaves[] = {2, 32, 43, 16, 77, 51, 1, 17, 42, 111};

    printf("\nSondagem linear:");
    imprime_enderecamento_aberto(chaves, m, sondagem_linear);
    printf("\n");

    printf("\nSondagem quadrática:");
    imprime_enderecamento_aberto(chaves, m, sondagem_quadatica);
    printf("\n");

    printf("\nHash duplo:");
    imprime_enderecamento_aberto(chaves, m, duplo_hash);
    printf("\n");
}
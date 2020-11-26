#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int sondagem_linear(int chave, int i, int table_size)
{
    return (chave + i) % table_size;
}

int sondagem_quadatica(int chave, int i, int table_size)
{
    return (chave + 3 * i + 7 * i * i) % table_size;
}

void imprime_enderecamento_aberto(int chaves[], int table_size, int (*hashing)(int chave, int i, int table_size))
{
    for (int i = 0; i < 7; i++)
    {
        printf("\n%d ->", chaves[i]);

        for (int j = 0; j < table_size; j++)
        {
            printf(" %d", hashing(chaves[i], j, table_size));
        }
    }
}

void imprime_enderecamento_separado(int chaves[], int table_size, int (*hashing)(int chave, int i, int table_size))
{
    for (int i = 0; i < 7; i++)
    {
        printf("\n%d ->", chaves[i]);

        printf(" %d", hashing(chaves[i], 0, table_size));
    }
}

void main()
{
    int m = 7;
    int chaves[] = {2341, 4234, 2839, 430, 22, 397, 3920};

    printf("\nSondagem linear:");
    imprime_enderecamento_aberto(chaves, m, sondagem_linear);
    printf("\n");

    printf("\nSondagem quadrática:");
    imprime_enderecamento_aberto(chaves, m, sondagem_quadatica);
    printf("\n");

    printf("\nEndereçamento separado:");
    imprime_enderecamento_separado(chaves, m, sondagem_linear);
    printf("\n");
}
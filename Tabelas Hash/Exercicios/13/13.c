#include <stdio.h>

int hashing(int chave, const int table_size)
{
    return ((chave < 0) ? -chave : chave) % table_size;
}

void main()
{
    int chaves[] = {5, 28, 19, 15, 20, 33, 12, 7, 10};

    int m1 = 9, m2 = 11;

    printf("\nTabela 1:\n");
    for (int i = 0; i < 9; i++)
    {
        printf("\t%d -> %d\n", chaves[i], hashing(chaves[i], m1));
    }

    printf("\nTabela 2:\n");
    for (int i = 0; i < 9; i++)
    {
        printf("\t%d -> %d\n", chaves[i], hashing(chaves[i], m2));
    }
}
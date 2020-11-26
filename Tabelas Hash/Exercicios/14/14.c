#include <stdio.h>

int hashing(int chave, const int table_size)
{
    return (2 * ((chave < 0) ? -chave : chave) + 5) % table_size;
}

void main()
{
    int chaves[] = {12, 44, 13, 88, 23, 94, 11, 39, 20, 16, 5};

    int m = 11;

    putchar('\n');
    for (int i = 0; i < 11; i++)
    {
        printf("%d -> %d\n", chaves[i], hashing(chaves[i], m));
    }
}
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int sondagem_linear(int chave, int i, int table_size)
{
    return (11 * (chave + i)) % table_size;
}

void main()
{
    int m = 16;
    char chaves[] = {'U', 'N', 'I', 'V', 'E', 'R', 'S', 'I', 'D', 'A', 'D', 'E'};

    printf("\nSondagem linear:");
    for (int i = 0; i < 12; i++)
    {
        printf("\n%d ->", chaves[i]);

        for (int j = 0; j < m; j++)
        {
            printf(" %d", sondagem_linear(chaves[i], j, m));
        }
    }
    printf("\n");
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char **insert_sorted(char **array, int *size, const char *name)
{
    array = (*size == 0) ? (char **)malloc((++(*size)) * sizeof(char *)) : (char **)realloc(array, (++(*size)) * sizeof(char *));

    int j;
    for (j = (*size) - 1; j > 0 && strcmp(name, array[j - 1]) < 0; j--)
    {
        array[j] = array[j - 1];
    }

    array[j] = (char *)malloc(strlen(name) * sizeof(char));
    strcpy(array[j], name);

    return array;
}

int main()
{
    int size = 0;
    char **names = NULL;

    while (true)
    {
        char name[50];

        printf("\nInforme um nome (0 para sair): ");
        fgets(name, sizeof(name), stdin);

        if (name[strlen(name) - 1] == '\n')
        {
            name[strlen(name) - 1] = '\0';
        }

        if (strcmp(name, "0") == 0)
        {
            break;
        }

        names = insert_sorted(names, &size, name);
    }

    puts("\nImprimindo os nomes ordenados de acordo com a tabela ASCII:");
    for (int i = 0; i < size; i++)
    {
        puts(names[i]);
    }

    return 0;
}
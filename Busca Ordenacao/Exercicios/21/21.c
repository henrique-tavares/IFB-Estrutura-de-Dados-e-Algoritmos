#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Pessoa
{
    int matricula;
    char nome[30];
    float nota;

} Pessoa;

typedef enum SortOrder
{
    MATRICULA = 1,
    NOME,
    NOTA
} SortOrder;

bool compare_by(Pessoa *p1, Pessoa *p2, SortOrder order_by)
{
    switch (order_by)
    {
    case MATRICULA:
        return (p1->matricula < p2->matricula);

    case NOME:
        return (strcmp(p1->nome, p2->nome) < 0);

    case NOTA:
        return (p1->nota < p2->nota);
    }
}

void merge(Pessoa *pessoas, int begin, int middle, int end, SortOrder order_by)
{
    int size = end - begin + 1;

    Pessoa *pessoas_temp = (Pessoa *)malloc(size * sizeof(Pessoa));

    for (int i = 0, i_aux1 = begin, i_aux2 = middle + 1; i < size; i++)
    {
        if (i_aux1 <= middle && i_aux2 <= end)
        {
            if (compare_by(pessoas + i_aux1, pessoas + i_aux2, order_by))
            {
                pessoas_temp[i] = pessoas[i_aux1++];
            }
            else
            {
                pessoas_temp[i] = pessoas[i_aux2++];
            }
        }
        else if (i_aux1 <= middle)
        {
            pessoas_temp[i] = pessoas[i_aux1++];
        }
        else
        {
            pessoas_temp[i] = pessoas[i_aux2++];
        }
    }

    for (int i = 0, j = begin; i < size; i++, j++)
    {
        pessoas[j] = pessoas_temp[i];
    }

    free(pessoas_temp);
}

void merge_sort_pessoa(Pessoa *pessoas, int begin, int end, SortOrder order_by)
{
    if (begin < end)
    {
        int middle = (begin + end) / 2;

        merge_sort_pessoa(pessoas, begin, middle, order_by);
        merge_sort_pessoa(pessoas, middle + 1, end, order_by);
        merge(pessoas, begin, middle, end, order_by);
    }
}

int main()
{
    int size = 0;
    Pessoa *pessoas = NULL;

    system("clear || cls");

    while (true)
    {
        int matricula;
        char nome[30];
        float nota;

        printf("\nInforme a matrícula (0 para sair): ");
        scanf("%d", &matricula);
        getchar();

        if (matricula == 0)
        {
            break;
        }

        printf("Informe o nome: ");
        fgets(nome, sizeof(nome), stdin);
        if (nome[strlen(nome) - 1] == '\n')
        {
            nome[strlen(nome) - 1] = '\0';
        }

        printf("Informe a nota: ");
        scanf("%f", &nota);
        getchar();

        if (size == 0)
        {
            pessoas = (Pessoa *)malloc((++size) * sizeof(Pessoa));
        }
        else
        {
            pessoas = (Pessoa *)realloc(pessoas, (++size) * sizeof(Pessoa));
        }

        pessoas[size - 1].matricula = matricula;
        strcpy(pessoas[size - 1].nome, nome);
        pessoas[size - 1].nota = nota;
    }

    int order_by;

    do
    {
        system("clear || cls");

        puts("\nSelecione o campo que deseja fazer a ordenação: ");
        puts("\t1 - matrícula");
        puts("\t2 - nome");
        puts("\t3 - nota");

        printf("\nInforme sua escolha: ");
        scanf("%d", &order_by);
        getchar();

    } while (order_by < 1 || order_by > 3);

    system("clear || cls");

    for (int i = 0; i < size; i++)
    {
        printf("\nMatrícula: %d\n", pessoas[i].matricula);
        printf("Nome: %s\n", pessoas[i].nome);
        printf("Nota: %.2f\n", pessoas[i].nota);
    }

    merge_sort_pessoa(pessoas, 0, size - 1, order_by);
    printf("\nOrdenando...\n");

    for (int i = 0; i < size; i++)
    {
        printf("\nMatrícula: %d\n", pessoas[i].matricula);
        printf("Nome: %s\n", pessoas[i].nome);
        printf("Nota: %.2f\n", pessoas[i].nota);
    }

    free(pessoas);

    return 0;
}
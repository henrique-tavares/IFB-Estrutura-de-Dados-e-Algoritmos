#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaProduto.h"

Produto *cria_produto(int codigo, char nome[], float valor, int qtd_estoque)
{
    Produto *produto = (Produto *)malloc(sizeof(Produto));

    if (produto == NULL)
    {
        printf("\nERRO: Memória insuficiente!\n");
        exit(1);
    }

    produto->codigo = codigo;
    produto->valor = valor;
    produto->qtd_estoque = qtd_estoque;

    if (strlen(nome) < 10)
    {
        strcpy(produto->nome, nome);
    }
    else
    {
        strcpy(produto->nome, "null");
    }

    return produto;
}

void libera_produto(Produto *prod)
{
    free(prod);
}

Elemento *cria_elemento(Produto *prod)
{
    Elemento *elemento = (Elemento *)malloc(sizeof(Elemento));

    if (elemento == NULL)
    {
        printf("\nERRO: Memória insuficiente!\n");
        exit(1);
    }

    elemento->produto = prod;
    elemento->prox = NULL;

    return elemento;
}

void libera_elemento(Elemento *elemento)
{
    elemento->prox = NULL;
    free(elemento->produto);
    free(elemento);
}

Lista *cria_lista()
{
    Lista *lista = (Lista *)malloc(sizeof(Lista));

    if (lista == NULL)
    {
        printf("\nERRO: Memória insuficiente!\n");
        exit(1);
    }

    lista->primeiro = NULL;
    lista->tamanho = 0;

    return lista;
}

void libera_lista(Lista *lista)
{
    for (Elemento *e = NULL; lista->primeiro != NULL; libera_elemento(e))
    {
        e = lista->primeiro;
        lista->primeiro = lista->primeiro->prox;
    }

    free(lista);
}

int contem(Lista *lista, char nome[])
{
    for (Elemento *e = lista->primeiro; e != NULL; e = e->prox)
    {
        if (strcmp(e->produto->nome, nome) == 0)
        {
            return true;
        }
    }

    return false;
}

void listar(Lista *lista)
{
    for (Elemento *e = lista->primeiro; e != NULL; e = e->prox)
    {
        printf("\nProduto:\n\tCódigo: %d\n\tNome: %s\n\tPreço: R$%.2f\n\tQuantidade: %d\n",
               e->produto->codigo, e->produto->nome, e->produto->valor, e->produto->qtd_estoque);
    }
}

void insere(Lista *lista, Produto *prod)
{
    Elemento *elemento = cria_elemento(prod);

    elemento->prox = lista->primeiro;
    lista->primeiro = elemento;

    lista->tamanho++;
}

void retira(Lista *lista, int codigo)
{
    if (vazio(lista))
    {
        return;
    }

    if (lista->primeiro->produto->codigo == codigo)
    {
        Elemento *e = lista->primeiro;

        lista->primeiro = lista->primeiro->prox;
        libera_elemento(e);

        lista->tamanho--;
        return;
    }

    for (Elemento *ant = lista->primeiro, *e = lista->primeiro->prox; e != NULL; ant = e, e = e->prox)
    {
        if (e->produto->codigo == codigo)
        {
            ant->prox = e->prox;
            libera_elemento(e);

            lista->tamanho--;
            return;
        }
    }

    printf("\nO Produto %d não está na lista\n", codigo);
}

Produto *busca(Lista *lista, char nome[])
{
    for (Elemento *e = lista->primeiro; e != NULL; e = e->prox)
    {
        if (strcmp(e->produto->nome, nome) == 0)
        {
            return e->produto;
        }
    }

    printf("\nO Produto: %s não foi encontrado\n", nome);
    return NULL;
}

int vazio(Lista *lista)
{
    return (lista->primeiro == NULL) ? true : false;
}

bool menor_preco_produto(Lista *lista, Produto *prod)
{
    if (vazio(lista))
    {
        return false;
    }

    for (Elemento *e = lista->primeiro; e != NULL; e = e->prox)
    {
        if (e == lista->primeiro || e->produto->valor < prod->valor)
        {
            prod->codigo = e->produto->codigo;
            strcpy(prod->nome, e->produto->nome);
            prod->qtd_estoque = e->produto->qtd_estoque;
            prod->valor = e->produto->valor;
        }
    }

    return true;
}

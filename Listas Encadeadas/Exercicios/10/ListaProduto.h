#pragma once
#include <stdbool.h>

// Lista encadeada simples

// Tipos exportados
typedef struct Lista Lista;
typedef struct Elemento Elemento;
typedef struct Produto Produto;

// Representa uma lista
struct Lista
{
    Elemento *primeiro;
    int tamanho;
};

// Representa um elemento da lista
struct Elemento
{
    Produto *produto;
    Elemento *prox;
};

// Representa um produto
struct Produto
{
    int codigo;      // código do produto
    char nome[10];   // nome do produto
    float valor;     // valor do produto
    int qtd_estoque; // quantidade disponível em estoque
};

// Funções exportadas

// Função cria_lista
// Cria uma lista vazia
Lista *cria_lista();

// Função libera_lista
// Libera a memória de uma lista
void libera_lista(Lista *lista);

// Função cria_elemento
// Retorna um elemento
Elemento *cria_elemento(Produto *prod);

// Função libera_elemento
// libera a memória de um elemento
void libera_elemento(Elemento *elemento);

// Função cria_produto
// retorna um produto
Produto *cria_produto(int codigo, char nome[], float valor, int qtd_estoque);

// Função libera_produto
// libera a memória de um elemento
void libera_produto(Produto *prod);

// Função contem
// Verifica se um elemento está ou não na lista
int contem(Lista *lista, char nome[]);

// Função listar
// Imprime na tela os elementos da lista
void listar(Lista *lista);

// Função insere
// Insere um elemento na lista
void insere(Lista *lista, Produto *prod);

// Função retira
// Retira um elemento na lista
void retira(Lista *lista, int codigo);

// Função busca
// Retorna um elemento da lista se a busca for bem sucedida
Produto *busca(Lista *lista, char nome[]);

// Função vazio
// Verifica se uma lista está vazia ou não
int vazio(Lista *lista);

// Questão 10
// Função menor_preco_produto
// Retorna por referencia o produto de menor preço
// Retorna se a operação foi possível
bool menor_preco_produto(Lista *lista, Produto *prod);

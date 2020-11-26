#pragma once
#include <stdbool.h>

// Lista encadeada simples

// Tipos exportados
typedef struct Lista Lista;
typedef struct Elemento Elemento;

// Representa uma lista
struct Lista
{
    Elemento *primeiro;
    int tamanho;
};

// Representa um elemento da lista
struct Elemento
{
    int valor;
    Elemento *prox;
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
Elemento *cria_elemento(int valor);

// Função libera_elemento
// libera a memória de um elemento
void libera_elemento(Elemento *elemento);

// Função contem
// Verifica se um elemento está ou não na lista
bool contem(Lista *lista, int valor);

// Função listar
// Imprime na tela os elementos da lista
void listar(Lista *lista);

// Função insere
// Insere um elemento na lista
void insere(Lista *lista, int valor);

// Função retira
// Retira um elemento na lista
void retira(Lista *lista, int valor);

// Função busca
// Retorna um elemento da lista se a busca for bem sucedida
Elemento *busca(Lista *lista, int busca);

// Função vazio
// Verifica se uma lista está vazia ou não
bool vazio(Lista *lista);

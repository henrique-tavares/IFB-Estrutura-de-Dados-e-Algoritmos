#pragma once
#include <stdbool.h>
#include <math.h>

// Lista circular dupla

// Tipos exportados
typedef struct Lista Lista;
typedef struct Elemento Elemento;
typedef struct Vertice Vertice;

// Representa uma lista
struct Lista
{
    Elemento *primeiro;
    int tamanho;
};

// Representa um elemento da lista
struct Elemento
{
    Vertice *vertice;
    Elemento *ant;
    Elemento *prox;
};

struct Vertice
{
    float x;
    float y;
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
Elemento *cria_elemento(float x, float y);

// Função libera_elemento
// libera a memória de um elemento
void libera_elemento(Elemento *elemento);

// Função contem
// Verifica se um elemento está ou não na lista
bool contem(Lista *lista, float x, float y);

// Função listar
// Imprime na tela os elementos da lista
void listar(Lista *lista);

// Função adiciona_vertice
// Adiciona um vértice na lista
void adiciona_vertice(Lista *lista, float x, float y);

// Função insere_vertice
// Insere um vértice na lista em uma determinada posição
void insere_vertice(Lista *lista, float x, float y, int pos);

// Função apaga_vertice
// Apaga um vértice da lista em uma determindada posição
void apaga_vertice(Lista *lista, int pos);

// Função remove_vertice
// Remove um vértice da lista
void remove_vertice(Lista *lista, float x, float y);

// Função vazio
// Verifica se uma lista está vazia ou não
bool vazio(Lista *lista);

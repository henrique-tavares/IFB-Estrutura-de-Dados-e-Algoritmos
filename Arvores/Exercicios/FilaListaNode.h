#pragma once
#include <stdbool.h>
#include "ListaNode.h"
#define variable(name) #name

// Fila

// Tipos exportados

// Representa um elemento da fila
typedef struct ElementoLista ElementoLista;

// Representa uma fila
typedef struct Fila Fila;

struct ElementoLista
{
    Lista *lista;
    ElementoLista *ant;
    ElementoLista *prox;
};

struct Fila
{
    ElementoLista *primeiro;
    ElementoLista *ultimo;
    int tam;
};

// Funções exportadas

// Função cria_fila
// Cria uma fila vazia
Fila *cria_fila();

// Função libera_fila
// Destrói uma fila, liberando sua memória
void libera_fila(Fila *);

// Função cria_elemento
// Cria um elemento a partir de um valor
ElementoLista *cria_elemento_lista(Lista *);

// Função libera_elemento
// Destrói um elemento, liberando sua memória
void libera_elemento_lista(ElementoLista *);

// Função enqueue
// Enfileira um elemento no final
void enqueue(Fila *, Lista *);

// Função dequeue
// Desenfileira o elemento do início
Lista *dequeue(Fila *);

// Função first
// Retorna o primeiro elemento da fila
Lista *first(Fila *);

// Função last
// Retorna o último elemento da fila
Lista *last(Fila *);

// Função tamanho
// Retorna o tamanho da fila
int tamanho(Fila *);

// Função vazia
// Verifica se a fila está vazia ou não
bool vazia(Fila *);

// Função imprime
// Imprime uma fila começando do último
void imprime(Fila *);

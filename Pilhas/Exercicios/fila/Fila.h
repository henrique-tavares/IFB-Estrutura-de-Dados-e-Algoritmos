#pragma once
#include <stdbool.h>

// Fila

// Tipos exportados

// Representa um elemento da fila
typedef struct FilaElemento FilaElemento;

// Representa uma fila
typedef struct Fila Fila;

struct FilaElemento
{
    int valor;
    FilaElemento *ant;
    FilaElemento *prox;
};

struct Fila
{
    FilaElemento *primeiro;
    FilaElemento *ultimo;
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
FilaElemento *fila_cria_elemento(int);

// Função libera_elemento
// Destrói um elemento, liberando sua memória
void fila_libera_elemento(FilaElemento *);

// Função enqueue
// Enfileira um elemento no final
void enqueue(Fila *, int);

// Função dequeue
// Desenfileira o elemento do início
int dequeue(Fila *);

// Função first
// Retorna o primeiro elemento da fila
int first(Fila *);

// Função last
// Retorna o último elemento da fila
int last(Fila *);

// Função tamanho
// Retorna o tamanho da fila
int fila_tamanho(Fila *);

// Função vazia
// Verifica se a fila está vazia ou não
bool fila_vazia(Fila *);

// Função imprime
// Imprime uma fila começando do primeiro
void fila_imprime(Fila *);

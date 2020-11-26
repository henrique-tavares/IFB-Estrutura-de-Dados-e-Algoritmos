#pragma once
#include <stdbool.h>
#include "../PilhaInt.h"

// Fila de pilhas

// Representa um elemento(pilha) da fila
typedef struct Elemento_Pilha Elemento_Pilha;

// Representa a fila
typedef struct Fila Fila;

struct Elemento_Pilha
{
    Pilha *pilha;
    Elemento_Pilha *prox;
};

struct Fila
{
    Elemento_Pilha *primeiro;
    Elemento_Pilha *ultimo;
    int tam;
};

// Funções exportadas

// Função cria_fila
// Cria uma fila vazia
Fila *cria_fila();

// Função libera_fila
// Destrói uma fila, librerando sua memória
void libera_fila(Fila *);

// Função cria_elemento_pilha
// Cria um elemento a partir de uma pilha
Elemento_Pilha *cria_elemento_pilha(Pilha *);

// Função libera_elemento_pilha
// Destrói um elemento_pilha, librando sua memória
void libera_elemento_pilha(Elemento_Pilha *);

// Função enqueue
// Enfileira uma pilha no final da fila
void enqueue(Fila *, Pilha *);

// Função dequeue
// Desenfileira a pilha do início da fila
Pilha *dequeue(Fila *);

// Função first
// Retorna a pilha do início da fila
Pilha *first(Fila *);

// Função last
// Retorna a pilha do final da fila
Pilha *last(Fila *);

// Função copia_pilha
// Retorna uma cópia de uma pilha
Pilha *copia_pilha(Pilha *);

// Função tamanho_fila
// Retorna o tamanho da fila
int tamanho_fila(Fila *);

// Função vazia_fila
// Verifica se a fila está vazia ou não
bool vazia_fila(Fila *);

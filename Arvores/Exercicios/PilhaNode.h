#pragma once
#include <stdbool.h>
#include "ArvoreInt.h"
// #include "ABBInt.h"
#define variable(name) #name

// Pilha dinânimca

// Tipos exportados

// Representa um elemento da pilha
typedef struct Elemento Elemento;

// Representa uma pilha
typedef struct Pilha Pilha;

struct Elemento
{
    Node *valor;
    Elemento *ant;
};

struct Pilha
{
    Elemento *topo;
    int tam;
};

// Funções exportadas

// Função cria_pilha
// Cria uma pilha vazia
Pilha *cria_pilha();

// Função libera_pilha
// Destrói uma pilha, liberando sua memória
void libera_pilha(Pilha *);

// Função cria_elemento
// Cria um elemento a a partir de um valor
Elemento *cria_elemento(Node *);

// Função libera_elemento
// Destóri um elemento, liberando sua memória
void libera_elemento(Elemento *);

// Função push
// Empilha um elemento no topo
void push(Pilha *, Node *);

// Função pop
// Desempilha o elemento do topo
Node *pop(Pilha *);

// Função peek
// Retorna o elemento do topo sem desempilhar
Node *peek(Pilha *);

// Função pull
// Altera o elemento do topo
void pull(Pilha *, Node *);

// Função tamanho
// Retorna o tamanho da pilha
int tamanho(Pilha *);

// Função vazia
// Verifica se uma pilha está vazia ou não
bool vazia(Pilha *);

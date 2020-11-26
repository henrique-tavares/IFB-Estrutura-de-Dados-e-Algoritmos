#pragma once
#include <stdbool.h>

// Pilha (lista encadeada dupla)

// Tipos exportados

typedef struct Pilha Pilha;
typedef struct Elemento Elemento;
typedef enum Tipo Tipo;

// Funções exportadas

// Função cria_pilha
// Cria uma pilha vazia
Pilha *cria_pilha();

// Função libera_pilha
// Destrói uma pilha, liberando sua memória
void libera_pilha(Pilha *);

// Função cria_elemento
// Cria um elemento a a partir de um valor
Elemento *cria_elemento_int(int);

// Função cria_elemento
// Cria um elemento a a partir de um valor
Elemento *cria_elemento_char(char);

// Função libera_elemento
// Destóri um elemento, liberando sua memória
void libera_elemento(Elemento *);

// Função push
// Empilha um elemento no  topo
void push_int(Pilha *, int);

// Função push
// Empilha um elemento no  topo
void push_char(Pilha *, char);

// Função pop
// Desempilha o elemento do topo
int pop_int(Pilha *);

// Função pop
// Desempilha o elemento do topo
char pop_char(Pilha *);

// Função peek
// Retorna o elemento do topo sem desempilhar
int peek_int(Pilha *);

// Função peek
// Retorna o elemento do topo sem desempilhar
char peek_char(Pilha *);

// Função peek_tipo
// Retorna o tipo do elemento do topo
Tipo peek_tipo(Pilha *);

// Função pull
// Altera o elemento do topo
void pull_int(Pilha *, int);

// Função pull
// Altera o elemento do topo
void pull_char(Pilha *, char);

// Função tamanho
// Retorna o tamanho da pilha
int tamanho(Pilha *);

// Função vazia
// Verifica se uma pilha está vazia ou não
bool vazia(Pilha *);

// Função imprime
// Imprime uma pilha começando pela base
void imprime(Pilha *);

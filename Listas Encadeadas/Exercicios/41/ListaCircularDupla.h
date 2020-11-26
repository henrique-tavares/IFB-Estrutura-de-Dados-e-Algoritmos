#pragma once
#include <stdbool.h>

// Lista Circular Duplmente Encadeada

// Tipos exportados
typedef struct Lista Lista;
typedef struct Elemento Elemento;

// Representa uma lista
struct Lista
{
	Elemento *primeiro;
	Elemento *ultimo;
	int tamanho;
};

// Representa um elemento ou nó da lista
struct Elemento
{
	int valor;
	Elemento *ant;
	Elemento *prox;
};

// Funções exportadas

/**
 * Função cria_elemento
 * Retorna um elemento novo
 */
Elemento *cria_elemento(int valor);

/**
 * Função libera_elemento
 * Libera a memória de um elemento
 */
void libera_elemento(Elemento *elemento);

/**
 * Função cria_lista
 * cria e retorna uma lista vazia 
 */
Lista *cria_lista();

/**
 * Função libera_lista
 * Libera a memória de uma lista
 */
void libera_lista(Lista *lista);

/**
 * Função adiciona
 * Adiciona um elemento no final da lista
 */
void adiciona(Lista *lista, int valor);

/**
 * Função retira
 * Retira um elemento com o valor desejado da lista
 */
void retira(Lista *lista, int valor);

/**
 * Função imprime
 * Imprime na tela a lista
 */
void imprime(Lista *lista);

/**
 * Função contem
 * Verifica se a lista contém um dado valor
 */
bool contem(Lista *lista, int valor);

/**
 * Função busca
 * Retorna o elemento de valor desejado, se possível
 */
Elemento *busca(Lista *lista, int valor);

/**
 * Função tamanho
 * Retorna o tamanho da lista
 */
int tamanho(Lista *lista);

/**
 * Função vazio
 * verifica se a lista está vazia ou não
 */
bool vazio(Lista *lista);

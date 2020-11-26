#pragma once
#include <stdbool.h>

// Questão 38

// Tipos exportados
typedef struct ListaPolinomio ListaPolinomio;
typedef struct Termo Termo;

// Representa um polinômio
struct ListaPolinomio
{
	Termo *primeiro;
	int tamanho;
};

// Representa um termo do polinônio
struct Termo
{
	int coeficiente;
	int potencia;
	Termo *prox;
};

/**
 * Função cria_polinomio
 * Retorna um polinomio vazio
 */
ListaPolinomio *cria_polinomio();

/**
 * Função libera_polinomio
 * Libera um polinomio criado previamente
 */
void libera_polinomio(ListaPolinomio *polinomio);
/**
 * Função cria_termo
 * Retorna um novo termo
 */
Termo *cria_termo(int coeficiente);

/**
 * Função libera_termo
 * Libera um termo criado previamente
 */
void libera_termo(Termo *termo);

/**
 * Função insere_termo
 * Insere um novo termo diferente de zero
 * no final do polinômio
 */
void insere_termo(ListaPolinomio *polinomio, int coeficiente);

/**
 * Função substitui_termo
 * Substitui um termo (eliminado ou não,
 * menos se o eliminado foi o último)
 * com a potência desejada, se possível
 */
void substitui_termo(ListaPolinomio *polinomio, int coeficiente, int potencia);

/**
 * Função imprime
 * Imprime um polinômio na tela
 */
void imprime(ListaPolinomio *polinomio);

/**
 * Função elimina_termo
 * Elimina o termo associado à n-enésima potência
 */
void elimina_termo(ListaPolinomio *polinomio, int potencia);

/**
 * Função reinicia_polinomio
 * Libera apenas os termos do polinômio
 */
void reinicia_polinomio(ListaPolinomio *polinomio);

/**
 * Função vazio
 * Verifica se o polinomio está vazio
 */
bool vazio(ListaPolinomio *polinomio);

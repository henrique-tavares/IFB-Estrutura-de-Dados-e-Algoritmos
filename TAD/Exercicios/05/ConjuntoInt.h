#pragma once

#include <stdbool.h>

// TAD: Conjunto de inteiros

// Tipo exportado
typedef struct ConjuntoInt ConjuntoInt;

// Funções exportadas

// Função cria_conjunto - b)
// Retorna um conjunto vazio
ConjuntoInt *cria_conjunto();

// Função libera_conjunto
// Libera a memória de um conjunto
void libera_conjunto(ConjuntoInt *);

// Função contem - g)
// Verifica se um dado número está no conjunto
bool contem(ConjuntoInt *, int);

// Função índice
// Retorna o índice de um elemento no conjunto
int indice(ConjuntoInt *, int);

// Função inserir - c)
// Insere um elemento no conjunto
void insere(ConjuntoInt *, int);

// Função retira - d)
// Retira um elemento do conjunto
void retira(ConjuntoInt *, int);

// Função uniao - a)
// Retorna a união entre dois conjuntos
ConjuntoInt *uniao(ConjuntoInt *, ConjuntoInt *);

// Função interseção - e)
// Retorna a interseção entre dois conjuntos
ConjuntoInt *intersecao(ConjuntoInt *, ConjuntoInt *);

// Função diferença - f)
// Retorna a diferença entre o primeiro e o segundo conjunto
ConjuntoInt *diferenca(ConjuntoInt *, ConjuntoInt *);

// Função max - i)
// Retorna o maior elemento do conjunto
int max(ConjuntoInt *);

// Função min - h)
// Retorna o menor elemento do conjunto
int min(ConjuntoInt *);

// Função tamanho - k)
// Retorna o tamanho do conjunto
int tamanho(ConjuntoInt *);

// Função lista_conjunto
// Imprime na tela os elementos do conjunto
void lista_conjunto(ConjuntoInt *);

// Função igual - j)
// Verifica se dois conjuntos são iguais
bool igual(ConjuntoInt *, ConjuntoInt *);

// Função vazio - l)
// Verifica se um conjunto é vazio
bool vazio(ConjuntoInt *);

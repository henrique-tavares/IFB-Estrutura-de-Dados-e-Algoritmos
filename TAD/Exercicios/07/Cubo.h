#pragma once

// TAD: Cubo

// Tipo exportado
typedef struct Cubo Cubo;

// Funções exportadas

// Função cria_cubo
// Cria um cubo dados o comprimento, a largura e a altura
Cubo *cria_cubo(float, float, float);

// Função libera_cubo
// Libera a memória de um cubo
void libera_cubo(Cubo *);

// Função comprimento
// Retorna o valor do comprimento de um cubo
float comprimento(Cubo *);

// Função largura
// Retorna o valor da largura de um cubo
float largura(Cubo *);

// Função altura
// Retorna o valor da altura de um cubo
float altura(Cubo *);

// Função area
// Retorna a área de um cubo
float area(Cubo *);

// Função volume
// Retorna o volume de um cubo
float volume(Cubo *);

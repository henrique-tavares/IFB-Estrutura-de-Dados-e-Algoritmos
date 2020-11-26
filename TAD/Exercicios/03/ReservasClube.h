#pragma once

// TAD: Sistema de Reserva de Clube

// Tipo exportado
typedef struct Clube Clube;

typedef enum Quadra Quadra;

// Funções exportadas

// Função criaClube
// Cria um clube com uma dada quantidade de quadras
Clube *cria_clube(int);

// Função liberaClube
// Libera a memória de um clube
void libera_clube(Clube *);

// Função listaClube
// Imprime na tela uma lista contendo o número de cada quadra e se elas estão livres ou não
void lista_clube(Clube *);

// Função reservaQuadra
// Reserva uma quadra para alugar se ela estiver livre dado o número da quadra
void reserva_quadra(Clube *, int);

// Função liberaQuadra
// Libera uma quadra previamente reservada
void libera_quadra(Clube *, int);

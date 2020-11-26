#pragma once

#include <stdbool.h>

// TAD: Número Racional

// Tipo exportado
typedef struct Racional Racional;

// Funções exportadas

// Função criaRacional
// Retorna um número racional
Racional *criaRacional(int, int);

// Função liberaRacional
// Libera a memória de um número racional
void liberaRacional(Racional *);

// Função numerador
// Retorna o numerador de um número racional
int numerador(Racional *);

// Função denominador
// Retorna o denominador de um número racional
int denominador(Racional *);

// Função reduz
// Retorna um número racional equivalente, porém irredutível
Racional *reduz(Racional *);

// Função inverte
// Retorna o inverso de um número racional
Racional *inverte(Racional *);

// Função soma_racional
// Retorna a soma entre dois números racionais
Racional *soma_racional(Racional *, Racional *);

// Função multiplica_racional
// Retorna a multiplicação entre dois números racionais
Racional *multiplica_racional(Racional *, Racional *);

// Função divide_racional
// Retorna a divisão entre dois números racionais
Racional *divide_racional(Racional *, Racional *);

// Função igual
// Verifica se dois números racionais são iguais
bool igual(Racional *, Racional *);

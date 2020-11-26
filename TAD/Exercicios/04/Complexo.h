#pragma once

// TAD: Número Complexo

// Tipo exportado
typedef struct Complexo Complexo;

// Funções exportadas

// Função cria
// Cria um número complexo com a sua parte real e imaginária
Complexo *cria(float, float);

// Função libera
// Libera a memória de um número complexo criado previamente
void libera(Complexo *);

// Função real
// Retorna a parte real do número complexo
float real(Complexo *);

// Função imaginario
// Retorna a parte imaginária do número complexo
float imaginario(Complexo *);

// Função soma
// Retorna a soma entre dois números complexos
Complexo *soma(Complexo *, Complexo *);

// Função subtrai
// Retorna a subtração entre dois números complexos
Complexo *subtrai(Complexo *, Complexo *);

// Função multiplica
// Retorna a multiplicação entre dois números complexos
Complexo *multiplica(Complexo *, Complexo *);

// Função divide
// Retorna a divisão entre dois números complexos
Complexo *divide(Complexo *, Complexo *);

// Função conjugado
// Retorna o conjugado de um número complexo
Complexo *conjugado(Complexo *);

#pragma once

// TAD: Cilindro

// Tipo exportado
typedef struct Cilindro Cilindro;

// Funções exportadas

// Função cria_cilindro
// Cria um cilindro dados o seu raio e altura
Cilindro *cria_cilindro(float, float);

// Função libera_cilindro
// libera a memória de um cilindro
void libera_cilindro(Cilindro *);

// Função raio
// Retorna o raio de um cilindro
float raio(Cilindro *);

// Função altura
// Retorna a altura de um cilindro
float altura(Cilindro *);

// Função area
// Retorna a área de um cilindro
float area(Cilindro *);

// Função volume
// Retorna o volume de um cilindro
float volume(Cilindro *);

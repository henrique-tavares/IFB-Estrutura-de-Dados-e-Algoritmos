#pragma once

// TAD: Esfera

// Tipo exportado
typedef struct Esfera Esfera;

// Funções exportadas

// Função cria_esfera
// Cria uma esfera dado o seu raio
Esfera *cria_esfera(float);

// Função libera_esfera
// Libera a memória de um cilindro
void libera_esfera(Esfera *);

// Função raio
// Retorna o raio de uma esfera
float raio(Esfera *);

// Função area
// Retorna a area de uma esfera
float area(Esfera *);

// Função volume
// Retorna o volume de uma esfera
float volume(Esfera *);

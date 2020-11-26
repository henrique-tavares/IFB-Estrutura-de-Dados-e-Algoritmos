#pragma once
#include "../PilhaInt.h"

/**
 * Questão 26
 * Função decimal_conversao
 * Converte um número decimal
 * para binário, octal ou hexadecimal
 */

typedef enum Base Base;

void decimal_conversao(int, Base);
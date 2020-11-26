#pragma once
#include "../ABBInt.h"

/**
 * Questão 17
 * Funções:
 *      insercao_nao_recurssiva,
 *      remocao_nao_recurssiva,
 *      busca_nao_recurssiva
 */
bool insercao_nao_recurssiva(Arvore *arvore, int valor);
bool remocao_nao_recurssiva(Arvore *arvore, int valor);
bool busca_nao_recurssiva(Arvore *arvore, int valor);
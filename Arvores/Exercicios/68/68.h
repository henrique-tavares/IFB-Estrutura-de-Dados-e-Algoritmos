#pragma once
#include <stdbool.h>
#include <string.h>
#define variable(name) #name
#define AREA_TERRITORIO_NACIONAL 85165767

typedef struct Municipio Municipio;
typedef struct Node Node;
typedef struct Arvore Arvore;

typedef enum Ordem
{
    // Pré-Ordem
    RED,
    // Em-Ordem
    ERD,
    // Pós-Ordem
    EDR,
} Ordem;

struct Municipio
{
    char *nome;
    float area;
    long int populacao;
};

struct Node
{
    Municipio municipio;
    Node *esq;
    Node *dir;

    void (*libera)(Node *self);

    int (*altura)(Node *self);
    bool (*folha)(Node *self);
};

struct Arvore
{
    Node *raiz;

    void (*libera)(Arvore *self);

    bool (*adiciona)(Arvore *self, Municipio municipio);
    Node *(*busca)(Arvore *self, char *nome);
    bool (*remove)(Arvore *self, char *nome);

    int (*qtd_municipios)(Arvore *self);
    float (*porcentagem_territorio_nacional)(Arvore *self);

    char *(*maior_populacao)(Arvore *self);

    void (*imprime_habitantes)(Arvore *self, long int limite_inf);
    void (*imprime_densidade_demografica)(Arvore *self);
    void (*imprime_alfabetico_completo)(Arvore *self);
    void (*imprime)(Arvore *self, Ordem ordem);
};

Node *cria_node(Municipio municipio);

Arvore *cria_arvore();
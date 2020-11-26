#pragma once
#include <stdbool.h>
#define variable(name) #name

typedef struct Arvore Arvore;
typedef struct Node Node;
typedef enum Lado Lado;
typedef enum Ordem Ordem;

enum Lado
{
    DIR,
    ESQ
};

enum Ordem
{
    // Pré-Ordem
    RED,
    // Em-Ordem
    ERD,
    // Pós-Ordem
    EDR
};

struct Node
{
    char valor;
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

    void (*cria_raiz)(Arvore *self, char valor);

    bool (*adiciona)(Arvore *self, char valor);
    bool (*remove)(Arvore *self, char valor);
    bool (*existe)(Arvore *self, char valor);

    int (*altura)(Arvore *self);
    void (*imprime)(Arvore *self, Ordem ordem);
};

Node *cria_node(char valor, Node *esq, Node *dir);

Arvore *cria_arvore(char raiz);

Arvore *cria_arvore_vazia();

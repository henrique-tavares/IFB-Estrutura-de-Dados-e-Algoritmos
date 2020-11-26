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
    int valor;
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

    void (*cria_raiz)(Arvore *self, int valor);

    bool (*adiciona)(Arvore *self, Node *other);
    bool (*remove)(Arvore *self, int valor);
    bool (*existe)(Arvore *self, int valor);

    int (*altura)(Arvore *self);
    void (*imprime)(Arvore *self, Ordem ordem);
};

Node *cria_node(int valor, Node *esq, Node *dir);

Arvore *cria_arvore(int raiz);

Arvore *cria_arvore_vazia();

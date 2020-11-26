#include <stdio.h>
#include <stdlib.h>
#include "ArvoreInt.h"

#pragma region FunçõesNode
void libera_node(Node *self);
int altura_node(Node *self);
bool folha(Node *self);
#pragma endregion FunçõesNode

Node *cria_node(int valor, Node *esq, Node *dir)
{
    Node *node = (Node *)malloc(sizeof(Node));

    if (node == NULL)
    {
        return NULL;
    }

    node->valor = valor;
    node->esq = esq;
    node->dir = dir;

    node->libera = &libera_node;

    node->altura = &altura_node;
    node->folha = &folha;

    return node;
}

void libera_node(Node *self)
{
    if (self->esq != NULL)
    {
        libera_node(self->esq);
    }

    if (self->dir != NULL)
    {
        libera_node(self->dir);
    }

    self->esq = NULL;
    self->dir = NULL;
    self->libera = NULL;
    self->altura = NULL;
    self->folha = NULL;

    free(self);
}

int altura_node(Node *self)
{
    if (self == NULL)
    {
        return -1;
    }

    if (folha(self))
    {
        return 0;
    }

    int alt_esq = altura_node(self->esq);
    int alt_dir = altura_node(self->dir);

    return (alt_esq > alt_dir) ? 1 + alt_esq : 1 + alt_dir;
}

bool folha(Node *self)
{
    return (self->esq == NULL && self->dir == NULL) ? true : false;
}

#pragma region FunçõesArvores
void libera_arvore(Arvore *self);
void cria_raiz(Arvore *self, int valor);
Node *adiciona_arvore(Arvore *self, Node *pai, int valor, Lado lado);
bool altera_arvore(Arvore *self, Node *node, int valor);
Node *busca_arvore(Arvore *self, int valor);
bool remove_arvore(Arvore *self, int valor);
bool existe_arvore(Arvore *self, int valor);
void imprime(Arvore *self, Ordem ordem);
int altura_arvore(Arvore *self);
#pragma endregion FunçõesArvores

Arvore *cria_arvore(int raiz)
{
    Arvore *arvore = (Arvore *)malloc(sizeof(Arvore));

    if (arvore == NULL)
    {
        return NULL;
    }

    arvore->raiz = cria_node(raiz, NULL, NULL);

    arvore->libera = &libera_arvore;

    arvore->cria_raiz = &cria_raiz;

    arvore->adiciona = &adiciona_arvore;
    arvore->altera = &altera_arvore;
    arvore->busca = &busca_arvore;
    arvore->remove = &remove_arvore;
    arvore->existe = &existe_arvore;

    arvore->altura = &altura_arvore;
    arvore->imprime = &imprime;

    return arvore;
}

Arvore *cria_arvore_vazia()
{
    Arvore *arvore = (Arvore *)malloc(sizeof(Arvore));

    if (arvore == NULL)
    {
        return NULL;
    }

    arvore->raiz = NULL;

    arvore->libera = &libera_arvore;

    arvore->cria_raiz = &cria_raiz;

    arvore->adiciona = &adiciona_arvore;
    arvore->busca = &busca_arvore;
    arvore->remove = &remove_arvore;
    arvore->existe = &existe_arvore;

    arvore->altura = &altura_arvore;
    arvore->imprime = &imprime;

    return arvore;
}

void libera_arvore(Arvore *self)
{
    if (self->raiz != NULL)
    {
        libera_node(self->raiz);
        self->raiz = NULL;
    }

    self->libera = NULL;
    self->busca = NULL;
    self->remove = NULL;
    self->existe = NULL;
    self->altura = NULL;
    self->imprime = NULL;

    free(self);
}

void cria_raiz(Arvore *self, int valor)
{
    if (self->raiz != NULL)
    {
        libera_node(self->raiz);
    }

    self->raiz = cria_node(valor, NULL, NULL);
}

Node *adiciona_arvore(Arvore *self, Node *pai, int valor, Lado lado)
{
    if (self != NULL && self->existe(self, valor))
    {
        return NULL;
    }

    if (pai == NULL)
    {
        return NULL;
    }

    Node *novo = cria_node(valor, NULL, NULL);

    if (lado == ESQ)
    {
        if (pai->esq != NULL)
        {
            libera_node(pai->esq);
            pai->esq = NULL;
        }

        pai->esq = novo;
    }
    else
    {
        if (pai->dir != NULL)
        {
            libera_node(pai->dir);
            pai->dir = NULL;
        }

        pai->dir = novo;
    }

    return novo;
}

bool altera_sub_arvore(Node *self, Node *other, int valor)
{
    if (self == NULL)
    {
        return false;
    }

    if (self == other)
    {
        self->valor = valor;
        return true;
    }

    return (altera_sub_arvore(self->esq, other, valor) || altera_sub_arvore(self->dir, other, valor)) ? true : false;
}

bool altera_arvore(Arvore *self, Node *node, int valor)
{
    return altera_sub_arvore(self->raiz, node, valor);
}

Node *busca_sub_arvore(Node *self, int valor)
{
    if (self == NULL)
    {
        return NULL;
    }

    if (self->valor == valor)
    {
        return self;
    }

    Node *busca_esq = busca_sub_arvore(self->esq, valor);
    Node *busca_dir = busca_sub_arvore(self->dir, valor);

    if (busca_esq != NULL)
    {
        return busca_esq;
    }
    else if (busca_dir != NULL)
    {
        return busca_dir;
    }
    else
    {
        return NULL;
    }
}

Node *busca_arvore(Arvore *self, int valor)
{
    return busca_sub_arvore(self->raiz, valor);
}

bool remove_sub_arvore(Node **self, int valor)
{
    if (*self == NULL)
    {
        return false;
    }

    if ((*self)->valor == valor)
    {
        libera_node(*self);
        *self = NULL;
        return true;
    }

    return (remove_sub_arvore(&((*self)->esq), valor) || remove_sub_arvore(&((*self)->dir), valor)) ? true : false;
}

bool remove_arvore(Arvore *self, int valor)
{
    return remove_sub_arvore(&(self->raiz), valor);
}

bool existe_sub_arvore(Node *self, int valor)
{
    if (self == NULL)
    {
        return false;
    }

    if (self->valor == valor)
    {
        return true;
    }

    return (existe_sub_arvore(self->esq, valor) || existe_sub_arvore(self->dir, valor)) ? true : false;
}

bool existe_arvore(Arvore *self, int valor)
{
    return existe_sub_arvore(self->raiz, valor);
}

int altura_arvore(Arvore *self)
{
    return altura_node(self->raiz);
}

void imprime_red(Node *self)
{
    if (self == NULL)
    {
        return;
    }

    printf("%d ", self->valor);
    imprime_red(self->esq);
    imprime_red(self->dir);
}

void imprime_erd(Node *self)
{
    if (self == NULL)
    {
        return;
    }

    imprime_erd(self->esq);
    printf("%d ", self->valor);
    imprime_erd(self->dir);
}

void imprime_edr(Node *self)
{
    if (self == NULL)
    {
        return;
    }

    imprime_edr(self->esq);
    imprime_edr(self->dir);
    printf("%d ", self->valor);
}

void imprime(Arvore *self, Ordem ordem)
{
    printf("[ ");

    switch (ordem)
    {
    case RED:
        imprime_red(self->raiz);
        break;

    case ERD:
        imprime_erd(self->raiz);
        break;

    case EDR:
        imprime_edr(self->raiz);
        break;
    }

    printf("]");
}

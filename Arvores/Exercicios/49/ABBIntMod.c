#include <stdio.h>
#include <stdlib.h>
#include "ABBIntMod.h"

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
bool adiciona_arvore(Arvore *self, Node *other);
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
    self->cria_raiz = NULL;
    self->adiciona = NULL;
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

bool _adiciona_arvore(Node **self, Node *other)
{
    if (*self == NULL)
    {
        return false;
    }

    if (other->valor > (*self)->valor)
    {
        if ((*self)->dir == NULL)
        {
            (*self)->dir = other;
            return true;
        }

        return _adiciona_arvore(&((*self)->dir), other);
    }
    else if (other->valor < (*self)->valor)
    {
        if ((*self)->esq == NULL)
        {
            (*self)->esq = other;
            return true;
        }

        return _adiciona_arvore(&((*self)->esq), other);
    }
    else
    {
        *self = other;
    }
}

bool adiciona_arvore(Arvore *self, Node *other)
{
    if (!self->raiz)
    {
        self->raiz = other;
        return true;
    }

    return _adiciona_arvore(&(self->raiz), other);
}

Node *_most_left(Node *self)
{
    if (!self)
    {
        return NULL;
    }

    return (self->esq) ? _most_left(self->esq) : self;
}

Node *_most_right(Node *self)
{
    if (!self)
    {
        return NULL;
    }

    return (self->dir) ? _most_right(self->dir) : self;
}

bool _remove_arvore(Node **self, int valor)
{
    if (*self == NULL)
    {
        return false;
    }

    if ((*self)->valor == valor)
    {
        if ((*self)->folha(*self))
        {
            libera_node(*self);
            *self = NULL;
        }
        else
        {
            Node *node_most_right = _most_right((*self)->esq);
            int valor_aux;

            if (node_most_right)
            {
                valor_aux = node_most_right->valor;
            }
            else
            {
                Node *node_most_left = _most_left((*self)->dir);
                valor_aux = node_most_left->valor;
            }

            _remove_arvore(self, valor_aux);
            (*self)->valor = valor_aux;
        }

        return true;
    }

    return (valor < (*self)->valor) ? _remove_arvore(&((*self)->esq), valor) : _remove_arvore(&((*self)->dir), valor);
}

bool remove_arvore(Arvore *self, int valor)
{
    return _remove_arvore(&(self->raiz), valor);
}

bool _existe_arvore(Node *self, int valor)
{
    if (self == NULL)
    {
        return false;
    }

    if (self->valor == valor)
    {
        return true;
    }

    return (valor < self->valor) ? _existe_arvore(self->esq, valor) : _existe_arvore(self->dir, valor);
}

bool existe_arvore(Arvore *self, int valor)
{
    return _existe_arvore(self->raiz, valor);
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

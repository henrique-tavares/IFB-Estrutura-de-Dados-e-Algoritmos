#include <stdio.h>
#include <stdlib.h>
#include "68.h"

#pragma region FunçõesNode
void libera_node(Node *self);
int altura_node(Node *self);
bool folha(Node *self);
#pragma endregion FunçõesNode

Node *cria_node(Municipio municipio)
{
    Node *node = (Node *)malloc(sizeof(Node));

    if (!node)
    {
        return NULL;
    }

    node->municipio = municipio;
    node->esq = NULL;
    node->dir = NULL;

    node->libera = &libera_node;
    node->altura = &altura_node;
    node->folha = &folha;

    return node;
}

void libera_node(Node *self)
{
    self->esq = NULL;
    self->dir = NULL;

    self->libera = NULL;
    self->altura = NULL;
    self->folha = NULL;

    free(self);
}

int altura_node(Node *node)
{
    if (!node)
    {
        return -1;
    }

    if (node->folha(node))
    {
        return 0;
    }

    int alt_esq = altura_node(node->esq);
    int alt_dir = altura_node(node->dir);

    int maior_filho = (alt_esq > alt_dir) ? alt_esq : alt_dir;

    return 1 + maior_filho;
}

bool folha(Node *self)
{
    return (self->esq == NULL && self->dir == NULL);
}

#pragma region FunçõesÁrvore
void libera_arvore(Arvore *self);
bool adiciona_arvore(Arvore *self, Municipio municipio);
Node *busca_arvore(Arvore *self, char *nome);
bool remove_arvore(Arvore *self, char *nome);
int qtd_municipios_arvore(Arvore *self);
float porcentagem_territorio_nacional_arvore(Arvore *self);
char *maior_populacao_arvore(Arvore *self);
void imprime_habitantes_arvore(Arvore *self, long int limite_inf);
void imprime_densidade_demografica_arvore(Arvore *self);
void imprime_alfabetico_completo_arvore(Arvore *self);
void imprime_arvore(Arvore *self, Ordem ordem);
#pragma endregion FunçõesÁrvore

Arvore *cria_arvore()
{
    Arvore *arvore = (Arvore *)malloc(sizeof(Arvore));

    if (!arvore)
    {
        return NULL;
    }

    arvore->raiz = NULL;

    arvore->libera = &libera_arvore;

    arvore->adiciona = &adiciona_arvore;
    arvore->busca = &busca_arvore;
    arvore->remove = &remove_arvore;

    arvore->qtd_municipios = &qtd_municipios_arvore;
    arvore->porcentagem_territorio_nacional = &porcentagem_territorio_nacional_arvore;
    arvore->maior_populacao = &maior_populacao_arvore;

    arvore->imprime_habitantes = &imprime_habitantes_arvore;
    arvore->imprime_densidade_demografica = &imprime_densidade_demografica_arvore;
    arvore->imprime_alfabetico_completo = &imprime_alfabetico_completo_arvore;
    arvore->imprime = &imprime_arvore;
}

void libera_arvore(Arvore *self)
{
    self->raiz = NULL;

    self->libera = NULL;

    self->adiciona = NULL;
    self->busca = NULL;
    self->remove = NULL;

    self->qtd_municipios = NULL;
    self->porcentagem_territorio_nacional = NULL;
    self->maior_populacao = NULL;

    self->imprime_habitantes = NULL;
    self->imprime_densidade_demografica = NULL;
    self->imprime_alfabetico_completo = NULL;
    self->imprime = NULL;

    free(self);
}

bool _adiciona_arvore(Node *self, Municipio municipio)
{
    if (!self)
    {
        return false;
    }

    int nome_cmp = strcmp(municipio.nome, self->municipio.nome);

    if (!self->esq && nome_cmp < 0)
    {
        self->esq = cria_node(municipio);
        return true;
    }

    if (!self->dir && nome_cmp > 0)
    {
        self->dir = cria_node(municipio);
        return true;
    }

    return (nome_cmp < 0) ? _adiciona_arvore(self->esq, municipio) : _adiciona_arvore(self->dir, municipio);
}

bool adiciona_arvore(Arvore *self, Municipio municipio)
{
    if (!self->raiz)
    {
        self->raiz = cria_node(municipio);
        return true;
    }

    return _adiciona_arvore(self->raiz, municipio);
}

Node *_busca_arvore(Node *self, char *nome)
{
    if (!self)
    {
        return NULL;
    }

    int nome_cmp = strcmp(nome, self->municipio.nome);

    if (nome_cmp == 0)
    {
        return self;
    }

    return (nome_cmp < 0) ? _busca_arvore(self->esq, nome) : _busca_arvore(self->dir, nome);
}

Node *busca_arvore(Arvore *self, char *nome)
{
    return _busca_arvore(self->raiz, nome);
}

Node *most_left(Node *node)
{
    if (!node)
    {
        return NULL;
    }

    return (node->esq) ? most_left(node->esq) : node;
}

Node *most_right(Node *node)
{
    if (!node)
    {
        return NULL;
    }

    return (node->dir) ? most_right(node->dir) : node;
}

bool _remove_arvore(Node **self, char *nome)
{
    if (*self == NULL)
    {
        return false;
    }

    int nome_cmp = strcmp(nome, (*self)->municipio.nome);

    if (nome_cmp == 0)
    {
        if ((*self)->folha(*self))
        {
            (*self)->libera(*self);
            *self = NULL;
        }
        else
        {
            Node *node_esq = most_right((*self)->esq);
            Node *node_dir = most_left((*self)->dir);
            char *nome_aux = NULL;

            if (altura_node(node_esq) >= altura_node(node_dir))
            {
                nome_aux = node_esq->municipio.nome;
            }
            else
            {
                nome_aux = node_dir->municipio.nome;
            }

            _remove_arvore(self, nome_aux);
            (*self)->municipio.nome = nome_aux;
        }

        return true;
    }

    return (nome_cmp < 0) ? _remove_arvore(&((*self)->esq), nome) : _remove_arvore(&((*self)->dir), nome);
}

bool remove_arvore(Arvore *self, char *nome)
{
    return _remove_arvore(&(self->raiz), nome);
}

int _qtd_municipios_arvore(Node *self)
{
    if (!self)
    {
        return 0;
    }

    return 1 + _qtd_municipios_arvore(self->esq) + _qtd_municipios_arvore(self->dir);
}

int qtd_municipios_arvore(Arvore *self)
{
    return _qtd_municipios_arvore(self->raiz);
}

float soma_territorio(Node *node)
{
    if (!node)
    {
        return 0;
    }

    return node->municipio.area + soma_territorio(node->esq) + soma_territorio(node->dir);
}

float porcentagem_territorio_nacional_arvore(Arvore *arvore)
{
    return (soma_territorio(arvore->raiz) / AREA_TERRITORIO_NACIONAL) * 100;
}

Municipio *_maior_populacao_arvore(Node *self)
{
    if (!self)
    {
        return NULL;
    }

    if (self->folha(self))
    {
        return &(self->municipio);
    }

    Municipio *mun_esq = _maior_populacao_arvore(self->esq);
    Municipio *mun_dir = _maior_populacao_arvore(self->dir);

    Municipio *mun_filho = NULL;

    if (mun_esq && !mun_dir)
    {
        mun_filho = mun_esq;
    }
    else if (mun_dir && !mun_esq)
    {
        mun_filho = mun_dir;
    }
    else
    {
        mun_filho = (mun_esq->populacao > mun_dir->populacao) ? mun_esq : mun_dir;
    }

    return (self->municipio.populacao > mun_filho->populacao) ? &(self->municipio) : mun_filho;
}

char *maior_populacao_arvore(Arvore *arvore)
{
    Municipio *mun = _maior_populacao_arvore(arvore->raiz);

    return mun->nome;
}

void _imprime_habitantes_arvore(Node *self, long int limite_inf)
{
    if (!self)
    {
        return;
    }

    _imprime_habitantes_arvore(self->esq, limite_inf);

    if (self->municipio.populacao > limite_inf)
    {
        printf(" %s", self->municipio.nome);
    }

    _imprime_habitantes_arvore(self->dir, limite_inf);
}

void imprime_habitantes_arvore(Arvore *self, long int limite_inf)
{
    printf("[");
    _imprime_habitantes_arvore(self->raiz, limite_inf);
    printf(" ]");
}

void _imprime_densidade_demografica_arvore(Node *self)
{
    if (!self)
    {
        return;
    }

    _imprime_densidade_demografica_arvore(self->esq);

    printf(" %s(%.2f hab/m²)", self->municipio.nome, (float)self->municipio.populacao / self->municipio.area);

    _imprime_densidade_demografica_arvore(self->dir);
}

void imprime_densidade_demografica_arvore(Arvore *self)
{
    printf("[");
    _imprime_densidade_demografica_arvore(self->raiz);
    printf(" ]");
}

void _imprime_alfabetico_completo_arvore(Node *self)
{
    if (!self)
    {
        return;
    }

    _imprime_alfabetico_completo_arvore(self->esq);

    printf("\n\tNome: %s\n\tPopulação: %ld\n\tÁrea: %.2f\n",
           self->municipio.nome, self->municipio.populacao, self->municipio.area);

    _imprime_alfabetico_completo_arvore(self->dir);
}

void imprime_alfabetico_completo_arvore(Arvore *self)
{
    printf("{");
    _imprime_alfabetico_completo_arvore(self->raiz);
    printf("}\n");
}

void imprime_red(Node *node)
{
    if (!node)
    {
        return;
    }

    printf(" %s", node->municipio.nome);
    imprime_red(node->esq);
    imprime_red(node->dir);
}

void imprime_erd(Node *node)
{
    if (!node)
    {
        return;
    }

    imprime_erd(node->esq);
    printf(" %s", node->municipio.nome);
    imprime_erd(node->dir);
}

void imprime_edr(Node *node)
{
    if (!node)
    {
        return;
    }

    imprime_edr(node->esq);
    imprime_edr(node->dir);
    printf(" %s", node->municipio.nome);
}

void imprime_arvore(Arvore *self, Ordem ordem)
{
    printf("{");
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
    printf(" }");
}

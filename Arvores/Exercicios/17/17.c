#include <stdio.h>
#include "17.h"

bool insercao_nao_recurssiva(Arvore *arvore, int valor)
{
    for (Node *node = arvore->raiz; node != NULL; node = (valor < node->valor) ? node->esq : node->dir)
    {
        if (node->valor == valor)
        {
            return false;
        }

        if (valor < node->valor && !node->esq)
        {
            Node *novo = cria_node(valor, NULL, NULL);
            node->esq = novo;
            return true;
        }
        else if (valor > node->valor && !node->dir)
        {
            Node *novo = cria_node(valor, NULL, NULL);
            node->dir = novo;
            return true;
        }
    }

    return false;
}

bool remocao_nao_recurssiva(Arvore *arvore, int valor)
{
    if (!arvore->raiz)
    {
        return false;
    }

    for (Node **node = &(arvore->raiz); *node != NULL; node = (valor < (*node)->valor) ? &((*node)->esq) : &((*node)->dir))
    {
        if (valor == (*node)->valor)
        {
            if ((*node)->folha(*node))
            {
                (*node)->libera(*node);
                *node = NULL;
            }
            else
            {
                Node *node_aux_pai = *node;
                Node *node_aux = NULL;
                for (node_aux = (*node)->esq; node_aux != NULL; node_aux = node_aux->dir)
                {
                    if (node_aux->folha(node_aux))
                    {
                        break;
                    }

                    if (node_aux == (*node)->esq)
                    {
                        node_aux_pai = node_aux_pai->esq;
                    }
                    else
                    {
                        node_aux_pai = node_aux_pai->dir;
                    }
                }

                if (node_aux)
                {
                    (*node)->valor = node_aux->valor;

                    if (node_aux == (*node)->esq)
                    {
                        node_aux_pai->esq = NULL;
                    }
                    else
                    {
                        node_aux_pai->dir = NULL;
                    }

                    node_aux->libera(node_aux);
                }
                else
                {
                    Node *node_aux_pai = *node;
                    Node *node_aux = NULL;
                    for (node_aux = (*node)->dir; node_aux != NULL; node_aux = node_aux->esq)
                    {
                        if (node_aux->folha(node_aux))
                        {
                            break;
                        }

                        if (node_aux == (*node)->dir)
                        {
                            node_aux_pai = node_aux_pai->dir;
                        }
                        else
                        {
                            node_aux_pai = node_aux_pai->esq;
                        }
                    }

                    (*node)->valor = node_aux->valor;

                    if (node_aux == (*node)->dir)
                    {
                        node_aux_pai->dir = NULL;
                    }
                    else
                    {
                        node_aux_pai->esq = NULL;
                    }

                    node_aux->libera(node_aux);
                }
            }
            return true;
        }
    }
    return false;
}

bool busca_nao_recurssiva(Arvore *arvore, int valor)
{
    for (Node *node = arvore->raiz; node != NULL; node = (valor < node->valor) ? node->esq : node->dir)
    {
        if (node->valor == valor)
        {
            return true;
        }
    }

    return false;
}

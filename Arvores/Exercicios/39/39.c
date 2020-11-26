#include <stdio.h>
#include <stdlib.h>
#include "39.h"

Fila *lista_caminhos(Arvore *arvore)
{
    Node *node = arvore->raiz;
    Fila *fila = cria_fila();
    Fila *caminhos = cria_fila();
    Fila *caminhos_final = cria_fila();

    if (node)
    {
        Lista *lista_aux = cria_lista();
        lista_aux->primeiro = cria_elemento(node);
        enqueue(fila, lista_aux);
        enqueue(caminhos, lista_aux);
    }

    while (!vazia(fila))
    {
        node = dequeue(fila)->primeiro->valor;

        if (node->folha(node))
        {
            enqueue(caminhos_final, dequeue(caminhos));
        }
        else if (node->esq && !node->dir)
        {
            Lista *caminho = dequeue(caminhos);
            Lista *caminho_aux = cria_lista();

            Elemento **ec = &(caminho_aux->primeiro);
            for (Elemento *el = caminho->primeiro; el != NULL; el = el->prox)
            {
                *ec = cria_elemento(el->valor);
                ec = &((*ec)->prox);
            }

            libera_lista(caminho);

            *ec = cria_elemento(node->esq);
            enqueue(caminhos, caminho_aux);
        }
        else if (node->dir && !node->esq)
        {
            Lista *caminho = dequeue(caminhos);
            Lista *caminho_aux = cria_lista();

            Elemento **ec = &(caminho_aux->primeiro);
            for (Elemento *el = caminho->primeiro; el != NULL; el = el->prox)
            {
                *ec = cria_elemento(el->valor);
                ec = &((*ec)->prox);
            }

            libera_lista(caminho);

            *ec = cria_elemento(node->dir);
            enqueue(caminhos, caminho_aux);
        }
        else
        {
            Lista *caminho = dequeue(caminhos);
            Lista *caminho_aux1 = cria_lista(), *caminho_aux2 = cria_lista();

            Elemento **ec1 = &(caminho_aux1->primeiro);
            Elemento **ec2 = &(caminho_aux2->primeiro);
            for (Elemento *el = caminho->primeiro; el != NULL; el = el->prox)
            {
                *ec1 = cria_elemento(el->valor);
                *ec2 = cria_elemento(el->valor);

                ec1 = &((*ec1)->prox);
                ec2 = &((*ec2)->prox);
            }

            libera_lista(caminho);

            *ec1 = cria_elemento(node->esq);
            enqueue(caminhos, caminho_aux1);

            *ec2 = cria_elemento(node->dir);
            enqueue(caminhos, caminho_aux2);
        }

        if (node->esq)
        {
            Lista *lista_aux = cria_lista();
            lista_aux->primeiro = cria_elemento(node->esq);
            enqueue(fila, lista_aux);
        }

        if (node->dir)
        {
            Lista *lista_aux = cria_lista();
            lista_aux->primeiro = cria_elemento(node->dir);
            enqueue(fila, lista_aux);
        }
    }

    return caminhos_final;
}

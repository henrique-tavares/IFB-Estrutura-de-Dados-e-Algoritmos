#include <stdio.h>
#include "../ABBInt.h"

int main()
{
    Arvore *arv = cria_arvore_vazia();

    arv->adiciona(arv, 33);
    arv->adiciona(arv, 15);
    arv->adiciona(arv, 41);
    arv->adiciona(arv, 38);
    arv->adiciona(arv, 34);
    arv->adiciona(arv, 47);
    arv->adiciona(arv, 49);
    arv->adiciona(arv, 43);

    printf("\npré-ordem: ");
    arv->imprime(arv, RED);

    printf("\nem-ordem:  ");
    arv->imprime(arv, ERD);

    printf("\npós-ordem: ");
    arv->imprime(arv, EDR);

    printf("\n\n");

    return 0;
}
#include "pilha_ponteiro.h"
#include <stdlib.h>

void Pilha_Inicia(Pilha *pPilha){
    pPilha->cabeca = (Celula *) malloc(sizeof(Celula));
    pPilha->cabeca->prox = NULL;
}

int Pilha_Eh_Vazia(Pilha *pPilha){
    if(pPilha->cabeca->prox == NULL)
        return 1;
    return 0;
}

int Pilha_Push(Pilha *pPilha, Item item){
    Celula *celula = (Celula *) malloc(sizeof(Celula));
    if(celula == NULL){
        return 0;
    }
    celula->item = item;
    celula->prox = pilha->cabeca->prox;
    pPilha->cabeca->prox = celula;
    pPilha->tamanho++;
    return 1;
}

int Pilha_Pop(Pilha *pPilha, Item *item){
    if(Pilha_Eh_Vazia(pPilha))
        return 0;

    Celula *celula = pPilha->cabeca->prox;
    pPilha->cabeca->prox = celula->prox;
    (*item) = celula->item;
    free(celula);
    pPilha->tamanho--;
    return 1;
}

int Pilha_Tamanho(Pilha *pPilha){
    return pPilha->tamanho;
}

void Pilha_Libera(Pilha *pPilha){
    Celula *celula = pPilha->cabeca;
    Celula *aux;
    while(celula != NULL){
        aux = celula->prox;
        free(celula);
        celula = aux;
    }
}

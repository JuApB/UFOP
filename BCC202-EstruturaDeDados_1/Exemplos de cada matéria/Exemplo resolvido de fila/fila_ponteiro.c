#include "fila_ponteiro.c"
#include <stdlib.h>

void FilaInicia(Fila *pFila){
    pFila->tam = 0;
    pFila->prox = NULL;
    pFila->fim = NULL;
}

int FilaVazia(Fila *pFila){
    if(pFila->tam == 0)
        return 1;
    return 0;
}

int FilaTamanho(Fila *pFila){
    return pFila->tam;
}

int FilaEnfileira(Fila *pFila, Item x){
    Celula *celula = (Celula*) malloc(sizeof(Celula));
    if(celula == NULL){
        return 0;
    }
    celula->item = x;
    celula->prox = NULL;
    if(pFila->fim == NULL){
        pFila->prox = celula;
        pFila->fim = celula;
    } else{
        pFila->fim->prox = celula;
        pFila->fim = celula;
    }
    pFila->tam++;
    return 1;
}

int FilaDesenfileira(Fila *pFila, Item *pX){
    if(pFila->tam > 0){
        Celula *aux = pFila->prox;
        pFila->prox = aux->prox;
        (*pX) = aux->item;
        pFila->tam--;
        free(aux);
        if(pFila->prox == NULL)
            pFila->fim = NULL;
        return 1;
    }
    return 0;
}

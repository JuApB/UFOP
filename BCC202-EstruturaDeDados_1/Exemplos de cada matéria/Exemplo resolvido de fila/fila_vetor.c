#include "fila_vetor.c"
#include <stdlib.h>

void FilaInicia(Fila *pFila){
    pFila->tam = 0;
    pFila->ini = 0;
    pFila->fim = MAX - 1;
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
    if(pFila->tam < MAX){
        pFila->fim = (pFila->fim + 1) % MAX;
        pFila->itens[pFila->fim] = x;
        pFila->tam++;
        return 1;
    }
    return 0;
}

int FilaDesenfileira(Fila *pFila, Item *pX){
    if(pFila->tam > 0){
        *pX = pFila->itens[pFila->ini];
        pFila->ini = (pFila->ini + 1) % MAX;
        pFila->tam--;
        return 1;
    }
    return 0;
}


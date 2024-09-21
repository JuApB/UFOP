#ifndef FILA_H
#define FILA_H

typedef int Item;

typedef struct {
    Item item;
    struct celula *prox;
} Celula;

typedef struct{
    Celula *prox, *fim;
    int tam;
} Fila;

void FilaInicia(Fila *);
int FilaVazia(Fila *);
int FilaTamanho(Fila *);
int FilaEnfileira(Fila *, Item);
int FilaDesenfileira(Fila *, Item *);

#endif
#ifndef FILA_H
#define FILA_H

#define MAX 100

typedef int Item;

typedef struct {
    Item itens[MAX];
    int tam, ini, fim;
} Fila;

void FilaInicia(Fila *);
int FilaVazia(Fila *);
int FilaTamanho(Fila *);
int FilaEnfileira(Fila *, Item);
int FilaDesenfileira(Fila *, Item *);

#endif
#ifndef ARVOREBIN_H
#define ARVOREBIN_H

#include "registro.h"
#include <stdio.h>
#include "utils.h"

typedef struct no {
  Registro registro;
  struct no *esquerda, *direita;
} No;

typedef struct {
  Registro registro;
  int posEsquerda, posDireita;
} NoExterno;

typedef struct arvore {
  No *raiz;
} ArvoreBin;

// Insere um registro na arvore binaria
void inserir(No **no, Registro registro, Metrica*);

// Monta a arvore binaria a partir de um arquivo de registros
void montaArvoreBinaria(ArvoreBin *arvore, FILE *arq, int, Metrica*);

// Monta um arquivo binario com a arvore binaria
void montaArquivo(FILE *arq, No *no, int *pos, Metrica *metrica);

// Busca um registro na arvore binaria
Registro *buscaChave(FILE *arq, int chave, int posAtual, Metrica *metrica);



#endif
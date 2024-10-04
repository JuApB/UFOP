#ifndef ACESSOSEQUENCIAL_H
#define ACESSOSEQUENCIAL_H

#include "registro.h"
#include <stdbool.h>
#include <stdio.h>

extern const int ITENSPAGINA;
extern const int MAXTABELA;

// Estrutura de índice da tabela de paginas
typedef struct {
  unsigned int posicao;
  int chave;
} TipoIndice;

typedef Registro TipoItem;

// Funcao que realiza a pesquisa sequencial
bool pesquisaAcessoSequencial(TipoIndice tabelaIndices[], int tam,
                              TipoItem *pItem, FILE *pArquivo, int tamArquivo);

#endif
#ifndef QUICKSORTEXTERNO_H
#define QUICKSORTEXTERNO_H

#include "util.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM_MEMORIA_PRINCIPAL 20

typedef struct {
  Registro area_pivos[TAM_MEMORIA_PRINCIPAL];
  unsigned int n;
} Area;

void inicializarArea(Area *area_pivos);

void troca(Registro *registros, unsigned int i, unsigned int j);

void ordenarEmMemoriaPrincipal(FILE **arquivoLi,
                               Registro area_pivos[TAM_MEMORIA_PRINCIPAL],
                               unsigned int qtde_registros);

bool syncBuffer(FILE **arquivoLi, FILE **arquivoEi, FILE **arquivoLs,
                FILE **arquivoEs);

void leParticaoInferior(FILE **arquivoLi, Registro *registro_lido,
                        unsigned int *leitura_inferior);

void escreveParticaoInferior(FILE **arquivoEi, Registro *registro_escrito,
                             unsigned int *escrita_inferior);

void leParticaoSuperior(FILE **uivoarqLs, Registro *registro_lido,
                        unsigned int *leitura_superior);

void escreveParticaoSuperior(FILE **arquivoEs, Registro *registro_escrito,
                             unsigned int *escrita_superior);

void inserirArea(Area *area, Registro *registro, Metrica *metricas);
void retirarArea(Area *area, unsigned int posicao);

void particaoExterna(FILE **arquivoLi, FILE **arquivoEi, FILE **uivoarqLs,
                     FILE **arquivoEs, Area *area, unsigned int esq,
                     unsigned int dir, int *i, int *j, Metrica *metricas);

void ordena(FILE **arquivoLi, FILE **arquivoEi, FILE **uivoarqLs,
            FILE **arquivoEs, int esq, int dir, Metrica *metricas);

bool quickSortExterno(unsigned int qtde_registros, Metrica *metricas);

void CopiaAlunosParaOrdenar(Entrada entrada, FILE *arquivoBinario);

void binParaTxt(const char *nomeArquivoBin, const char *nomeArquivoTxt,
                int quantidade);

#endif
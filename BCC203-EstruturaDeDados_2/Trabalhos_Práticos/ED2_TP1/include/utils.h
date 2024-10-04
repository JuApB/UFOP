#ifndef UTILS_H
#define UTILS_H

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  unsigned int leituras;
  unsigned int escritas;
  unsigned int comparacoes;
  clock_t inicio, fim;
  double tempo;
} Metrica;

// Imprime os argumentos passados para o programa
void imprimirArgumentos(int, char *[]);

// Abre o arquivo de registros de acordo com a situação
FILE *abrirArquivoRegistros(int);

// Fecha o arquivo de registros
void fecharArquivoRegistros(FILE *);

// Imprimir metricas
void imprimirMetricas(Metrica);

#endif
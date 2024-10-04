#ifndef UTIL_H
#define UTIL_H

// #include <cstddef>
#include <time.h>
#include <stdbool.h>
#include <stdio.h>

#define FF 40
#define F 20

/**
 * @brief Estrutura de dados que armazena os argumentos passados na linha de
 * comando.
 *
 */
typedef struct {
  int metodo;
  int registros;
  int situacao;
  bool opcional;
} Entrada;

/**
 * @brief Estrutura de dados que armazena um registro.
 *
 */
typedef struct {
  unsigned long int numeroInscricao;
  double nota;
  char estado[3];
  char cidade[51];
  char curso[31];
} Registro;

typedef struct {
  Registro reg;
  int fita;
} ItemFita;

/**
 * @brief Estrutura de dados que armazena as métricas de um algoritmo de
 * ordenação.
 *
 */
typedef struct {
  unsigned int leituras;
  unsigned int escritas;
  unsigned int comparacoes;
  clock_t inicio, fim;
  double tempo;
} Metrica;

/**
 * @brief Faz a leitura dos argumentos passados na linha de comando e verifica
 * se são válidos.
 *
 * @param entrada Estrutura de dados que armazena os argumentos passados na
 * linha de comando.
 * @param argc Quantidade de argumentos passados na linha de comando.
 * @param argv Argumentos passados na linha de comando.
 * @return true Se os argumentos são válidos.
 * @return false Se os argumentos são inválidos.
 */
bool processarEntrada(Entrada *entrada, int argc, char *argv[]);

/**
 * @brief Abre um arquivo de texto com base na situação passada.
 *
 * @param situacao Situação do arquivo de texto.
 * @return FILE* Arquivo de texto aberto.
 */
FILE *abrirArquivoTexto(int situacao);

/**
 * @brief Fecha um arquivo de texto.
 *
 * @param arquivoTexto Arquivo de texto a ser fechado.
 */
void fecharArquivoTexto(FILE *arquivoTexto);

/**
 * @brief Imprime o conteúdo de um arquivo de texto.
 *
 * @param arquivoTexto Arquivo de texto a ser impresso.
 * @param registros Quantidade de registros a serem impressos.
 */
void imprimirArquivoTexto(FILE *, int);

/**
 * @brief Abre um arquivo binário com base na situação passada.
 *
 * @param situacao Situação do arquivo binário.
 * @return FILE* Arquivo binário aberto.
 */
FILE *abrirArquivoBinario(int situacao);

/**
 * @brief Fecha um arquivo binário.
 *
 * @param arquivoBinario Arquivo binário a ser fechado.
 */
void fecharArquivoBinario(FILE *arquivoBinario);

/**
 * @brief Imprime o conteúdo de um arquivo binário.
 *
 * @param arquivoBinario Arquivo binário a ser impresso.
 * @param registros Quantidade de registros a serem impressos.
 */
void imprimirArquivoBinario(FILE *, int);

/**
 * @brief Converte um arquivo de texto para um arquivo binário.
 *
 * @param arquivoTexto Arquivo de texto a ser convertido.
 */
void converterParaBinario(FILE *, int);

/**
 * @brief Abre um arquivo binário ou converte um arquivo de texto para binário.
 *
 * @details Esta função tentará abrir um arquivo binário e, se não conseguir,
 * tentará abrir um arquivo de texto e convertê-lo para binário.
 *
 * @param situacao Situação do arquivo.
 * @return FILE* Arquivo binário aberto.
 */
void processarArquivo(int situacao);

// Imprimir metricas
void imprimirMetricas(Metrica);

// Retorna o nome do arquivo de acordo com a situacao
char *nomeArquivoSituacao(int);

#endif // UTIL_H

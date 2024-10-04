// Para cada experimento, considerando os mesmos parâmetros
// (método de ordenação, quantidade de registros, situação de ordem do arquivo),
// deve-se ocorrer a pesquisa automática de 10 chaves de pesquisa distintas, bem
// diferenciadas e existentes no arquivo em questão, no intuito de se obter a
// média de cada um dos quesitos a serem considerados no processo de análise
// experimental.
#include "../include/registro.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  // comando ./analise <metodo> <quantidade> <situacao>
  // Verifica se a quantidade de argumentos é válida
  if (argc < 4) {
    printf("\033[1;31mNúmero de argumentos inválido!\033[0m\n");
    return 0;
  }

  int metodo = atoi(argv[1]);
  int quantidade = atoi(argv[2]);
  int situacao = atoi(argv[3]);

  // relata as metricas de criação do arquivo de indices se tiver
  // calcula a media de leituras, comparacoes e tempo de execucao

  int n = quantidade; // Defina o valor de n aqui
  int k[10];   // Array para armazenar as 10 posições do arquivo selecionadas

  // Loop para calcular os 10 posições
  for (int i = 1; i <= 10; i++) {
    k[i - 1] = (int)floor((double)(i - 1) * n / 10) + 1;
  }

  FILE *pArquivoRegistros = NULL;

  Registro reg;

  switch (situacao) {
  case 1:
    pArquivoRegistros = fopen("crescente.bin", "rb");
    break;
  case 2:
    pArquivoRegistros = fopen("decrescente.bin", "rb");
    break;
  case 3:
    pArquivoRegistros = fopen("aleatorio.bin", "rb");
    break;
  default:
    printf("\033[1;31mSituação inválida\033[0m\n");
    return 0;
  }
  // Verifica se o arquivo foi aberto corretamente
  if (pArquivoRegistros == NULL) {
    printf("\033[1;31mErro ao abrir o arquivo\033[0m\n");
    return 0;
  }
  // Ler os registros
  for (int i = 0; i < 10; i++) {
    fseek(pArquivoRegistros, k[i] * sizeof(Registro), SEEK_SET);
    fread(&reg, sizeof(Registro), 1, pArquivoRegistros);
    k[i] = reg.chave;
  }

  fclose(pArquivoRegistros);

  // Imprimir as 10 chaves selecionadas
  printf("As 10 chaves selecionadas de %d registros são: ", n);
  for (int i = 0; i < 10; i++) {
    printf("%d ", k[i]);
  }
  printf("\n");

  FILE *fp;
  char comando[200];
  char resultado[200000]; // Buffer maior para capturar toda a saida
  for (int i = 0; i < 10; i++) {
    // montar o comando
    sprintf(comando, "./pesquisa %d %d %d %d", metodo, quantidade, situacao, k[i]);

    // Executar o comando
    fp = popen(comando, "r");
    if (fp == NULL) {
      printf("\033[1;31mErro ao executar o comando\033[0m\n");
      return 0;
    }

    // Ler a saida do comando
    while (fgets(resultado, sizeof(resultado), fp) != NULL) {
        printf("%s", resultado);
    }

    pclose(fp);

    printf("\n");
  }

  return 0;
}
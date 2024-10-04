#include "../include/utils.h"
#include <stdio.h>
#include <stdlib.h>

void imprimirArgumentos(int argc, char *argv[]) {
  char metodos[4][100] = {"Acesso sequencial indexado",
                          "Árvore binária adequada a memória externa",
                          "Árvore B", "Árvore B*"};

  char situacao[3][100] = {"ascendentemente", "descendentemente",
                           "aleatoriamente"};

  if (argc < 5) {
    printf("\033[1;31mNúmero de argumentos inválido\033[0m\n");
    return;
  }

  printf("\033[1;34mMétodo: %s\033[0m\n", metodos[atoi(argv[1]) - 1]);
  printf("\033[1;34mQuantidade: %d\033[0m\n", atoi(argv[2]));
  printf("\033[1;34mSituação: %s\033[0m\n", situacao[atoi(argv[3]) - 1]);
  printf("\033[1;34mChave: %d\033[0m\n", atoi(argv[4]));
  if (argc == 6) {
    printf("\033[1;34mArgumento opcional: %s\033[0m\n", argv[5]);
  }
}

FILE *abrirArquivoRegistros(int situacao) {
  FILE *pArquivo = NULL;
  switch (situacao) {
  case 1:
    pArquivo = fopen("crescente.bin", "rb");
    break;
  case 2:
    pArquivo = fopen("decrescente.bin", "rb");
    break;
  case 3:
    pArquivo = fopen("aleatorio.bin", "rb");
    break;
  default:
    printf("\033[1;31mSituação não encontrada\033[0m\n");
    break;
  }
  return pArquivo;
}

void fecharArquivoRegistros(FILE *pArquivo) { fclose(pArquivo); }

void imprimirMetricas(Metrica metrica) {
  printf("\033[1;34mLeituras: %d\033[0m\n", metrica.leituras);
  printf("\033[1;34mComparacoes: %d\033[0m\n", metrica.comparacoes);
  //printf("\033[1;34mEscritas: %d\033[0m\n", metrica.escritas);
  printf("\033[1;34mTempo: %f segundos\033[0m\n",
         (double)(metrica.fim - metrica.inicio) / CLOCKS_PER_SEC);
}
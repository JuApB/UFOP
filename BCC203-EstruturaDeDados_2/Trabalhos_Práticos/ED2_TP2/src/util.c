#include "util.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool processarEntrada(Entrada *entrada, int argc, char *argv[]) {
  // Verificar a quantidade de argumentos
  if (argc < 4 || argc > 5) {
    printf("Número de argumentos inválido!\n");
    return false;
  }

  // Verificar o metodo
  entrada->metodo = atoi(argv[1]);
  if (entrada->metodo < 1 || entrada->metodo > 3) {
    printf("Método inválido! Deve ser 1, 2 ou 3\n");
    return false;
  }

  // Verificar a quantidade
  entrada->registros = atoi(argv[2]);
  if (entrada->registros <= 0) {
    printf("Quantidade inválida!");
    printf("Deve ser um número positivo maior que zero.\n");
    return false;
  }

  // Verificar situacao
  entrada->situacao = atoi(argv[3]);
  if (entrada->situacao < 1 || entrada->situacao > 3) {
    printf("Situação inválida! Deve ser 1, 2 ou 3.\n");
    return false;
  }

  // Verificar argumento opcional (se fornecido)
  entrada->opcional = false;
  if (argc == 5) {
    if (strcmp(argv[4], "-p") != 0 && strcmp(argv[4], "-P") != 0) {
      printf("Argumento opcional inválido! Deve ser -p ou -P.\n");
      return false;
    }
    entrada->opcional = true;
  }

  // Se chegou ate aqui todos os argumentos sao validos
  return true;
}

FILE *abrirArquivoTexto(int situacao) {
  FILE *arquivoTexto = NULL;
  switch (situacao) {
  case 1:
    arquivoTexto = fopen("../../PROVAO_ASCENDENTE.txt", "r");
    break;
  case 2:
    arquivoTexto = fopen("../../PROVAO_DESCENDENTE.txt", "r");
    break;
  case 3:
    arquivoTexto = fopen("../../PROVAO.txt", "r");
    break;
  }
  if (arquivoTexto == NULL) {
    printf("Erro ao abrir o arquivo de texto na situação %d!\n", situacao);
    exit(1);
  }
  return arquivoTexto;
}

void fecharArquivoTexto(FILE *arquivoTexto) { fclose(arquivoTexto); }

void imprimirArquivoTexto(FILE *arquivoTexto, int registros) {
  int tam = 200;
  char texto[tam];
  for (int i = 0; i < registros; i++) {
    fgets(texto, tam, arquivoTexto);
    printf("%s", texto);
  }
}

FILE *abrirArquivoBinario(int situacao) {
  FILE *arquivoBinario = NULL;
  switch (situacao) {
  case 1:
    arquivoBinario = fopen("../../PROVAO_ASCENDENTE.bin", "rb");
    break;
  case 2:
    arquivoBinario = fopen("../../PROVAO_DESCENDENTE.bin", "rb");
    break;
  case 3:
    arquivoBinario = fopen("../../PROVAO.bin", "rb");
    break;
  }
  return arquivoBinario;
}

void fecharArquivoBinario(FILE *arquivoBinario) { fclose(arquivoBinario); }

void imprimirArquivoBinario(FILE *arquivoBinario, int registros) {
  Registro registro;
  for (int i = 0; i < registros; i++) {
    fread(&registro, sizeof(Registro), 1, arquivoBinario);
    printf("%08lu %05.1lf %2s %-50s %s\n", registro.numeroInscricao,
           registro.nota, registro.estado, registro.cidade, registro.curso);
  }
}

void converterParaBinario(FILE *arquivoTexto, int situacao) {
  FILE *arquivoBinario = NULL;
  switch (situacao) {
  case 1:
    arquivoBinario = fopen("../../PROVAO_ASCENDENTE.bin", "wb");
    break;
  case 2:
    arquivoBinario = fopen("../../PROVAO_DESCENDENTE.bin", "wb");
    break;
  case 3:
    arquivoBinario = fopen("../../PROVAO.bin", "wb");
    break;
  }

  Registro registro;

  // Leitura do arquivo de texto e escrita no arquivo binario
  while (fscanf(arquivoTexto, "%8lu %5lf %2s %50[A-Z'\\ -] %30s",
                &registro.numeroInscricao, &registro.nota, registro.estado,
                registro.cidade, registro.curso) != EOF) {
    fwrite(&registro, sizeof(Registro), 1, arquivoBinario);
    // Passa para a proxima linha do arquivoentrada.
    while (fgetc(arquivoTexto) != '\n')
      ;
  }

  fclose(arquivoBinario);
}

void processarArquivo(int situacao) {
  FILE *arquivoBinario = NULL;
  FILE *arquivoTexto = NULL;

  // Tenta abrir o arquivo binario
  arquivoBinario = abrirArquivoBinario(situacao);

  // Se nao tiver o arquivo binario tenta abrir o arquivo texto e converter
  if (arquivoBinario == NULL) {
    printf("Erro ao abrir o arquivo binário na situação %d!\n", situacao);
    printf("Tentando converter arquivo de texto...\n");
    arquivoTexto = abrirArquivoTexto(situacao);

    converterParaBinario(arquivoTexto, situacao);
    fecharArquivoTexto(arquivoTexto);
  } else {
    fecharArquivoBinario(arquivoBinario);
  }
}

void imprimirMetricas(Metrica metrica) {
  printf("\033[1;34mLeituras: %d\033[0m\n", metrica.leituras);
  printf("\033[1;34mEscritas: %d\033[0m\n", metrica.escritas);
  printf("\033[1;34mComparacoes: %d\033[0m\n", metrica.comparacoes);
  printf("\033[1;34mTempo: %f segundos\033[0m\n",
         (double)(metrica.fim - metrica.inicio) / CLOCKS_PER_SEC);
}

char *nomeArquivoSituacao(int situacao) {
  switch (situacao) {
  case 1:
    return "PROVAO_ASCENDENTE";
  case 2:
    return "PROVAO_DESCENDENTE";
  case 3:
    return "PROVAO";
  }
  return "";
}
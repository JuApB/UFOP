#include "../include/registro.h"
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 1000000

long int gerarLongIntAleatorio() {
  long int parteAlta = ((long int)rand() << 32) | rand();
  long int parteBaixa = ((long int)rand() << 32) | rand();
  // faz com que gere numeros negativos
  return (parteAlta << 1) ^ (parteBaixa >> 31);
}

void gerarDadoAleatorio(char *dado, int tamanho) {
  // do 32 ao 126 sao caracteres imprimiveis
  // 126 - 32 = 94
  // 94 + 1 para incluir o 126
  for (int i = 0; i < (tamanho - 1); i++) {
    int codigoAscii = (rand() % 95) + 32;
    dado[i] = codigoAscii;
  }
  dado[tamanho - 1] = '\0';
}

void crescente() {
  // Inicializa o gerador de numeros aleatorios
  srand(42);

  Registro reg;
  memset(&reg, 0, sizeof(Registro));

  FILE *pArquivo = NULL;
  pArquivo = fopen("crescente.bin", "wb");

  for (int i = 1; i <= MAX; i++) {
    reg.chave = i;
    reg.dado1 = gerarLongIntAleatorio();
    gerarDadoAleatorio(reg.dado2, 1001);
    gerarDadoAleatorio(reg.dado3, 5001);
    fwrite(&reg, sizeof(Registro), 1, pArquivo);
  }

  fclose(pArquivo);
}

void decrescente() {
  Registro reg;
  memset(&reg, 0, sizeof(Registro));

  FILE *pCrescente = NULL;
  pCrescente = fopen("crescente.bin", "rb");

  FILE *pDecrescente = NULL;
  pDecrescente = fopen("decrescente.bin", "wb");

  for (int i = MAX; i >= 1; i--) {
    fseek(pCrescente, (i - 1) * sizeof(Registro), SEEK_SET);
    fread(&reg, sizeof(Registro), 1, pCrescente);
    fwrite(&reg, sizeof(Registro), 1, pDecrescente);
  }

  fclose(pCrescente);
  fclose(pDecrescente);
}

void aleatorio() {
  // Inicializa o gerador de numeros aleatorios
  srand(42);

  Registro reg;
  memset(&reg, 0, sizeof(Registro));

  FILE *pCrescente = NULL;
  pCrescente = fopen("crescente.bin", "rb");

  FILE *pAleatorio = NULL;
  pAleatorio = fopen("aleatorio.bin", "wb");

  // Cria um vetor com os indices dos registros
  int *vetor = (int *)malloc(MAX * sizeof(int));
  for (int i = 0; i < MAX; i++) {
    vetor[i] = i;
  }

  // Embaralha o vetor
  for (int i = 0; i < MAX; i++) {
    int posicao = rand() % MAX;
    int aux = vetor[i];
    vetor[i] = vetor[posicao];
    vetor[posicao] = aux;
  }

  // Escreve os registros em ordem aleatoria
  for (int i = 0; i < MAX; i++) {
    fseek(pCrescente, vetor[i] * sizeof(Registro), SEEK_SET);
    fread(&reg, sizeof(Registro), 1, pCrescente);
    fwrite(&reg, sizeof(Registro), 1, pAleatorio);
  }

  fclose(pCrescente);
  fclose(pAleatorio);
  free(vetor);
}

int main() {

  crescente();
  decrescente();
  aleatorio();
  return 0;
}

#include "../include/registro.h"
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
  Registro reg;
  int quantidade = 10;

  FILE *pArquivo = NULL;
  pArquivo = fopen("crescente.bin", "rb");

  for (int i = 1; i <= quantidade; i++) {
    fread(&reg, sizeof(Registro), 1, pArquivo);
    printf("Registro %d: chave(%-5d) dado1(%-21ld) dado2(%-5.5s) dado3(%-5.5s)\n",
        i, reg.chave, reg.dado1, reg.dado2, reg.dado3);
  }

  fclose(pArquivo);
  return 0;
}

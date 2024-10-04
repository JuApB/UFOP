#include "../include/registro.h"
#include <stdio.h>

int main() {
  Registro reg;
  printf("Tamanho do Registro: %zu bytes \n", sizeof(reg));
  printf("Tamanho da chave: %zu bytes\n", sizeof(reg.chave));
  printf("Tamanho do dado 1: %zu bytes\n", sizeof(reg.dado1));
  printf("Tamanho do dado 2: %zu bytes\n", sizeof(reg.dado2));
  printf("Tamanho do dado 3: %zu bytes\n", sizeof(reg.dado3));
  printf("\nTamanho total: %zu\n", sizeof(reg.chave) + sizeof(reg.dado1) +
                                       sizeof(reg.dado2) + sizeof(reg.dado3));
  return 0;
}

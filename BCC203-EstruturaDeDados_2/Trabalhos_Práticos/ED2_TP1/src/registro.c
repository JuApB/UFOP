#include "../include/registro.h"
#include <stdio.h>

void imprimirRegistro(Registro *registro) {
  printf("Chave: %d\n", registro->chave);
  printf("Dado1: %ld\n", registro->dado1);
  printf("Dado2: %.15s ...\n", registro->dado2);
  printf("Dado3: %.15s ...\n", registro->dado3);
}
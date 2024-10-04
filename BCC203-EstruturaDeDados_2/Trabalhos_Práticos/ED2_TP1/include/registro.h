#ifndef REGISTRO_H
#define REGISTRO_H

typedef struct {
  int chave;
  long int dado1;
  char dado2[1001];
  char dado3[5001];
} Registro;

void imprimirRegistro(Registro *);

#endif

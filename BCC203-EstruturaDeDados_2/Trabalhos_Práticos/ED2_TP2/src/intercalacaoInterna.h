#ifndef INTERCALACAOINTERNA_H
#define INTERCALACAOINTERNA_H

#include "util.h"

typedef struct {
  int blocos;
  int registros;
} ConteudoFita;

int intercalacaoInterna(FILE *, Entrada, Metrica*);

#endif // INTERCALACAOINTERNA_H
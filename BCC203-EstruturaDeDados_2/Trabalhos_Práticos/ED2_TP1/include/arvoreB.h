#ifndef ARVOREB_H
#define ARVOREB_H

#include <stdio.h>
#include "utils.h"
#include "registro.h"

#define M1 10
#define MM1 20
#define FALSE 0
#define TRUE 1

typedef struct TipoPagina * TipoApontador;

typedef struct TipoPagina {
    short n;
    Registro r[MM1];
    TipoApontador p[MM1 + 1];
} TipoPagina;

void inicializaArvoreB(TipoApontador *Arvore);
int pesquisaArvoreB(Registro *x, TipoApontador Ap, Metrica *metrica);
void insArvoreB(Registro Reg, TipoApontador Ap, short *Cresceu, Registro *RegRetorno, TipoApontador *ApRetorno, Metrica *metrica);
void insereNaPaginaArvoreB(TipoApontador Ap, Registro Reg, TipoApontador ApDir, Metrica *metrica);
void insereArvoreB(Registro Reg, TipoApontador *Ap, Metrica *metrica);

#endif
#include "../include/b_estrela.h"  // Inclui as definições e declarações para a árvore B*.
#include "../include/utils.h"  // Inclui utilitários adicionais, métricas e outras funções auxiliares.
#include <stdbool.h>  
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  

// Inicializa uma nova árvore B*.
void inicializaBEstrela(TipoApontadorB *arvore) {
  // Aloca memória para uma nova página.
  (*arvore) = (TipoPaginaB *)malloc(sizeof(TipoPaginaB));
  // Define o tipo da página como externa.
  (*arvore)->Pt = Externa;
  // Inicializa o número de elementos na página externa como zero.
  (*arvore)->UU.U1.ne = 0;
}

// Insere uma chave e um ponteiro na página interna.
void insereNaPagInt(TipoApontadorB Ap, TipoChave Chave, TipoApontadorB ApDir, Metrica *metrica) {
  bool naoAchouPosicao;  // Variável para verificar se a posição correta foi encontrada.
  int k;  // Índice para percorrer os elementos.

  k = Ap->UU.U0.ni;  // Inicializa o índice com o número de elementos na página interna.

  metrica->comparacoes++;  // Incrementa a métrica de comparações.
  naoAchouPosicao = (k > 0);  // Verifica se há elementos na página interna.

  metrica->comparacoes++;  // Incrementa a métrica de comparações do while.
  while (naoAchouPosicao) {
    metrica->comparacoes++;  
    if (Chave >= Ap->UU.U0.ri[k - 1]) {  // Verifica se a chave é maior ou igual à chave atual.
      naoAchouPosicao = false;  // Define que a posição foi encontrada.
      break;
    }
    // Desloca as chaves e ponteiros para a direita.
    Ap->UU.U0.ri[k] = Ap->UU.U0.ri[k - 1];
    Ap->UU.U0.pi[k + 1] = Ap->UU.U0.pi[k];
    k--;

    metrica->comparacoes++;  
    if (k < 1)
      naoAchouPosicao = false;  // Define que a posição foi encontrada.
    metrica->comparacoes++;  // Incrementa a métrica de comparações do while.
  }
  // Insere a chave e o ponteiro na posição correta.
  Ap->UU.U0.ri[k] = Chave;
  Ap->UU.U0.pi[k + 1] = ApDir;
  Ap->UU.U0.ni++;  // Incrementa o número de elementos na página interna.
  return;
}

// Insere um registro na página externa.
void insereNaPagExt(TipoApontadorB Ap, TipoRegistro Reg, Metrica *metrica) {
  int k = Ap->UU.U1.ne;  // Inicializa o índice com o número de elementos na página externa.

  metrica->comparacoes++;  
  bool naoAchouPosicao = (k > 0);  // Verifica se há elementos na página externa.

  metrica->comparacoes++;  
  while (naoAchouPosicao) {
    metrica->comparacoes++; 
    if (Reg.chave >= Ap->UU.U1.re[k - 1].chave) {  // Verifica se a chave do registro é maior ou igual à chave atual.
      naoAchouPosicao = false;  // Define que a posição foi encontrada.
      break;
    }
    // Desloca os registros para a direita.
    Ap->UU.U1.re[k] = Ap->UU.U1.re[k - 1];
    k--;
    metrica->comparacoes++;  
    if (k < 1)
      naoAchouPosicao = false;  // Define que a posição foi encontrada.
    metrica->comparacoes++;  // Incrementa a métrica de comparações do while.
  }
  // Insere o registro na posição correta.
  Ap->UU.U1.re[k] = Reg;
  Ap->UU.U1.ne++;  // Incrementa o número de elementos na página externa.
  return;
}

// Função recursiva para inserir um registro na árvore B*.
void insBEstrela(TipoRegistro Reg, TipoApontadorB Ap, bool *Cresceu, TipoRegistro *RegRetorno, TipoApontadorB *ApRetorno, Metrica *metrica) {
  long i = 1, j;  // Variáveis de índice.
  TipoApontadorB ApTemp;  // Ponteiro temporário para nova página.

  if (Ap->Pt == Externa) {  // Verifica se a página é externa.
    if (Ap->UU.U1.ne == MM2) {  // Verifica se a página externa está cheia.
      // Não tem espaço na página externa, então é necessário dividir.
      ApTemp = (TipoApontadorB)malloc(sizeof(TipoPaginaB));  // Aloca memória para uma nova página.
      ApTemp->Pt = Externa;  // Define o tipo da nova página como externa.
      ApTemp->UU.U1.ne = 0;  // Inicializa o número de elementos na nova página como zero.

      metrica->comparacoes++;  
      if (Reg.chave < Ap->UU.U1.re[M].chave) {  // Verifica se a chave do registro é menor que a chave do meio.
        insereNaPagExt(ApTemp, Ap->UU.U1.re[MM2 - 1], metrica);  // Insere o registro na nova página.
        Ap->UU.U1.ne--;  // Decrementa o número de elementos na página atual.
        insereNaPagExt(Ap, Reg, metrica);  // Insere o registro na página atual.
      } else {
        insereNaPagExt(ApTemp, Reg, metrica);  // Insere o registro na nova página.
      }

      // Dividir a página externa.
      for (j = M + 2; j <= MM2; j++) {
        insereNaPagExt(ApTemp, Ap->UU.U1.re[j - 1], metrica);  // Move metade dos elementos para a nova página.
      }

      Ap->UU.U1.ne = M + 1;  // Atualiza o número de elementos na página atual.
      *RegRetorno = Ap->UU.U1.re[M];  // Define o registro de retorno.
      *ApRetorno = ApTemp;  // Define a nova página de retorno.
      *Cresceu = true;  // Define que a árvore cresceu.
      return;
    } else {
      // Tem espaço na página externa.
      insereNaPagExt(Ap, Reg, metrica);  // Insere o registro na página.
      *Cresceu = false;  // Define que a árvore não cresceu.
      return;
    }
  } else {
    metrica->comparacoes++;  
    while (i < Ap->UU.U0.ni && Reg.chave > Ap->UU.U0.ri[i - 1]) {  // Percorre os elementos na página interna.
      i++;
      metrica->comparacoes++; 
    }

    metrica->comparacoes++;  
    if (Reg.chave == Ap->UU.U0.ri[i - 1]) {  // Verifica se o registro já existe.
      *Cresceu = false;  // Define que a árvore não cresceu.
      return;
    }

    metrica->comparacoes++;  
    if (Reg.chave < Ap->UU.U0.ri[i - 1])
      i--;  // Ajusta o índice.

    // Chama recursivamente a função para inserir na subárvore adequada.
    insBEstrela(Reg, Ap->UU.U0.pi[i], Cresceu, RegRetorno, ApRetorno, metrica);

    if (!*Cresceu)
      return;  // Se a árvore não cresceu, retorna.

    if (Ap->UU.U0.ni < MM) {  // Verifica se há espaço na página interna.
      insereNaPagInt(Ap, RegRetorno->chave, *ApRetorno, metrica);  // Insere o registro na página interna.
      *Cresceu = false;  // Define que a árvore não cresceu.
      return;
    }

    // Não há espaço na página interna, então é necessário dividir.
    ApTemp = (TipoApontadorB)malloc(sizeof(TipoPaginaB));  // Aloca memória para uma nova página.
    ApTemp->Pt = Interna;  // Define o tipo da nova página como interna.
    ApTemp->UU.U0.ni = 0;  // Inicializa o número de elementos na nova página como zero.
    ApTemp->UU.U0.pi[0] = NULL;  // Inicializa o primeiro ponteiro da nova página como NULL.

    if (i < M + 1) {  // Verifica se a chave está na primeira metade.
      insereNaPagInt(ApTemp, Ap->UU.U0.ri[MM - 1], Ap->UU.U0.pi[MM], metrica);  // Move o último elemento para a nova página.
      Ap->UU.U0.ni--;  // Decrementa o número de elementos na página atual.
      insereNaPagInt(Ap, RegRetorno->chave, *ApRetorno, metrica);  // Insere o registro na página atual.
    } else {
      insereNaPagInt(ApTemp, RegRetorno->chave, *ApRetorno, metrica);  // Insere o registro na nova página.
    }

    for (j = M + 2; j <= MM; j++)
      insereNaPagInt(ApTemp, Ap->UU.U0.ri[j - 1], Ap->UU.U0.pi[j], metrica);  // Move metade dos elementos para a nova página.

    Ap->UU.U0.ni = M;  // Atualiza o número de elementos na página atual.
    ApTemp->UU.U0.pi[0] = Ap->UU.U0.pi[M + 1];  // Define o primeiro ponteiro da nova página.
    RegRetorno->chave = Ap->UU.U0.ri[M];  // Define o registro de retorno.
    *ApRetorno = ApTemp;  // Define a nova página de retorno.
  }
}

// Insere um registro na árvore B*.
void insereBEstrela(TipoRegistro Reg, TipoApontadorB *Ap, Metrica *metrica) {
  bool Cresceu;  // Variável para verificar se a árvore cresceu.
  TipoRegistro RegRetorno;  // Registro de retorno.
  TipoPaginaB *ApRetorno, *ApTemp;  // Ponteiros para novas páginas.

  insBEstrela(Reg, *Ap, &Cresceu, &RegRetorno, &ApRetorno, metrica);  // Chama a função recursiva para inserir o registro.

  if (Cresceu) {  // Verifica se a árvore cresceu na altura pela raiz.
    ApTemp = (TipoPaginaB *)malloc(sizeof(TipoPaginaB));  // Aloca memória para uma nova página.
    ApTemp->UU.U0.ni = 1;  // Inicializa o número de elementos na nova página como um.
    ApTemp->UU.U0.ri[0] = RegRetorno.chave;  // Define a chave do registro de retorno.
    ApTemp->UU.U0.pi[1] = ApRetorno;  // Define o ponteiro para a nova página.
    ApTemp->UU.U0.pi[0] = *Ap;  // Define o ponteiro para a página atual.
    *Ap = ApTemp;  // Atualiza o ponteiro da árvore para a nova página.
  }
}

// Pesquisa um registro na árvore B*.
bool pesquisaBEstrela(TipoRegistro *x, TipoApontadorB *Ap, Metrica *metrica) {
  int i;  // Índice para percorrer os elementos.
  TipoApontadorB Pag;  // Ponteiro para a página atual.
  Pag = *Ap;

  if ((*Ap)->Pt == Interna) {  // Verifica se a página é interna.
    i = 1;
    metrica->comparacoes++;  
    while (i < Pag->UU.U0.ni && x->chave > Pag->UU.U0.ri[i - 1]) {  // Percorre os elementos na página interna.
      i++;
      metrica->comparacoes++;  
    }

    metrica->comparacoes++;  
    if (x->chave < Pag->UU.U0.ri[i - 1])
      return pesquisaBEstrela(x, &Pag->UU.U0.pi[i - 1], metrica);  // Pesquisa na subárvore à esquerda.
    else
      return pesquisaBEstrela(x, &Pag->UU.U0.pi[i], metrica);  // Pesquisa na subárvore à direita.
  }

  i = 1;
  metrica->comparacoes++;  
  while (i < Pag->UU.U1.ne && x->chave > Pag->UU.U1.re[i - 1].chave) {  // Percorre os elementos na página externa.
    i++;
    metrica->comparacoes++;  
  }

  metrica->comparacoes++;  
  if (x->chave == Pag->UU.U1.re[i - 1].chave) {  // Verifica se encontrou o registro.
    *x = Pag->UU.U1.re[i - 1];  // Atualiza o registro encontrado.
    return true;  // Retorna verdadeiro, indicando que o registro foi encontrado.
  } else {
    return false;  // Retorna falso, indicando que o registro não foi encontrado.
  }
}
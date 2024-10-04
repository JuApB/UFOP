#include "../include/acessoSequencial.h"
#include "../include/utils.h"
#include <stdio.h>

const int ITENSPAGINA = 1024;
const int MAXTABELA = 1024;

bool pesquisaAcessoSequencial(TipoIndice tabelaIndices[], int tam,
                              TipoItem *pItem, FILE *pArquivo, int tamArquivo) {
  // variaveis para metricas
  Metrica metrica;
  metrica.comparacoes = 0;
  metrica.leituras = 0;
  metrica.inicio = clock();

  // variaveis para a pesquisa
  TipoItem pagina[ITENSPAGINA];
  int i, quantidadeItens;
  long deslocamento;

  // procura a página onde o item pode se encontrar
  i = 0;
  metrica.comparacoes++;
  while ((i < tam) && (tabelaIndices[i].chave <= pItem->chave)) {
    metrica.comparacoes++;
    i++;
  }

  // caso a chave desejada seja menor que a primeira chave.
  // o item nao existe no arquivo
  if (i == 0) {
    return false;
  } else {
    // a ultima pagina pode nao estar completa
    if (i < tam) {
      quantidadeItens = ITENSPAGINA;
    } else {
      // calcula a quantidade de itens na ultima pagina
      fseek(pArquivo, tamArquivo * sizeof(TipoItem), SEEK_SET);
      quantidadeItens = (ftell(pArquivo) / sizeof(TipoItem)) % ITENSPAGINA;
    }

    // le a pagina desejada do arquivo
    deslocamento =
        (tabelaIndices[i - 1].posicao - 1) * ITENSPAGINA * sizeof(TipoItem);
    fseek(pArquivo, deslocamento, SEEK_SET);
    fread(&pagina, sizeof(TipoItem), quantidadeItens, pArquivo);
    metrica.leituras++;

    // pesquisa sequencial na pagina lida
    for (i = 0; i < quantidadeItens; i++) {
      metrica.comparacoes++;
      if (pagina[i].chave == pItem->chave) {
        *pItem = pagina[i];
        metrica.fim = clock();
        printf(
            "\033[1;32mMetricas Pesquisa Acesso sequencial indexado\033[0m\n");
        imprimirMetricas(metrica);
        return true;
      }
    }
    metrica.fim = clock();
    printf("\033[1;34mMetricas Pesquisa Acesso sequencial indexado\033[0m\n");
    imprimirMetricas(metrica);
    return false;
  }
}
#include "../include/acessoSequencial.h"
#include "../include/arvoreB.h"
#include "../include/arvorebin.h"
#include "../include/b_estrela.h"
#include "../include/utils.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  // Verifica se a quantidade de argumentos é válida
  if (argc < 5) {
    printf("\033[1;31mNúmero de argumentos inválido!\033[0m\n");
    return 0;
  }

  int metodo = atoi(argv[1]);
  int quantidade = atoi(argv[2]);
  int situacao = atoi(argv[3]);
  int chave = atoi(argv[4]);

  FILE *pArquivoRegistros = NULL;
  pArquivoRegistros = abrirArquivoRegistros(situacao);
  if (pArquivoRegistros == NULL) {
    printf("\033[1;31mErro ao abrir o arquivo\033[0m\n");
    return 0;
  }

  // Sempre declare as variaveis fora do switch

  // Variaveis para o metodo 1
  TipoIndice tabelaIndices[MAXTABELA];
  TipoItem item;
  int pos, cont;
  FILE *pArquivoIndices = NULL;
  char nomeArquivoIndices[100];
  int quantidadeIndices = 0;
  Metrica metrica;

  // Variáveis para o método 2
  FILE *pArquivoArvoreBinaria = NULL;
  Registro *registro;
  char nomeArquivoArvoreBinaria[100];

  // Variáveis para o método 9

  switch (metodo) {
  case 1: {
    // imprimirArgumentos(argc, argv);
    if (situacao > 1) {
      printf("\033[1;31mSituação inválida para o método 1 (Acesso Sequencial "
             "Indexado)\033[0m\n");
      break;
    }

    // Forma o nome do arquivo de indices
    sprintf(nomeArquivoIndices, "indices_%d.bin", quantidade);

    // Tenta abrir o arquivo de indices
    pArquivoIndices = fopen(nomeArquivoIndices, "rb");

    // Se não conseguir, cria o arquivo de indices
    if (pArquivoIndices == NULL) {
      metrica.leituras = 0;
      metrica.comparacoes = 0;
      metrica.inicio = clock();
      pArquivoIndices = fopen(nomeArquivoIndices, "wb");

      cont = 0; // contador de itens
      pos = 0;  // posicao da pagina

      // gera a tabela de indice das paginas
      for (int i = 0; i < quantidade; i++) {
        metrica.leituras++;
        if (fread(&item, sizeof(TipoItem), 1, pArquivoRegistros) == 1) {
          cont++;
          if (cont % ITENSPAGINA == 1) {
            tabelaIndices[pos].chave = item.chave;
            tabelaIndices[pos].posicao = pos + 1;
            pos++;
          }
        }
      }
      // grava a tabela de indices no arquivo
      fwrite(tabelaIndices, sizeof(TipoIndice), pos, pArquivoIndices);

      fclose(pArquivoIndices);

      metrica.fim = clock();

      // Imprime as metricas
      printf("\033[1;32mMetricas criacao arquivo de indices\033[0m\n");
      imprimirMetricas(metrica);
      printf("\n");
    } else {
      // Se conseguir abrir o arquivo de indices
      // Calcula a quantidade de indices
      fseek(pArquivoIndices, 0, SEEK_END);
      quantidadeIndices = ftell(pArquivoIndices) / sizeof(TipoIndice);
      pos = quantidadeIndices;
      fseek(pArquivoIndices, 0, SEEK_SET);

      // Le a tabela de indices
      fread(tabelaIndices, sizeof(TipoIndice), quantidadeIndices,
            pArquivoIndices);
      fclose(pArquivoIndices);
    }

    fflush(stdout);     // limpa o buffer de saida
    item.chave = chave; // chave a ser pesquisada

    // Pesquisa a chave na tabela de indices
    if (pesquisaAcessoSequencial(tabelaIndices, pos, &item, pArquivoRegistros,
                                 quantidade)) {
      printf("\033[1;32mItem encontrado!\033[0m\n");
      imprimirRegistro(&item);
    } else {
      printf("\033[1;31mItem não encontrado!\033[0m\n");
    }
    break;
  }
  case 2: {
    // imprimirArgumentos(argc, argv);
    // Forma o nome do arquivo da arvore binaria
    sprintf(nomeArquivoArvoreBinaria, "arvoreBinaria_%s_%d.bin",
            situacao == 1   ? "crescente"
            : situacao == 2 ? "decrescente"
                            : "aleatorio",
            quantidade);

    Metrica metricaMontagemInterna = {0};
    Metrica metricaEscritaArquivo = {0};
    Metrica metricaBusca = {0};

    // Tenta abrir o arquivo da arvore binaria
    pArquivoArvoreBinaria = fopen(nomeArquivoArvoreBinaria, "rb");
    if (pArquivoArvoreBinaria == NULL) { // Não existe árvore feita
      // Inicializa a raiz da arvore
      ArvoreBin arvore;
      arvore.raiz = NULL;

      // Captura o tempo de início para a montagem da árvore
      metricaMontagemInterna.inicio = clock();
      montaArvoreBinaria(&arvore, pArquivoRegistros, quantidade,
                         &metricaMontagemInterna);
      metricaMontagemInterna.fim = clock();
      metricaMontagemInterna.tempo =
          (double)(metricaMontagemInterna.fim - metricaMontagemInterna.inicio) /
          CLOCKS_PER_SEC;

      // Se a arvore foi montada em memoria interna
      if (arvore.raiz != NULL) {
        // Cria o arquivo para a arvore binaria
        pArquivoArvoreBinaria = fopen(nomeArquivoArvoreBinaria, "wb");
        if (pArquivoArvoreBinaria != NULL) { // Se o arquivo foi criado
          pos = 0;
          // Captura o tempo de início para a escrita no arquivo
          metricaEscritaArquivo.inicio = clock();
          montaArquivo(pArquivoArvoreBinaria, arvore.raiz, &pos,
                       &metricaEscritaArquivo);
          fclose(pArquivoArvoreBinaria);

          // Reabre o arquivo para leitura
          pArquivoArvoreBinaria = fopen(nomeArquivoArvoreBinaria, "rb");
          if (pArquivoArvoreBinaria == NULL) {
            printf("Erro ao reabrir o arquivo '%s' após criação.\n",
                   nomeArquivoArvoreBinaria);
            return 0;
          }

          // Captura o tempo de fim para a escrita no arquivo
          metricaEscritaArquivo.fim = clock();
          metricaEscritaArquivo.tempo = (double)(metricaEscritaArquivo.fim -
                                                 metricaEscritaArquivo.inicio) /
                                        CLOCKS_PER_SEC;
        } else {
          printf("\033[1;31mErro ao criar o arquivo %s\033[0m\n",
                 nomeArquivoArvoreBinaria);
          return 0;
        }

        // Soma montagem interna com escrita no arquivo
        metricaMontagemInterna.tempo += metricaEscritaArquivo.tempo;
        metricaMontagemInterna.leituras += metricaEscritaArquivo.leituras;
        metricaMontagemInterna.comparacoes += metricaEscritaArquivo.comparacoes;
        printf("\033[1;34mMétricas da montagem criação dos índices:\033[0m\n");
        imprimirMetricas(metricaMontagemInterna);
      } else {
        printf("\033[1;31mErro ao montar a árvore binária\033[0m\n");
        return 0;
      }
    }

    // Tempo de busca
    metricaBusca.inicio = clock();
    registro = buscaChave(pArquivoArvoreBinaria, chave, 0, &metricaBusca);
    metricaBusca.fim = clock();
    metricaBusca.tempo =
        (double)(metricaBusca.fim - metricaBusca.inicio) / CLOCKS_PER_SEC;

    if (registro == NULL) {
      printf("Registro não encontrado!!\n");
    } else {
      imprimirRegistro(registro);
    }

    // Exibindo métricas

    printf("\033[1;34mMétricas da busca:\033[0m\n");
    imprimirMetricas(metricaBusca);

    break;
  }
  case 3: {
    Metrica metrica = {0};
    clock_t inicioArvoreB = clock();
    metrica.leituras = 0;
    metrica.comparacoes = 0;

    // Inicializa a árvore B
    TipoApontador arvoreB;
    inicializaArvoreB(&arvoreB);

    // Lê registros do arquivo e insere na árvore B
    Registro item;

    for (int i = 0; i < quantidade; i++) {
      fread(&item, sizeof(Registro), 1, pArquivoRegistros);
      metrica.leituras++;
      insereArvoreB(item, &arvoreB, &metrica);
    }

    clock_t finalArvoreB = clock();
    double montagemArvoreB =
        (double)(finalArvoreB - inicioArvoreB) / CLOCKS_PER_SEC;

    printf("\033[1;34mMétrica de criação da árvore B \033[0m\n");
    printf("\033[1;34mLeituras: %d\033[0m\n", metrica.leituras);
    printf("\033[1;34mComparações: %d\033[0m\n", metrica.comparacoes);
    printf("\033[1;34mTempo de montagem Árvore B: %f segundos\033[0m\n",
           montagemArvoreB);

    printf("\n");

    metrica.inicio = clock();
    metrica.leituras = 0;
    metrica.comparacoes = 0;

    // Prepara o item a ser pesquisado
    item.chave = chave;

    // Realiza a busca na árvore B
    if (pesquisaArvoreB(&item, arvoreB, &metrica)) {
      imprimirRegistro(&item);
      printf("\033[1;32mItem encontrado!\033[0m\n\n");
    } else {
      printf("\033[1;31mItem não encontrado!\033[0m\n\n");
    }

    metrica.fim = clock();
    metrica.tempo = (double)(metrica.fim - metrica.inicio) / CLOCKS_PER_SEC;
    printf("\033[1;34mMétrica de pesquisa da árvore B \033[0m\n");
    imprimirMetricas(metrica);

    break;
  }
  case 4: {
    TipoApontadorB arvoreBEst; // Declaração de um ponteiro para a árvore B*.
    TipoRegistro registro; // Declaração de uma variável do tipo registro.

    inicializaBEstrela(&arvoreBEst); // Inicializa a árvore B*.

    // Declaração e inicialização de métricas de criação da árvore.
    Metrica metricaCriacao;
    metricaCriacao.inicio = clock();
    metricaCriacao.leituras = 0;

    for (int i = 0; i < quantidade; i++) {
      metricaCriacao.leituras++; // Incrementa o contador de leituras.
      // Lê um registro do arquivo.
      if (fread(&registro, sizeof(TipoRegistro), 1, pArquivoRegistros) != 1) {
        printf("Erro ao ler o registro\n");
        return 0;
      }
      insereBEstrela(registro, &arvoreBEst,
                     &metricaCriacao); // Insere o registro na árvore B*.
    }
    // Armazena o tempo de término, calcula o tempo total gasto e imprime as
    // métricas de criação.
    metricaCriacao.fim = clock();
    metricaCriacao.tempo =
        (double)(metricaCriacao.fim - metricaCriacao.inicio) / CLOCKS_PER_SEC;
    printf("Métricas de criação da árvore B*:\n");
    imprimirMetricas(metricaCriacao);

    // Declaração e inicialização de métricas de pesquisa na árvore.
    Metrica metricaPesquisa;
    metricaPesquisa.inicio = clock();
    metricaPesquisa.leituras = 0;

    registro.chave = chave; // Chave a ser pesquisada
    // Pesquisa o registro na árvore B* e faz a impressão.
    if (pesquisaBEstrela(&registro, &arvoreBEst, &metricaPesquisa)) {
      metricaPesquisa.fim = clock(); // Finaliza o tempo de pesquisa.
      printf("Registro encontrado\n");
      imprimirRegistro(&registro);
    } else {
      metricaPesquisa.fim = clock(); // Finaliza o tempo de pesquisa.
      printf("Registro não encontrado\n");
    }

    printf("Métricas de pesquisa na árvore B*:\n");
    // Calcula o tempo total gasto e imprime as métricas de pesquisa.
    metricaPesquisa.tempo =
        (double)(metricaPesquisa.fim - metricaPesquisa.inicio) / CLOCKS_PER_SEC;
    imprimirMetricas(metricaPesquisa);
    break;
  }
  default: {
    printf("Método não encontrado\n");
    break;
  }
  }

  fecharArquivoRegistros(pArquivoRegistros);
  return 0;
}

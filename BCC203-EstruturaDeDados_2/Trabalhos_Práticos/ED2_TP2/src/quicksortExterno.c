#include "quicksortExterno.h"
#include "util.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Seta o valor da variavel "n" da variavel de tipo "Area" para 0.
void inicializarArea(Area *area_pivos) { area_pivos->n = 0; }

void troca(Registro *registros, unsigned int i, unsigned int j) {
  Registro auxiliar;

  auxiliar = registros[i];
  registros[i] = registros[j];
  registros[j] = auxiliar;
}

// Le "qtde_registros" registros do arquivo, armazenando-os no vetor
// "area_pivos" e os ordenando dentro dele.
void ordenarEmMemoriaPrincipal(FILE **arquivoLi,
                               Registro area_pivos[TAM_MEMORIA_PRINCIPAL],
                               unsigned int qtde_registros) {
  fread(area_pivos, sizeof(Registro), qtde_registros, *arquivoLi);

  // Ordena em memoria interna com o algoritmo Insertion Sort.
  for (unsigned int i = 0; i < qtde_registros - 1; i++)
    for (unsigned int j = i + 1; j > 0; j--)
      if (area_pivos[j].nota < area_pivos[j - 1].nota)
        troca(area_pivos, j, j - 1);
}

bool syncBuffer(FILE **arquivoLi, FILE **arquivoEi, FILE **arquivoLs,
                FILE **arquivoEs) {
  if (fflush(*arquivoLi) || fflush(*arquivoEi) || fflush(*arquivoLs) ||
      fflush(*arquivoEs))
    return false;

  return true;
}

void leparticaoExternaInferior(FILE **arquivoLi, Registro *registro_lido,
                               unsigned int *leitura_inferior) {
  fseek(*arquivoLi, (*leitura_inferior - 1) * sizeof(Registro), SEEK_SET);
  fread(registro_lido, sizeof(Registro), 1, *arquivoLi);
  (*leitura_inferior)++;
}

void escreveparticaoExternaInferior(FILE **arquivoEi,
                                    Registro *registro_escrito,
                                    unsigned int *escrita_inferior) {
  fseek(*arquivoEi, (*escrita_inferior - 1) * sizeof(Registro), SEEK_SET);
  fwrite(registro_escrito, sizeof(Registro), 1, *arquivoEi);
  (*escrita_inferior)++;
}

void leparticaoExternaSuperior(FILE **arquivoLs, Registro *registro_lido,
                               unsigned int *leitura_superior) {
  fseek(*arquivoLs, (*leitura_superior - 1) * sizeof(Registro), SEEK_SET);
  fread(registro_lido, sizeof(Registro), 1, *arquivoLs);
  (*leitura_superior)--;
}

void escreveparticaoExternaSuperior(FILE **arquivoEs,
                                    Registro *registro_escrito,
                                    unsigned int *escrita_superior) {
  fseek(*arquivoEs, (*escrita_superior - 1) * sizeof(Registro), SEEK_SET);
  fwrite(registro_escrito, sizeof(Registro), 1, *arquivoEs);
  (*escrita_superior)--;
}

void inserirArea(Area *area, Registro *registro, Metrica *metricas) {
  unsigned int i = area->n;

  while (i > 0 && registro->nota <= area->area_pivos[i - 1].nota) {
    area->area_pivos[i] = area->area_pivos[i - 1];
    i--;
    metricas->comparacoes++;
  }
  metricas->comparacoes++;

  area->area_pivos[i] = *registro;
  area->n++;
}

void retirarArea(Area *area, unsigned int posicao) {
  unsigned int i = posicao;

  area->n--;

  while (i < area->n) {
    area->area_pivos[i] = area->area_pivos[i + 1];
    i++;
  }
}

void particaoExterna(FILE **arquivoLi, FILE **arquivoEi, FILE **arquivoLs,
                     FILE **arquivoEs, Area *area, unsigned int esq,
                     unsigned int dir, int *i, int *j, Metrica *metricas) {
  unsigned int leitura_inferior;
  unsigned int escrita_inferior;
  unsigned int leitura_superior;
  unsigned int escrita_superior;
  double limite_inferior;
  double limite_superior;
  // Utilizada para saber se ira ler o item da particaoExterna inferior ou
  // superior do subarquivo.
  bool alternar;
  Registro ultimo_lido;

  leitura_inferior = escrita_inferior = esq;
  leitura_superior = escrita_superior = dir;
  limite_inferior = -1.0;
  limite_superior = 101.0;
  alternar = true;

  // Os dois comandos abaixo fazem os apontadores de leitura e escrita inferior
  // apontarem para o inicio do subarquivo.
  fseek(*arquivoLi, (leitura_inferior - 1) * sizeof(Registro), SEEK_SET);
  fseek(*arquivoEi, (escrita_inferior - 1) * sizeof(Registro), SEEK_SET);

  *i = esq - 1;
  *j = dir + 1;

  // Verifica se a quantidade de itens do subarquivo cabe em memoria principal.

  // O "+1" na expressao eh para contabilizar o primeiro elemento da diferenca,
  // ja que ele eh excluido por ela.
  if ((dir - esq) + 1 <= TAM_MEMORIA_PRINCIPAL) {
    unsigned int quantidade_registros_subarquivo;

    quantidade_registros_subarquivo = (dir - esq) + 1;

    // Le diretamente do arquivo, armazenando e ordenando os itens lidos dentro
    // da area dos pivos.
    ordenarEmMemoriaPrincipal(arquivoLi, area->area_pivos,
                              quantidade_registros_subarquivo);
    metricas->leituras++;

    // Escreve os registros ordenados no inicio do subarquivo.
    fwrite(area->area_pivos, sizeof(Registro), quantidade_registros_subarquivo,
           *arquivoEi);
    metricas->escritas++;

    // Sincroniza os buffers de cada apontador do arquivo binario.
    if (syncBuffer(arquivoLi, arquivoEi, arquivoLs, arquivoEs) == false)
      exit(1);

    *i = esq;
    *j = dir;

    return;
  }

  while (leitura_inferior <= leitura_superior) {
    if (area->n < TAM_MEMORIA_PRINCIPAL - 1) {
      if (alternar) {
        leparticaoExternaInferior(arquivoLi, &ultimo_lido, &leitura_inferior);
        metricas->leituras++;
        alternar = false;
      } else {
        leparticaoExternaSuperior(arquivoLs, &ultimo_lido, &leitura_superior);
        metricas->leituras++;
        alternar = true;
      }

      inserirArea(area, &ultimo_lido, metricas);
    } else {
      if (leitura_inferior == escrita_inferior) {
        leparticaoExternaInferior(arquivoLi, &ultimo_lido, &leitura_inferior);
        metricas->leituras++;
        alternar = false;
      } else if (leitura_superior == escrita_superior) {
        leparticaoExternaSuperior(arquivoLs, &ultimo_lido, &leitura_superior);
        metricas->leituras++;
        alternar = true;
      } else if (alternar) {
        leparticaoExternaInferior(arquivoLi, &ultimo_lido, &leitura_inferior);
        metricas->leituras++;
        alternar = false;
      } else {
        leparticaoExternaSuperior(arquivoLs, &ultimo_lido, &leitura_superior);
        metricas->leituras++;
        alternar = true;
      }

      metricas->comparacoes++;
      if (ultimo_lido.nota < limite_inferior) {
        *i = escrita_inferior;
        escreveparticaoExternaInferior(arquivoEi, &ultimo_lido,
                                       &escrita_inferior);
        metricas->escritas++;

        if (syncBuffer(arquivoLi, arquivoEi, arquivoLs, arquivoEs) == false)
          exit(1);
      } else if (ultimo_lido.nota > limite_superior) {
        *j = escrita_superior;
        escreveparticaoExternaSuperior(arquivoEs, &ultimo_lido,
                                       &escrita_superior);
        metricas->escritas++;

        if (syncBuffer(arquivoLi, arquivoEi, arquivoLs, arquivoEs) == false)
          exit(1);
      } else {
        inserirArea(area, &ultimo_lido, metricas);

        if (escrita_inferior - esq <= dir - escrita_superior) {
          limite_inferior = area->area_pivos[0].nota;
          escreveparticaoExternaInferior(arquivoEi, &area->area_pivos[0],
                                         &escrita_inferior);
          metricas->escritas++;
          retirarArea(area, 0);

          if (syncBuffer(arquivoLi, arquivoEi, arquivoLs, arquivoEs) == false)
            exit(1);
        } else {
          limite_superior = area->area_pivos[area->n - 1].nota;
          escreveparticaoExternaSuperior(
              arquivoEs, &area->area_pivos[area->n - 1], &escrita_superior);
          metricas->escritas++;
          retirarArea(area, area->n - 1);

          if (syncBuffer(arquivoLi, arquivoEi, arquivoLs, arquivoEs) == false)
            exit(1);
        }
      }
    }
  }

  while (escrita_inferior <= escrita_superior) {
    escreveparticaoExternaInferior(arquivoEi, &area->area_pivos[0],
                                   &escrita_inferior);
    metricas->escritas++;
    retirarArea(area, 0);

    if (syncBuffer(arquivoLi, arquivoEi, arquivoLs, arquivoEs) == false)
      exit(1);
  }
}

void ordena(FILE **arquivoLi, FILE **arquivoEi, FILE **arquivoLs,
            FILE **arquivoEs, int esq, int dir, Metrica *metricas) {
  // Delimita, como um indice do arquivo, o termino da particaoExterna inferior.
  int i;
  // Delimita, como um indice do arquivo, o comeco da particaoExterna superior.
  int j;
  Area area_pivos;

  // Verifica se na particaoExterna ha somente um elemento. Se sim, ja esta
  // ordenado.
  if (dir - esq < 1)
    return;

  inicializarArea(&area_pivos);

  particaoExterna(arquivoLi, arquivoEi, arquivoLs, arquivoEs, &area_pivos, esq,
                  dir, &i, &j, metricas);

  // Se o tamanho da particaoExterna inferior for menor ou igual ao tamanho da
  // particaoExterna superior, ordena ela primeiro.

  // Caso contrario, ordena a particaoExterna superior primeiro.
  if (i - esq <= dir - j) {
    ordena(arquivoLi, arquivoEi, arquivoLs, arquivoEs, esq, i, metricas);
    ordena(arquivoLi, arquivoEi, arquivoLs, arquivoEs, j, dir, metricas);
  } else {
    ordena(arquivoLi, arquivoEi, arquivoLs, arquivoEs, j, dir, metricas);
    ordena(arquivoLi, arquivoEi, arquivoLs, arquivoEs, esq, i, metricas);
  }
}

bool quickSortExterno(unsigned int qtde_registros, Metrica *metricas) {

  // Inicio da contagem de tempo de execucao do metodo.
  metricas->inicio = clock();

  // Ponteiro de leitura na particaoExterna inferior do arquivo
  // "Para_Ordenar.dat"
  FILE *arquivoLi;
  // Ponteiro de escrita na particaoExterna inferior do arquivo
  // "Para_Ordenar.dat"
  FILE *arquivoEi;
  // Ponteiro de leitura na particaoExterna superior do arquivo
  // "Para_Ordenar.dat"
  FILE *arquivoLs;
  // Ponteiro de escrita na particaoExterna superior do arquivo
  // "Para_Ordenar.dat"
  FILE *arquivoEs;

  // Fluxo condicional que verifica se foi possivel abrir todos os arquivos.
  if ((arquivoLi = fopen("Para_Ordenar.bin", "rb")) == NULL)
    return false;
  else if ((arquivoEi = fopen("Para_Ordenar.bin", "r+b")) == NULL) {
    fclose(arquivoLi);
    return false;
  } else if ((arquivoLs = fopen("Para_Ordenar.bin", "rb")) == NULL) {
    fclose(arquivoLi);
    fclose(arquivoEi);
    return false;
  } else if ((arquivoEs = fopen("Para_Ordenar.bin", "r+b")) == NULL) {
    fclose(arquivoLi);
    fclose(arquivoEi);
    fclose(arquivoLs);
    return false;
  }

  ordena(&arquivoLi, &arquivoEi, &arquivoLs, &arquivoEs, 1, qtde_registros,
         metricas);

  fclose(arquivoLi);
  fclose(arquivoEi);
  fclose(arquivoLs);
  fclose(arquivoEs);

  // Fim da contagem de tempo de execucao do metodo.
  metricas->fim = clock();
  metricas->tempo +=
      ((double)(metricas->fim - metricas->inicio)) / CLOCKS_PER_SEC;

  return true;
}

void CopiaAlunosParaOrdenar(Entrada entrada, FILE *arquivoBinario) {
  FILE *inputFile = arquivoBinario;

  FILE *outputFile = fopen("Para_Ordenar.bin", "wb");
  if (outputFile == NULL) {
    perror("Erro ao abrir Para_Ordenar.bin");
    fclose(inputFile);
    return;
  }

  Registro aluno;
  for (int i = 0; i < entrada.registros; i++) {
    size_t bytesRead = fread(&aluno, sizeof(Registro), 1, inputFile);
    if (bytesRead != 1) {
      if (feof(inputFile)) {
        printf("Número de alunos solicitado é maior do que o disponível em "
               "PROVAO.bin\n");
      } else {
        perror("Erro ao ler PROVAO.bin");
      }
      break;
    }
    fwrite(&aluno, sizeof(Registro), 1, outputFile);
  }

  fclose(outputFile);
}

void binParaTxt(const char *nomeArquivoBin, const char *nomeArquivoTxt,
                int quantidade) {
  FILE *fileBin = fopen(nomeArquivoBin, "rb");
  if (fileBin == NULL) {
    perror("Erro ao abrir o arquivo binário");
    return;
  }

  FILE *fileTxt = fopen(nomeArquivoTxt, "w");
  if (fileTxt == NULL) {
    perror("Erro ao criar o arquivo de texto");
    fclose(fileBin);
    return;
  }
  int i = 0;
  Registro registro;
  while (fread(&registro, sizeof(Registro), 1, fileBin) && i < quantidade) {
    // fprintf(fileTxt, "Inscrição: %ld\n", Registro.nInscricao);
    fprintf(fileTxt, "Nota: %.1f\n", registro.nota);
    // fprintf(fileTxt, "Estado: %s\n", Registro.estado);
    // fprintf(fileTxt, "Cidade: %s\n", Registro.cidade);
    // fprintf(fileTxt, "Curso: %s\n", Registro.curso);
    // fprintf(fileTxt, "--------------------------\n");
    i++;
  }

  fclose(fileBin);
  fclose(fileTxt);
}
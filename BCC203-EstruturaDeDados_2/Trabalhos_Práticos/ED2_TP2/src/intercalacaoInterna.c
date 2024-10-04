#include "intercalacaoInterna.h"
#include "quicksortInterno.h"
#include "util.h"
#include <stdio.h>
#include <sys/stat.h>

void abrirFitas(FILE *fitasEntrada[], FILE *fitasSaida[], int quantidadeFitas) {
  // Abre as fitas de entrada
  for (int i = 0; i < quantidadeFitas; i++) {
    char nomeFitaEntrada[50];
    sprintf(nomeFitaEntrada, "fitas/fita%d.bin", i);
    fitasEntrada[i] = fopen(nomeFitaEntrada, "wb+");
  }

  // Abre as fitas de saida
  for (int i = 0; i < quantidadeFitas; i++) {
    char nomeFitaSaida[50];
    sprintf(nomeFitaSaida, "fitas/fita%d.bin", i + quantidadeFitas);
    fitasSaida[i] = fopen(nomeFitaSaida, "wb+");
  }
}

bool tentaLerRegistro(ItemFita *memoriaInterna, FILE *fita, int blocoAtual,
                      int tamanhoBloco, ConteudoFita *conteudoFita,
                      Metrica *metrica) {
  // Posicao contem o numero de registros lidos ate o momento
  int posicao = ftell(fita) / sizeof(Registro);

  // Se a posicao for igual a quantidade de registros, retorna falso
  if (posicao == conteudoFita->registros) {
    return false;
  }

  // Se a posicao for maior que o tamanho do bloco, retorna falso
  if (posicao >= (tamanhoBloco * blocoAtual)) {
    return false;
  }

  // Le o registro
  fread(&memoriaInterna[0].reg, sizeof(Registro), 1, fita);
  metrica->leituras++;

  // Atualiza o conteudo da fita lida
  posicao = ftell(fita) / sizeof(Registro);

  // se leu um bloco atual inteiro, atualiza a quantidade de blocos
  if (posicao == (tamanhoBloco * blocoAtual)) {
    conteudoFita->blocos--;
    // o ultimo bloco pode nao estar completo
  } else if (posicao == conteudoFita->registros) {
    conteudoFita->blocos--;
  }

  return true;
}

// Verifica se existe apenas uma fita com registros
bool estaOrdenado(ConteudoFita conteudoFitas[]) {
  // Se a fita 1 nao tiver blocos, entao apenas a fita 0 tem registros
  if (conteudoFitas[1].blocos == 0) {
    return true;
  }
  return false;
}

// Verifica se existe algum bloco ativo
bool houverBlocosAtivos(ConteudoFita conteudoFitas[], int quantidadeFitas) {
  for (int i = 0; i < quantidadeFitas; i++) {
    if (conteudoFitas[i].blocos > 0) {
      return true;
    }
  }
  return false;
}

// Atualiza a quantidade de blocos
void atualizarQuantidadeBlocos(ConteudoFita *conteudoFita, int tamanhoBloco) {
  int blocosCompletos = conteudoFita->registros / tamanhoBloco;
  int blocosRestantes = conteudoFita->registros % tamanhoBloco;
  if (blocosRestantes > 0) {
    blocosCompletos++;
  }
  conteudoFita->blocos = blocosCompletos;
}

void criacaoDosBlocos(Entrada entrada, int quantidadeFitas,
                      int tamanhoMemoriaInterna, ItemFita *memoriaInterna,
                      FILE *arquivoBinario, FILE **fitasEntrada,
                      ConteudoFita *conteudoFitasEntrada, Metrica *metrica) {
  // Variaveis auxiliares
  Registro registrosAux[tamanhoMemoriaInterna]; // Vetor auxiliar para ordenacao

  // Particiona o arquivo de entrada
  int registrosParaLer = entrada.registros;
  // Contador de fitas de entrada
  int i = 0;
  while (registrosParaLer > 0) { // Geracao dos blocos ordenados

    // Reinicia o contador de fitas de entrada
    if (i == quantidadeFitas) {
      i = 0;
    }

    // Quantidade de registros a serem lidos
    int quantidade = registrosParaLer > tamanhoMemoriaInterna
                         ? tamanhoMemoriaInterna
                         : registrosParaLer;

    // Quantidade de registros lidos com sucesso
    int registrosLidos =
        fread(registrosAux, sizeof(Registro), quantidade, arquivoBinario);
    metrica->leituras++;

    // Passa os registros do vetor de Registros para o vetor de ItemFita
    for (int j = 0; j < registrosLidos; j++) {
      memoriaInterna[j].reg = registrosAux[j];
    }

    // Ordena os registros
    quicksortInterno(memoriaInterna, 0, registrosLidos - 1, metrica);

    // Escreve os registros ordenados nas fitas de entrada
    for (int j = 0; j < registrosLidos; j++) {
      registrosAux[j] = memoriaInterna[j].reg;
    }
    fwrite(registrosAux, sizeof(Registro), registrosLidos, fitasEntrada[i]);
    metrica->escritas++;

    // Atualiza a quantidade de blocos e registros na fita de entrada
    conteudoFitasEntrada[i].blocos++;
    conteudoFitasEntrada[i].registros += registrosLidos;

    // Atualiza a quantidade de registros a serem lidos
    registrosParaLer -= registrosLidos;

    // Avanca para a proxima fita de entrada
    i++;
  }
}

int intercalacaoDosBlocos(int quantidadeFitas, ItemFita *memoriaInterna,
                          FILE **fitasEntrada, FILE **fitasSaida,
                          ConteudoFita *conteudoFitasEntrada,
                          ConteudoFita *conteudoFitasSaida, Metrica *metrica) {
  // Variaveis auxiliares
  int blocoAtual = 1; // Qual bloco esta sendo intercalado
  int saidaAtual = 0; // Qual fita de saida esta sendo utilizada
  int tamanhoBlocoEntrada = 20;
  int tamanhoBlocoSaida = 400; // A primeira intercalacao tera 400 registros
  int registrosNaMemoriaInterna = 0;

  // Variaveis auxiliares para alternar entre as fitas de entrada e saida
  FILE **entrada = fitasEntrada;
  ConteudoFita *conteudoEntrada = conteudoFitasEntrada;

  FILE **saida = fitasSaida;
  ConteudoFita *conteudoSaida = conteudoFitasSaida;

  bool alternancia = false; // Alternancia entre as fitas de entrada e saida
  // se for false, intercalando de entrada para saida
  // se for true, intercalando de saida para entrada

  // Enquanto nao houver apenas 1 fita com registros
  while (!estaOrdenado(conteudoEntrada)) {
    // Enquanto houver blocos nas fitas de entrada para ser intercalado
    while (houverBlocosAtivos(conteudoEntrada, quantidadeFitas)) {
      // Leitura do primeiro registro de cada fita de entrada
      for (int i = 0; i < quantidadeFitas; i++) {
        if (tentaLerRegistro(&memoriaInterna[i], entrada[i], blocoAtual,
                             tamanhoBlocoEntrada, &conteudoEntrada[i],
                             metrica)) {
          registrosNaMemoriaInterna++;
          memoriaInterna[i].fita = i;
        }
      }

      // Reinicia para qual fita de saida sera escrito
      if (saidaAtual == quantidadeFitas) {
        saidaAtual = 0;
      }

      // Executa um laco de repeticao até terminar de intercalar um bloco de
      // cada fita
      while (registrosNaMemoriaInterna > 0) {
        quicksortInterno(memoriaInterna, 0, registrosNaMemoriaInterna - 1,
                         metrica);

        fwrite(&memoriaInterna[0].reg, sizeof(Registro), 1, saida[saidaAtual]);
        metrica->escritas++;
        conteudoSaida[saidaAtual].registros++;
        // Atualiza a quantidade de blocos
        atualizarQuantidadeBlocos(&conteudoSaida[saidaAtual],
                                  tamanhoBlocoSaida);

        // Atualiza o contador de registros lidos
        registrosNaMemoriaInterna--;

        // TODO: Poderia melhorar aqui para que ao sobrar apenas uma fita ativa,
        // le todos os registros dela de uma vez (respeitando o limite de 20
        // registros na memoria interna) e escrevendo tudo de uma vez na fita de
        // saida ==> Diminuiria o numero de escritas no disco ==> Mas vou deixar
        // assim por enquanto, se der tempo eu volto aqui para melhorar

        // Le o proximo registro da fita de entrada que teve o registro lido
        if (tentaLerRegistro(memoriaInterna, entrada[memoriaInterna[0].fita],
                             blocoAtual, tamanhoBlocoEntrada,
                             &conteudoEntrada[memoriaInterna[0].fita],
                             metrica)) {
          registrosNaMemoriaInterna++;
        } else {
          // Move o vetor para esquerda
          for (int j = 0; j < registrosNaMemoriaInterna; j++) {
            memoriaInterna[j] = memoriaInterna[j + 1];
          }
        }
      }
      blocoAtual++;
      saidaAtual++;
    }
    /* REINICIA AS VARIAVEIS AUXILIARES PARA A PROXIMA INTERCALACAO */
    // Reinicia o conteudo das fitas de entrada
    for (int i = 0; i < quantidadeFitas; i++) {
      conteudoEntrada[i].blocos = 0;
      conteudoEntrada[i].registros = 0;
    }

    // Reinicia os arquivos de entrada e saida
    for (int i = 0; i < quantidadeFitas; i++) {
      fseek(entrada[i], 0, SEEK_SET);
      fseek(saida[i], 0, SEEK_SET);
    }

    // Reinicia o contador de registros na memoria interna
    registrosNaMemoriaInterna = 0;

    // Troca as fitas de entrada e saida
    FILE **temp = entrada;
    entrada = saida;
    saida = temp;

    // Troca os conteudos das fitas de entrada e saida
    ConteudoFita *tempConteudo = conteudoEntrada;
    conteudoEntrada = conteudoSaida;
    conteudoSaida = tempConteudo;

    // Atualiza o tamanho do bloco de entrada e saida
    tamanhoBlocoEntrada = tamanhoBlocoSaida;
    tamanhoBlocoSaida *= quantidadeFitas;

    // Reinicia o contador de fitas de saida
    saidaAtual = 0;

    // Reinicia o bloco atual
    blocoAtual = 1;

    // Alterna entre as fitas de entrada e saida
    alternancia = !alternancia;
  }
  if (alternancia) {
    // se a ultima intercalacao foi de saida para entrada
    // entao o arquivo ordenado esta na primeira fita de saida
    return 20;
  }
  // se a ultima intercalacao foi de entrada para saida
  // entao o arquivo ordenado esta na primeira fita de entrada
  return 0;
}

int intercalacaoInterna(FILE *arquivoBinario, Entrada entrada,
                        Metrica *metrica) {
  metrica->inicio = clock();

  // Constantes
  const int tamanhoMemoriaInterna = 20;
  const int quantidadeFitas = 20;

  // Variaveis auxiliares
  ItemFita memoriaInterna[tamanhoMemoriaInterna];
  FILE *fitasEntrada[quantidadeFitas];
  FILE *fitasSaida[quantidadeFitas];

  // Variaveis auxiliares
  ConteudoFita conteudoFitasEntrada[quantidadeFitas];
  ConteudoFita conteudoFitasSaida[quantidadeFitas];

  // Inicializa variaveis auxiliares
  for (int i = 0; i < quantidadeFitas; i++) {
    conteudoFitasEntrada[i].blocos = 0;
    conteudoFitasEntrada[i].registros = 0;

    conteudoFitasSaida[i].blocos = 0;
    conteudoFitasSaida[i].registros = 0;
  }

  // Cria a pasta fitas
  struct stat st = {0};
  if (stat("fitas", &st) == -1) {
    mkdir("fitas", 0700);
  }

  // Abre as fitas de entrada e saida
  abrirFitas(fitasEntrada, fitasSaida, quantidadeFitas);

  // Cria os blocos ordenados nas fitas de entrada
  criacaoDosBlocos(entrada, quantidadeFitas, tamanhoMemoriaInterna,
                   memoriaInterna, arquivoBinario, fitasEntrada,
                   conteudoFitasEntrada, metrica);

  // se apenas uma fita de entrada foi utilizada, o arquivo ja esta ordenado
  if (conteudoFitasEntrada[1].blocos == 0) {
    return 0;
  }

  // Volta para o inicio do arquivo binario de cada fita de entrada
  for (int i = 0; i < quantidadeFitas; i++) {
    fseek(fitasEntrada[i], 0, SEEK_SET);
  }

  int fitaOrdenada;
  fitaOrdenada = intercalacaoDosBlocos(
      quantidadeFitas, memoriaInterna, fitasEntrada, fitasSaida,
      conteudoFitasEntrada, conteudoFitasSaida, metrica);

  metrica->fim = clock();
  metrica->tempo = (double)(metrica->fim - metrica->inicio) / CLOCKS_PER_SEC;

  // Fecha as fitas de entrada e saida
  for (int i = 0; i < quantidadeFitas; i++) {
    fclose(fitasEntrada[i]);
    fclose(fitasSaida[i]);
  }

  return fitaOrdenada;
}
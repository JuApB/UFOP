#include "intercalacaoInterna.h"
#include "quicksortExterno.h"
#include "intercalacao.h"
#include "util.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  Entrada entrada;
  FILE *arquivoBinario = NULL;
  FILE *arquivoBinarioOrdenado = NULL;

  // Inicializa a metrica
  Metrica metrica;
  metrica.comparacoes = 0;
  metrica.escritas = 0;
  metrica.leituras = 0;

  // Processa a entrada do terminal
  if (!processarEntrada(&entrada, argc, argv)) {
    printf("./ordena <metodo> <quantidade> <situacao> [-p | -P]\n");
    return 0;
  }

  // Tenta abrir o arquivo binario ou converte o arquivo de texto para binário
  processarArquivo(entrada.situacao);

  arquivoBinario = abrirArquivoBinario(entrada.situacao);

  // Se a entrada tem a flag opcional, imprime o arquivo texto
  if (entrada.opcional) {
    printf("Arquivo binário ANTES da ordenação:\n");
    imprimirArquivoBinario(arquivoBinario, entrada.registros);
  }

  // Retorna o ponteiro do arquivo para o inicio depois da impressao
  fseek(arquivoBinario, 0, SEEK_SET);

  /*VARIAVEIS DE METRICA METODO 2*/
  int numeroDeLeituras = 0, numeroDeEscritas = 0, numeroDeComparacoesEntreValores = 0;
  clock_t tempoInicialDeExecucao = clock(), tempoTotalDeExecucao;

  /* VARIAVEIS AUXILIARES DO METODO 1 */
  char novoNomeArquivo[50];
  char antigoNomeArquivo[50];
  char comando[50];
  int fitaOrdenada = 0;

  // Chama a função de ordenação
  // As funcoes de ordenacao devem ordenar o arquivo binario que esta na
  // variavel 'arquivoBinario'
  switch (entrada.metodo) {
  case 1:
    // Intercalacao com metodo de ordenacao visto em Estrutura de Dados 1
    fitaOrdenada = intercalacaoInterna(arquivoBinario, entrada, &metrica);

    // Imprime as metricas
    printf("\n");
    printf("\033[1;32mMetricas - Intercalação de ordenação interna\033[0m\n");
    imprimirMetricas(metrica);
    printf("\n");

    // Move a fita que esta ordenada para a pasta arquivosOrdenados
    sprintf(comando, "mv fitas/fita%d.bin ../../arquivosOrdenados",
            fitaOrdenada);
    system(comando);

    // E renomeia para o nome do arquivo original + o metodo de ordenacao + a
    // quantidade de registros
    sprintf(novoNomeArquivo, "../../arquivosOrdenados/%s-%d-%d.bin",
            nomeArquivoSituacao(entrada.situacao), entrada.metodo,
            entrada.registros);
    sprintf(antigoNomeArquivo, "../../arquivosOrdenados/fita%d.bin",
            fitaOrdenada);
    rename(antigoNomeArquivo, novoNomeArquivo);

    // Exclui todas as fitas
    system("rm fitas/fita*");
    break;
  case 2:
    intercalacao(entrada, arquivoBinario, &numeroDeLeituras, &numeroDeEscritas, &numeroDeComparacoesEntreValores);
    break;
  case 3:
    CopiaAlunosParaOrdenar(entrada, arquivoBinario);

    if (quickSortExterno(entrada.registros, &metrica)) {
      // binParaTxt("Para_Ordenar.bin", "Ordenado.txt", entrada.registros);
    } else {
      printf("Algo deu errado!\n");
    }

    tempoTotalDeExecucao = clock() - tempoInicialDeExecucao;

    // Imprime as metricas
    printf("\n");
    printf("\033[1;32mMetricas - QuickSort Externo\033[0m\n");
    imprimirMetricas(metrica);
    printf("\n");

    // Move o arquivo que esta ordenado para a pasta arquivosOrdenados
    sprintf(comando, "mv Para_Ordenar.bin ../../arquivosOrdenados");
    system(comando);

    // E renomeia para o nome do arquivo original + o metodo de ordenacao + a
    // quantidade de registros
    sprintf(novoNomeArquivo, "../../arquivosOrdenados/%s-%d-%d.bin",
            nomeArquivoSituacao(entrada.situacao), entrada.metodo,
            entrada.registros);
    sprintf(antigoNomeArquivo, "../../arquivosOrdenados/Para_Ordenar.bin");
    rename(antigoNomeArquivo, novoNomeArquivo);
    
    break;
  }

  // Se a entrada tem a flag opcional, imprime o arquivo binario ordenado
  if (entrada.opcional) {
    char nomeArquivoOrdenado[50];

    sprintf(nomeArquivoOrdenado, "../../arquivosOrdenados/%s-%d-%d.bin",
            nomeArquivoSituacao(entrada.situacao), entrada.metodo,
            entrada.registros);

    arquivoBinarioOrdenado = fopen(nomeArquivoOrdenado, "rb");

    printf("Arquivo binário DEPOIS da ordenação:\n");

    imprimirArquivoBinario(arquivoBinarioOrdenado, entrada.registros);

    fclose(arquivoBinarioOrdenado);
  }

    printf("\n\t> Numero total de leituras da memoria externa para a interna: %d vezes!\n", numeroDeLeituras);
    printf("\n\t> Numero total de escritas da memoria interna para a externa: %d vezes!\n", numeroDeEscritas);
    printf("\n\t> Numero total de comparacoes entre os valores: %d vezes!\n", numeroDeComparacoesEntreValores);
    printf("\n\t> Tempo de execucao: %.4lf segundos!\n\n", tempoTotalDeExecucao / 1000.0);

  // Fecha os arquivos
  fecharArquivoBinario(arquivoBinario);

  return 0;
}

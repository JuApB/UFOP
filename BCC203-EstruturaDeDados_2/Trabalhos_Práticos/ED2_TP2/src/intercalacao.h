#ifndef INTERCALACOES_H
#define INTERCALACOES_H

#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "lista.h"

void swapregistro(Registro *v, int a, int b){
    Registro aux = v[a];
    v[a] = v[b];
    v[b] = aux;
}

void swapInt(int v [], int a, int b){
    int aux = v[a];
    v[a] = v[b];
    v[b] = aux;
}

short ehMenor(Registro *registros, int fitaDoRegistro [], short ativas [], int a, int b, int* numeroDeComparacoes){
    if (ativas[fitaDoRegistro[a] % F] == -1) return 1;
    if (ativas[fitaDoRegistro[b] % F] == -1) return 0;
    (*numeroDeComparacoes)++;
    return (registros[b].nota < registros[a].nota);
}

void heapify(Registro *registros, short ativas[], int fitaDoRegistro[], int quantidade, int* numeroDeComparacoes, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < quantidade && ehMenor(registros, fitaDoRegistro, ativas, left, largest, numeroDeComparacoes)) largest = left;
    if (right < quantidade && ehMenor(registros, fitaDoRegistro, ativas, right, largest, numeroDeComparacoes)) largest = right;
    if (largest != i){
        swapregistro(registros, i, largest);
        swapInt(fitaDoRegistro, i, largest);
        heapify(registros, ativas, fitaDoRegistro, quantidade, numeroDeComparacoes, largest);
    }
}

void heapSort(Registro *registros, short ativas[], int fitaDoRegistro[], int quantidade, int* numeroDeComparacoes){
    for (int i = quantidade / 2 - 1; i >= 0; i--) heapify(registros, ativas, fitaDoRegistro, quantidade, numeroDeComparacoes, i);
    for (int i = quantidade - 1; i >= 0; i--){
        swapregistro(registros, 0, i);
        swapInt(fitaDoRegistro, 0, i);
        heapify(registros, ativas, fitaDoRegistro, i, numeroDeComparacoes, 0);
    }
}

// Procura por uma unica fita que tenha registros
// Condição de parada
// Retorna -1 se mais de uma ou nenhuma fita esteja preenchida.
int CondicaodaFita(int numeroDeRegistrosNaFita [], int quantidade, int inicio){
    int preenchida = -1;
    for (int i = 0; i < quantidade; i++){
        if (numeroDeRegistrosNaFita[inicio + i] > 0){
            if (preenchida == -1) preenchida = i;
            else return -1;
        }
    }
    if (preenchida == -1) return preenchida;
    else return inicio + preenchida;
}

// Função para verificar se todas as fitas foram percorridas
short TodasforamPercorridas(FILE** fitas, int numeroDeRegistrosNaFita [], int quantidade, int inicio){
    for (int i = 0; i < quantidade; i++){
        if (ftell(fitas[inicio + i]) / sizeof(Registro) < numeroDeRegistrosNaFita[inicio + i])
            return 0;
    }
    return 1;
}

// Função para verificar se todos os blocos estão esgotados, caso esteja é retornado 1
short todosBlocosEsgotados(short ativas [], int quantidade){
    for (int i = 0; i < quantidade; i++){
        if (ativas[i] != -1) return 0;
    }
    return 1;
}

// Método responsável por intercalar os bloco de cada fita de entrada e saida até que reste só uma fita de saída preenchida
void intercalarBlocos(Registro *memoria, Entrada entrada, FILE* arqTemporario, FILE** fitas, int numeroDeRegistrosNaFita[FF], Lista blocos[FF], int* numeroDeLeituras, int* numeroDeEscritas, int* numeroDeComparacoes){
    // Vetor de inteiros que referencia para cada registro da memória de qual fita ele veio
    int fitaDoRegistro[F];
    // Vetor responsável por armazenar a situação do bloco que está sendo lido de cada fita de entrada
    short ativas[F];
    // Se for igual a '1', as primeiras F fitas são as de entrada e as outras de saida
    int Fitas_Jump = 1;
    // Variável responsável por armazenar o indice da fita de saida atual
    int fita;
    // Variável utilizada para armazenar o indice da unica fita preenchida, caso tenha mais de uma fita preenchida é retornado -1
    int indiceDaUnicaFitaPreenchida = CondicaodaFita(numeroDeRegistrosNaFita, F, F * Fitas_Jump);
    
    while (indiceDaUnicaFitaPreenchida == -1){
        // Define a fita alvo como a primeira fita de saída de acordo com a situacao de distribuição
        fita = F * Fitas_Jump;
        int bloco = 0;
        // Executa o while enquanto todas as fitas de entrada não forem percorridas
        while (!TodasforamPercorridas(fitas, numeroDeRegistrosNaFita, F, F * (!Fitas_Jump))){
            // adiciona um novo bloco na fita que foi destinada
            adicionarItemNoInicioDaLista(&blocos[fita], ftell(fitas[fita]) / sizeof(Registro));
            // Vetor responsável por armazenar o indice onde termina o bloco de cada fita
            int indiceOndeTerminaOsBlocos[F];
            for (int i = 0; i < F; i++){
                if (tamanhoDaLista(&blocos[(F * !Fitas_Jump) + i]) > bloco + 1)
                    indiceOndeTerminaOsBlocos[i] = posicaoNaLista(&blocos[(F * !Fitas_Jump) + i], bloco + 1);
                else indiceOndeTerminaOsBlocos[i] = numeroDeRegistrosNaFita[(F * !Fitas_Jump) + i];
            }
            // Pega o primeiro elemento de cada fita de entrada
            for (int i = 0; i < F; i++){
                // Verificação para saber se tem registro no bloco
                if (ftell(fitas[(F * !Fitas_Jump) + i]) / sizeof(Registro) < indiceOndeTerminaOsBlocos[i]){
                    // É armazenado na memória interna o primeiro registro
                    fread(&memoria[i], sizeof(Registro), 1, fitas[(F * !Fitas_Jump) + i]);
                    (*numeroDeLeituras)++;
                    // Verificação para saber esse registro lido foi o ultimo do bloco
                    if (ftell(fitas[(F * !Fitas_Jump) + i]) / sizeof(Registro) >= indiceOndeTerminaOsBlocos[i])
                        ativas[i] = 0; // foi o ultimo elemento?
                    else ativas[i] = 1;
                } else ativas[i] = -1; // elemento inexistente
                fitaDoRegistro[i] = i + (!Fitas_Jump * F);

            }
            // Executa o laço enquanto um bloco não estiver esgotado
            while (!todosBlocosEsgotados(ativas, F)){
                // Realiza a ordenação da memória interna
                heapSort(memoria, ativas, fitaDoRegistro, F, numeroDeComparacoes);
                // Pega o menor registro e armazena na memória interna
                fwrite(&memoria[0], sizeof(Registro), 1, fitas[fita]);
                (*numeroDeEscritas)++;
                // Atualiza a variavel de tamanho da fita
                numeroDeRegistrosNaFita[fita]++;
                // Verifica se a fita do menor registro está ativa
                if (ativas[fitaDoRegistro[0] % F]){
                    // Caso esteja ativa, o próximo registro é armazenado na memória interna
                    fread(&memoria[0], sizeof(Registro), 1, fitas[fitaDoRegistro[0]]);
                    (*numeroDeLeituras)++;
                    // Caso tenha sido o utlimo registro a ser lido, a fita se torna inativa
                    if (ftell(fitas[fitaDoRegistro[0]]) / sizeof(Registro) == indiceOndeTerminaOsBlocos[fitaDoRegistro[0] % F])
                        ativas[fitaDoRegistro[0] % F] = 0; // a fita se torna inativa
                } else ativas[fitaDoRegistro[0] % F] = -1; // Caso não esteja ativa, significa que o bloco esgotou
            }
            // Define a próxima fita alvo
            fita = (fita % F + 1) % F + F * Fitas_Jump;
            bloco++;
        }
        for (int i = 0; i < F; i++){
            // Faz o rewind nas fitas de entrada e saida para executar a próxima intercalação
            rewind(fitas[F * Fitas_Jump + i]);
            rewind(fitas[F * (!Fitas_Jump) + i]);
            // Define o número de registros nas fitas de entrada como 0
            numeroDeRegistrosNaFita[F * (!Fitas_Jump) + i] = 0;
            // Reseta os blocos das fitas de entradas
            limparLista(&blocos[F * (!Fitas_Jump) + i]);
        }
        // Agora a distruibuição das fitas de entrada são trocadas com as fitas de saídas
        Fitas_Jump = !Fitas_Jump;
        indiceDaUnicaFitaPreenchida = CondicaodaFita(numeroDeRegistrosNaFita, F, F * (!Fitas_Jump));
    }
    rewind(fitas[indiceDaUnicaFitaPreenchida]);
    rewind(arqTemporario);
    // Método responsável por armazenar todos os registros da ultima fita preenchida no arquivo temporário
    Registro registro;
    for (int i = 0; i < entrada.registros; i++){
        // joga todos os registros da fita f na fita principal
        fread(&registro, sizeof(Registro), 1, fitas[indiceDaUnicaFitaPreenchida]);
        (*numeroDeLeituras)++;
        fwrite(&registro, sizeof(Registro), 1, arqTemporario);
        (*numeroDeEscritas)++;
    }
}

short ehMenorMarcado(Registro *registros, int registrosMarcados [], int a, int b, int* numeroDeComparacoes){
    if (registrosMarcados[a % F] != 0) return 1;
    if (registrosMarcados[b % F] != 0) return 0;
                

    (*numeroDeComparacoes)++;
    return (registros[b].nota < registros[a].nota);
}

void heapifyMarcados(Registro *registros, int registrosMarcados[], int quantidade, int* numeroDeComparacoes, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < quantidade && ehMenorMarcado(registros, registrosMarcados, left, largest, numeroDeComparacoes)) largest = left;
    if (right < quantidade && ehMenorMarcado(registros, registrosMarcados, right, largest, numeroDeComparacoes)) largest = right;
    if (largest != i){
        swapregistro(registros, i, largest);
        swapInt(registrosMarcados, i, largest);
        heapifyMarcados(registros, registrosMarcados, quantidade, numeroDeComparacoes, largest);
    }
}

void heapSortMarcados(Registro *registros, int registrosMarcados[], int quantidade, int* numeroDeComparacoes){
    for (int i = quantidade / 2 - 1; i >= 0; i--) heapifyMarcados(registros, registrosMarcados, quantidade, numeroDeComparacoes, i);
    for (int i = quantidade - 1; i >= 0; i--){
        swapregistro(registros, 0, i);
        swapInt(registrosMarcados, 0, i);
        heapifyMarcados(registros, registrosMarcados, i, numeroDeComparacoes, 0);
    }
}

// Função para verificar se todos os registros da memória estao marcados, caso estejam é retornado o valor 1
int verificarTodosMarcados(int marcados []){
    for (int i = 0; i < F; i++){
        if (marcados[i] == 0) return 0;
    }
    return 1;
}

// Retorna 1 se tem elementos na memoria (se tem algum elemento que nao está marcado com '-1')
int temElementoNaMemoria(int marcados []){
    for (int i = 0; i < F; i++){
        if (marcados[i] != -1) return 1;
    }
    return 0;
}

void gerarOrdenarBlocosSelecaoPorSubstituicao(Registro *memoria, Entrada entrada, FILE* arqTemporario, FILE** fitas, int numeroDeRegistrosNaFita [], Lista blocos [], int* numeroDeLeituras, int* numeroDeEscritas, int* numeroDeComparacoes){
    // Vetor para representar os registros marcados
    int registrosMarcados[F];
    for (int i = 0; i < F; i++) registrosMarcados[i] = 0;
    // pega a primeira fita de entrada como fita alvo
    int fitaSelecionada = 0;
    // Variável responsável por guardar o proximo registro lido do arqTemporario antes que ele seja jogado na memória
    Registro proximoRegistro;
    // Pega os 'F' primeiros registros do arquivo e joga na memoria interna
    fread(memoria, sizeof(Registro), F, arqTemporario);
    (*numeroDeLeituras)++;
    // Enquanto nao percorrer todo o arquivo ou houver elementos na memoria
    while ((ftell(arqTemporario) / sizeof(Registro) < entrada.registros) || temElementoNaMemoria(registrosMarcados)){
        for (int i = 0; i < F; i++)
            if (registrosMarcados[i] == 1) registrosMarcados[i] = 0; // Desmarca todos que estavam marcados na memoria
        // adiciona um novo bloco para a fita alvo
        adicionarItemNoInicioDaLista(&blocos[fitaSelecionada], numeroDeRegistrosNaFita[fitaSelecionada]);
        // Enquanto houver um elemento na memoria não-marcado
        while (!verificarTodosMarcados(registrosMarcados)){
            // Faz a ordenação da memória em busca do menor registro
            heapSortMarcados(memoria, registrosMarcados, F, numeroDeComparacoes);
            // Escreve o menor registro da memoria da fita alvo
            fwrite(&memoria[0], sizeof(Registro), 1, fitas[fitaSelecionada]);
            (*numeroDeEscritas)++;
            numeroDeRegistrosNaFita[fitaSelecionada]++;
            // Se ainda tiver elemento no arquivo...
            if (ftell(arqTemporario) / sizeof(Registro) < entrada.registros){
                fread(&proximoRegistro, sizeof(Registro), 1, arqTemporario);
                (*numeroDeLeituras)++;
                // Se o valor dele for maior que o que acabou de sair, marque este registro
                if (proximoRegistro.nota > memoria[0].nota) registrosMarcados[0] = 1;
                (*numeroDeComparacoes)++;
                memoria[0] = proximoRegistro;
            } else registrosMarcados[0] = -1; // Marca o primeiro elemento (nao tem elemento na memoria)
        }
        // Percorre somente entre as fitas de entrada (as F primeiras do vetor de fitas)
        fitaSelecionada = (fitaSelecionada + 1) % F;
    }
    for (int i = 0; i < FF; i++) rewind(fitas[i]);
    rewind(arqTemporario);
}

void imprimirFita(FILE* fita) {
    rewind(fita);
    Registro reg;
    while (fread(&reg, sizeof(Registro), 1, fita) == 1) {
        printf("Nota: %f\n", reg.nota);
    }
}

int intercalacao(Entrada entrada, FILE* arqTemporario, int* numeroDeLeituras, int* numeroDeEscritas, int* numeroDeComparacoes){
    // Criando um vetor para armazenar os ponteiros das fitas
    FILE* fitas[FF];
    for (int i = 0; i < FF; i++){
        char nomeFita[50];
        // Armazena no buffer do nome a concatenação do F com o inteiro i
        sprintf(nomeFita, "fitas/fita%d.bin", i);
        fitas[i] = fopen(nomeFita, "wb+");
    }

    // Coloca os ponteiros no inicio do arquivo
    for (int i = 0; i < FF; i++) rewind(fitas[i]);
    rewind(arqTemporario);
    // Vetor responsavel por amazernar em cada posicao o numero de registros dentro de cada fita respectivamente, inicializando com 0
    int numeroDeRegistrosNaFita[FF];
    for (int i = 0; i < FF; i++) numeroDeRegistrosNaFita[i] = 0;
    // Vetor de uma LinkedList para armazenar os blocos de uma fita, onde cada posicao 'i' desse vetor corresponde à fita 'i'
    Lista blocos[FF];
    for (int i = 0; i < FF; i++) blocos[i].primeiroItem = NULL;
    //Vetor de Registros
    Registro memoria[F];

    gerarOrdenarBlocosSelecaoPorSubstituicao(memoria, entrada, arqTemporario, fitas, numeroDeRegistrosNaFita, blocos, numeroDeLeituras, numeroDeEscritas, numeroDeComparacoes);

    //todo aonde deixo isso
    // => Leitura do primeiro registro de cada fita
    // => Retirada do registro contendo a menor chave e armazenando esta em uma fita de saida
    // => Leitura de um novo registro da fita onde o registro foi retirado da Memoria principal
    // => Ao ler todos os registros de um dos blocos, a fita correspondente fica inativa
    // => Esta fita que ficou inativa é reativada quando o n-esimo registros das outras fitas forem lidos
    rewind(arqTemporario);
    // Fase de intercalação dos blocos com as fitas
    intercalarBlocos(memoria, entrada, arqTemporario, fitas, numeroDeRegistrosNaFita, blocos, numeroDeLeituras, numeroDeEscritas, numeroDeComparacoes);
    rewind(arqTemporario);

    for (int i = 0; i < FF; i++) fclose(fitas[i]);
    for (int i = 0; i < FF; i++){
        char nomeFita[50];
        // Armazena no buffer do nome a concatenação do F com o inteiro i
        sprintf(nomeFita, "fitas/fita%d.bin", i);
        remove(nomeFita);
    }

    return 0;
}

// Função para verificar se o arquivo está ordenado por nota
short verificarOrdenacao(FILE *arq) {
    Registro registroAtual, registroAnterior;
    short primeiroRegistro = 1;

    // Reposiciona o ponteiro do arquivo no início
    rewind(arq);

    // Lê o primeiro registro
    if (fread(&registroAnterior, sizeof(Registro), 1, arq) != 1) {
        // Arquivo vazio ou erro na leitura
        return 0;
    }

    // Lê os registros restantes e verifica a ordem
    while (fread(&registroAtual, sizeof(Registro), 1, arq) == 1) {
        if (primeiroRegistro) {
            // O primeiro registro é sempre considerado válido
            primeiroRegistro = 0;
        } else if (registroAtual.nota < registroAnterior.nota) {
            // Se o registro atual tiver uma nota menor que o anterior, a ordenação está incorreta
            return 0;
        }

        // Atualiza o registro anterior
        registroAnterior = registroAtual;
    }

    // Se passou por todos os registros e a ordem estava correta, retorna 1
    return 1;
}

#endif


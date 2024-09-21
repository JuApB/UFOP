/*
  Nome: Juliana Aparecida Borges
  Matrícula: 21.2.4156
  Turma: 31
    */
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

// Declaracao das variaveis: Matriz do tabuleiro correto,
// Matriz do tabuleiro recem jogado, Movimentos do jogo.
int tabCerto[3][3] = {{1, 2, 3},{ 4, 5, 6},{7, 8, 0}};
int tabRecente[3][3] = {{1, 2, 3},{ 4, 5, 6},{7, 8, 0}};
int mov = 0;

// Funcao do tabuleiro, antes de embaralhar
void impressaoTab(int mat[3][3]) {
  for(int i = 0; i < 3; i ++) {
   for(int j = 0; j < 3; j ++) {
    printf("%d ", mat[i][j]);
    }
  printf("\n");
  }
  printf("\n");
}

// Funcao para embaralhar as peças do tabuleiro
int embaralhar(int mat[3][3], int n) {
  for(int i = 0; i < 3; i ++) {
   for(int j = 0; j < 3; j ++) {
    if(mat[i][j] == 0) { 
    //Mudando a posição da peça que esta abaixo do zero;
    if(i+1 < 3 && mat[i+1][j] == n) {
      mat[i][j] = mat[i+1][j];
      mat[i+1][j] = 0;
      return 1;
       }
    //Mudando a posição da peça que esta acima do zero;
    if( i-1 >= 0 && mat[i-1][j] == n) {
      mat[i][j] = mat[i-1][j];
      mat[i-1][j] = 0;
      return 1;
       }
    //Mudando a posição da peça que esta a direita do zero;
    if(j+1 < 3 && mat[i][j+1] == n) {
      mat[i][j] = mat[i][j+1];
      mat[i][j+1] = 0;
      return 1;
       }
    //Mudando a posição da peça que esta a esquerda do zero;
    if(j-1 >= 0 &&  mat[i][j-1] == n) {
      mat[i][j] = mat[i][j-1];
      mat[i][j-1] = 0;
      return 1;
       }
      }
    }
   }
  return 0;
 }

// Funcao para verificar se o usuario ganhou o jogo
int ganhou(int tab_Recente[3][3]) {
  int venceu = 1;
  for(int i = 0; i < 3; i ++) {
   for(int j = 0; j < 3; j ++) {
    if(tab_Recente[i][j] != tabCerto[i][j]) 
      venceu = 0;
      }
    }
  return venceu;
}

// Funcao para embaralhar de acordo com o nivel
// de dificuldade escolhida pelo jogador
void jogo(int dificuldade, int novoJogo) {
  int count = 0;
  if(novoJogo) {
    switch (dificuldade) {
    // Embaralhando no nivel de dificuldade Facil
     case 1:
     while(count < 20) {
      if(embaralhar(tabRecente, 1 + (rand() % 8))) count++;
      }
      break;
    // Embaralhando no nivel de dificuldade Medio
    case 2:
    while(count < 40) {
      if(embaralhar(tabRecente, 1 + (rand() % 8))) count++;
     }
     break;
    // Embaralhando no nivel de dificuldade Dificil
    case 3:
    while(count < 80) {
      if(embaralhar(tabRecente, 1 + (rand() % 8))) count++;
       }
     break;
    default:
     break;
    }
  }

printf("Tabuleiro embaralhado. Vamos comecar o jogo!\n");
  impressaoTab(tabRecente);

  // Declarando um char para comando de sair e salvar, e um int para 
  // igualar sair com 0
  char instrucao[100];
  int sair = 0;
  while(strcmp("sair", instrucao) && !sair) {
    printf("Digite um comando ou numero da peca que quer movimentar\n");
    scanf("%s", instrucao);

    // Comparando instrucao com sair e comparando instrucao com salvar
    if ((strcmp(instrucao, "sair") && strcmp(instrucao, "salvar"))) {
      // Convertendo string para inteiro
      int temp = atoi(instrucao);
     if(embaralhar(tabRecente, atoi(instrucao))) mov++;
      impressaoTab(tabRecente);

    // Imprimindo mensagem de parabens para o jogador, 
    //quando ele ganhar o jogo
      if(ganhou(tabRecente)) {
        printf("Parabens! Voce completou o quebra-cabecas com %d movimentos!\n\n", mov);
        sair = 1;
        }
      }
    else if (!strcmp(instrucao, "salvar")) {
      //Abrindo arquivo para salvar o jogo
      char nomeArq[100];
      scanf("%s", nomeArq);
     
      FILE *arq;
      arq =  fopen(nomeArq, "w");
      
      fprintf(arq, "%d\n", 3);
      for(int i = 0; i < 3; i++) {
       for(int j = 0; j < 3; j++) {
        fprintf(arq, "%d ", tabRecente[i][j]);
        }
        fprintf(arq, "\n");
       }
      fprintf(arq, "%d", mov);
      fclose(arq);

      sair = 1;
     }
   }
 }

void salvo() {
  //Abrindo arquivo salvo para continuar o jogo
    char nomeArq[100];
    scanf("%s", nomeArq);
    
    FILE *arq;
    arq =  fopen(nomeArq, "r");

    int tamMatriz;
    fscanf(arq, "%d", &tamMatriz);

    for(int i = 0; i < 3; i++) {
     for (int j = 0; j < 3; j++) {
      fscanf(arq, "%d", &tabRecente[i][j]);
       }
     }
    fscanf(arq, "%d", &mov);
    fclose(arq);
}

int main() {
  int opcoes, dificuldade;
  int saida = 0;

  //Impressão do MENU
  while (!saida) {
  printf("\n  Bem Vindo ao Quebra Cabeca! :)\n");
  printf("\n         MENU    ");
  printf("\n0. Sair \n1. Novo Jogo \n2. Continuar o Jogo Atual \n3. Continuar Jogo Salvo \n4. Instruçoes do Jogo");
  printf("\nEscolha uma das opcoes acima (digite “sair” em qualquer lugar para sair do jogo):\n");
  scanf("%d", &opcoes);

  //Implementando cada opcao do menu
 switch(opcoes){
   case 0:
    printf ("Saindo... \nSaiu! ");
    saida = 1;
    break;
   case 1:
    printf("Qual nivel de dificuldade?\n");
    printf("1 - Facil\n");
    printf("2 - Medio\n");
    printf("3 - Dificil\n");
    scanf("%d", &dificuldade);
    jogo(dificuldade, 1);
    break;
   case 2:
    printf ("Continuando Jogo Atual \n");
    jogo(-1, 0);
    break;
   case 3:
    printf("Para continuar o Jogo Salvo, digite o nome do arquivo:\n");
    salvo();
    jogo(-1, 0);
    break;
   case 4:
    printf("\n     Instrucoes do Jogo: \n");
    printf(" Os numeros podem ser movidos para o zero por deslocamento da peca selecionada. \nSelecione um numero por vez. Os movimentos permitidos sao os de deslocar as \npecas para o local do zero. Faca isso ate os numeros ficarem em ordem \ncrescente, assim ganhando o jogo.\n\n");
    break;
   default:
    printf("Opcao Invalida.\n");
    break;
   }
  }
  return 0;
}
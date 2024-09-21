#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <time.h>

int tabCorreto[3][3] = {{1, 2, 3},{ 4, 5, 6},{7, 8, 0}};
int tabAtual[3][3] = {{1, 2, 3},{ 4, 5, 6},{7, 8, 0}};
int mov = 0;

void impressaoTab(int mat[3][3]) {
  for(int i = 0; i < 3; i ++) {
   for(int j = 0; j < 3; j ++) {
    printf("%d ", mat[i][j]);
    }
  printf("\n");
  }
  printf("\n");
}

int embaralhar(int mat[3][3], int n) {
  for(int i = 0; i < 3; i ++) {
   for(int j = 0; j < 3; j ++) {
    if(mat[i][j] == 0) { 
    // Muda a posição da peça abaixo do zero;
    if(i+1 < 3 && mat[i+1][j] == n) {
      mat[i][j] = mat[i+1][j];
      mat[i+1][j] = 0;
      return 1;
       }
    // Muda a posição da peça acima do zero;
    if( i-1 >= 0 && mat[i-1][j] == n) {
      mat[i][j] = mat[i-1][j];
      mat[i-1][j] = 0;
      return 1;
       }
    // Muda a posição da peça a direita do zero;
    if(j+1 < 3 && mat[i][j+1] == n) {
      mat[i][j] = mat[i][j+1];
      mat[i][j+1] = 0;
      return 1;
       }
    // Muda a posição da peça a esquerda do zero;
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

int ganhou(int tab_Atual[3][3]) {
  int venceu = 1;
  for(int i = 0; i < 3; i ++) {
   for(int j = 0; j < 3; j ++) {
    if(tab_Atual[i][j] != tabCorreto[i][j]) 
      venceu = 0;
      }
    }
  return venceu;
}

void jogo(int dificuldade, int novoJogo) {
  int count = 0;
  if(novoJogo) {
    switch (dificuldade) {
     case 1:
     while(count < 20) {
      if(embaralhar(tabAtual, 1 + (rand() % 8))) count++;
      }
      break;
    case 2:
    while(count < 40) {
      if(embaralhar(tabAtual, 1 + (rand() % 8))) count++;
     }
     break;
    case 3:
    while(count < 80) {
      if(embaralhar(tabAtual, 1 + (rand() % 8))) count++;
       }
     break;
    default:
     break;
    }
  }

printf("Tabuleiro embaralhado. Vamos comecar o jogo!\n");
  impressaoTab(tabAtual);

  char comando[100];
  int sair = 0;
  while(strcmp("sair", comando) && !sair) {
    printf("Digite um comando ou numero da peca que quer movimentar\n");
    scanf("%s", comando);
    if ((strcmp(comando, "sair") && strcmp(comando, "salvar"))) {
      int temp = atoi(comando);
     if(embaralhar(tabAtual, atoi(comando))) mov++;
      impressaoTab(tabAtual);

      if(ganhou(tabAtual)) {
        printf("Parabens! Voce completou o quebra-cabecas com %d movimentos!\n\n", mov);
        sair = 1;
        }
      }
    else if (!strcmp(comando, "salvar")) {
      char nomeArq[100];
      scanf("%s", nomeArq);
     
      FILE *arq;
      arq =  fopen(nomeArq, "w");
      
      fprintf(arq, "%d\n", 3);
      for(int i = 0; i < 3; i++) {
       for(int j = 0; j < 3; j++) {
        fprintf(arq, "%d ", tabAtual[i][j]);
        }
        fprintf(arq, "\n");
       }
      fprintf(arq, "%d", mov);
      fclose(arq);

      sair = 1;
     }
   }
 }

void salve() {   
    char nomeArq[100];
    scanf("%s", nomeArq);
    
    FILE *arq;
    arq =  fopen(nomeArq, "r");

    int tamMatriz;
    fscanf(arq, "%d", &tamMatriz);

    for(int i = 0; i < 3; i++) {
     for (int j = 0; j < 3; j++) {
      fscanf(arq, "%d", &tabAtual[i][j]);
       }
     }
    fscanf(arq, "%d", &mov);
    fclose(arq);
}

int main() {
  int opçoes, dificuldade;
  int saida = 0;

  while (!saida) {
  printf("\nBem Vindo ao Quebra Cabeca!\n");
  printf("\n         MENU    ");
  printf("\n0 - Sair \n1 - Novo Jogo \n2 - Continuar o Jogo Atual \n3 - Continuar Jogo Salvo \n4 - Instruçoes do Jogo");
  printf("\nEscolha uma das opcoes acima: \n");
  scanf("%d", &opçoes);

  //Implementando menu
 switch(opçoes){
   case 0:
    printf ("Saindo! ");
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
    printf ("Continuando Jogo Atual ");
    jogo(-1, 0);
    break;
   case 3:
    printf("Para continuar o Jogo Salvo, digite o nome do arquivo:\n ");
    salve();
    jogo(-1, 0);
    break;
   case 4:
    printf("\n Instrucoes do Jogo \n");
    printf("Os numeros podem ser movidos para o zero por deslocamento da peca selecionada. \nSelecione um numero por vez. \nOs movimentos permitidos sao os de deslocar as pecas para o local do zero. \nFaca isso ate os numeros ficarem em ordem crescente \nassim ganhando o jogo.\n");
    break;
   default:
    printf("Opcao Invalida.\n");
    break;
   }
  }
  return 0;
}
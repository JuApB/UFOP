// Maria Clara Miranda de Sá 21.2.4187 turma 31

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int tabuleiro_correto[3][3] = {{1, 2, 3},{ 4, 5, 6},{7, 8, 0}};
int tabuleiro_atual[3][3] = {{1, 2, 3},{ 4, 5, 6},{7, 8, 0}};
int movimentos = 0;

void printBoard(int matriz[3][3])
{
  for(int i = 0; i < 3; i ++)
  {
  for(int j = 0; j < 3; j ++)
  {
    printf("%d ", matriz[i][j]);
  }
  printf("\n");
  }
  printf("\n");
}

int embaralhar(int matriz[3][3], int n)
{
  for(int i = 0; i < 3; i ++)
  {
  for(int j = 0; j < 3; j ++)
  {
  if(matriz[i][j] == 0) 
  { 

    // Muda com a posição do elemento abaixo do 0;
    if(i+1 < 3 && matriz[i+1][j] == n)
    {
      matriz[i][j] = matriz[i+1][j];
      matriz[i+1][j] = 0;
      return 1;
    }

    // Muda com a posição do elemento acima do 0;
    if( i-1 >= 0 && matriz[i-1][j] == n)
    {
      matriz[i][j] = matriz[i-1][j];
      matriz[i-1][j] = 0;
      return 1;
    }

    // Muda com a posição do elemento a direita do 0;
    if(j+1 < 3 && matriz[i][j+1] == n)
    {
      matriz[i][j] = matriz[i][j+1];
      matriz[i][j+1] = 0;
      return 1;
    }

    // Muda com a posição do elemento a esquerda do 0;
    if(j-1 >= 0 &&  matriz[i][j-1] == n)
    {
      matriz[i][j] = matriz[i][j-1];
      matriz[i][j-1] = 0;
      return 1;
    }
  }
  }
  }
  return 0;
}

int venceu(int tabuleiroAtual[3][3])
{
  int win = 1;
  for(int i = 0; i < 3; i ++)
  {
  for(int j = 0; j < 3; j ++)
  {
    if(tabuleiroAtual[i][j] != tabuleiro_correto[i][j]) win = 0;
  }
  }
  return win;
}

void game(int nivel, int novoJogo)
{
  int count = 0;
  if(novoJogo)
  {
    switch (nivel)
  {
  case 1:
    while(count < 20)
    {
      if(embaralhar(tabuleiro_atual, 1 + (rand() % 8))) count++;
    }
    break;
  case 2:
    while(count < 40)
    {
      if(embaralhar(tabuleiro_atual, 1 + (rand() % 8))) count++;
    }
    break;
  case 3:
    while(count < 80)
    {
      if(embaralhar(tabuleiro_atual, 1 + (rand() % 8))) count++;
    }
    break;
  
  default:
    break;
  }
  }

  printf("Tabuleiro embaralhado. Vamos comecar o jogo!\n");
  printBoard(tabuleiro_atual);

  char comando[100];
  int sair = 0;
  while(strcmp("sair", comando) && !sair)
  {
    printf("Digite um comando ou numero da peca que quer mover\n");
    scanf("%s", &comando);
    if ((strcmp(comando, "sair") && strcmp(comando, "salvar")))
    {
      int temp = atoi(comando);
     if(embaralhar(tabuleiro_atual, atoi(comando))) movimentos++;
      printBoard(tabuleiro_atual);

      if(venceu(tabuleiro_atual))
      {
        printf("Parabens! Voce completou com quebra-cabecas com %d movimentos!\n\n", movimentos);
        sair = 1;
      }
    }
    else if (!strcmp(comando, "salvar"))
    {
      char nomeArquivo[100];
      scanf("%s", &nomeArquivo);
     
      FILE *arq;
      arq =  fopen(nomeArquivo, "w");
      
      fprintf(arq, "%d\n", 3);
      for(int i = 0; i < 3; i++)
      {
      for(int j = 0; j < 3; j++)
      {
        fprintf(arq, "%d ", tabuleiro_atual[i][j]);
      }
        fprintf(arq, "\n");
      }
      fprintf(arq, "%d", movimentos);
      fclose(arq);

      sair = 1;
    }
  
  }
}

void getSave()
{   
    char nomeArquivo[100];
    scanf("%s", &nomeArquivo);
    
    FILE *arq;
    arq =  fopen(nomeArquivo, "r");

    int tamMatriz;
    fscanf(arq, "%d", &tamMatriz);

    for(int i = 0; i < 3; i++)
    {
    for (int j = 0; j < 3; j++)
    {
      fscanf(arq, "%d", &tabuleiro_atual[i][j]);
    }
    }
    fscanf(arq, "%d", &movimentos);
    fclose(arq);
}


int x = 0, y = 0, aux, vitoria;


// função principal
int main() {
 // declaração de variáveis  
  int opcao, nivel; 

 // entrada de dados
  
  int exit = 0;
  

  while (!exit)
  {
  printf("Bem vindo ao Quebra Cabeca! \nDigite uma opcao: \n");
  printf("0 - Sair do jogo \n");
  printf("1 - Comecar um novo jogo \n");
  printf("2 - Continuar o jogo atual \n");
  printf("3 - Continuar um jogo salvo \n");
  printf("4 - Instrucoes do jogo \n");
  printf("\n");
  printf("Escolha uma opcao!\n");
  scanf("%d", &opcao);
  switch(opcao) {
    case 0: 
      printf("Sair do jogo");
      exit = 1;
      break;
    case 1:
      printf("Qual nivel de dificuldade?\n ");
      printf("1 - Facil\n");
      printf("2 - Medio\n");
      printf("3 - Dificil\n");
      scanf("%d", &nivel);
      game(nivel, 1);
  
        break;
    case 2 :
      game(-1, 0);
      break;
    case 3 :
      printf("Digite o nome do arquivo:\n");
      getSave();
      game(-1, 0);
      break;
    case 4 :
      printf("Instrucoes do jogo \n");
      break;

    default:
      printf("Opcao invalida!");
    
  }
  }
}


  
  
  
#include <stdio.h>
#include <string.h>

//Struct
typedef struct {
    char nome[50];
    float nota;
    int freq; 
} Aluno;

int main() {
    //Declaracao das variaveis
    int n = 0;
    int entrar = 1;
    Aluno *x;
    //abrindo arquivo
    FILE *informacoes = fopen("dadosAlunos.txt", "w");

    //comando de repeticao
    while(n <= 30 && entrar == 1){
      printf("\nDigite 1 para entrar um aluno ou 0 para encerrar: ");
      scanf("%d", &entrar);

      if (entrar == 1)  {
        scanf("%s %f %d", x[n].nome, &x[n].nota, &x[n].freq);
         n++;
        }
    }

    fprintf(informacoes, "%d\n", n);
    for (int i = 0; i < n; i++)
        fprintf(informacoes, "\n%s %.1f %d\n", x[i].nome, x[i].nota, x[i].freq);

    fclose(informacoes); //fechando arquivo

    return 0;

}
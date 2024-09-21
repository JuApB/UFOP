#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "turma.h"
#include "aluno.h"

struct aluno {
  char nome[20];
  char curso[20];
  float nota;
};

struct turma {
    Aluno* alunos; // vetor de ponteiros de alunos
    int n; // inteiro com o tamanho da turma
};

// Manter como especificado
void lerInfos(int *qtd, char *option) {
    scanf("%s", option);
    scanf("%d", qtd);
}

// Manter como especificado
Turma* alocaTurma(int qtdAlunos) {
    *alocaAluno();
    Turma* pTurma = (Turma*) malloc(sizeof(Turma));
    pTurma->n = qtdAlunos;
    pTurma->alunos = (Aluno*) malloc(qtdAlunos * sizeof(Aluno));
    for(int i = 0; i < qtdAlunos; i++){
        pTurma->alunos[i] = *alocaAluno(); // Usar funcao de alocaAluno aqui
    }
    return pTurma;
}

// Manter como especificado
void desalocaTurma(Turma **pTurma) {
    desalocaAluno(alunos); // Usar funcao desalocaAluno aqui
    free(pTurma);
}

// Manter como especificado
void lerTurma(Turma *pTurma) {
    for(int i = 0; i < pTurma->n; i++){ // Ler informacoes dos alunos da turma
       scanf("%s %s %f", pTurma->alunos[i].nome, pTurma->alunos[i].curso, pTurma->alunos[i].nota);
    }

}

// Manter como especificado
float calcularMetrica(Turma *pTurma, char* curso, char option) {
    float soma = 0, media;
    for(int i = 0; i < pTurma->n; i++){
        if(strcmp(pTurma->alunos[i].curso, curso) == 0){
            soma += pTurma->alunos[i].nota;
        }
    }
    media = soma / pTurma->n;

    if(option == 'S'){
        return soma;
    }
    else if(option == 'M'){
        return media;
    }
}

// Manter como especificado
void printMetrica(char* curso, float metrica, char option) {
    printf("A %s no curso de %s eh %.1f\n", option == 'S' ? "soma" : "media", curso, metrica);
}

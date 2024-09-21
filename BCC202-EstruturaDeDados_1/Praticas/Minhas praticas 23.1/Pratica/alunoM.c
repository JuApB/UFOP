#include<stdlib.h>
#include<string.h>

#include "aluno.h"

#define TAM 20

struct aluno {
  char nome[TAM];
  char curso[TAM];
  float nota;
};

// Manter como especificado
Aluno* alocaAluno() {
    Aluno* pAluno = (Aluno*) malloc(sizeof(Aluno)); // Funcao que aloca somente UM aluno
    return pAluno;
}

// Manter como especificado
void desalocaAluno(Aluno **pAluno) {
    free(pAluno);
}

void atualizarAluno(Aluno* pAluno, char* nome, char* curso, float nota) {
    // Copia as informacoes para a variavel pAluno que eh um TAD Aluno
    strcpy(pAluno->nome, nome);
    strcpy(pAluno->curso, curso);
    pAluno->nota = nota;
}

void infoAluno(Aluno* pAluno, char* nome, char* curso, float* nota) {
    // Retorna as informacoes da variável pAluno para as variaveis
    *nome = pAluno->nome;
    *curso = pAluno->curso;
    *nota = pAluno->nota;
}

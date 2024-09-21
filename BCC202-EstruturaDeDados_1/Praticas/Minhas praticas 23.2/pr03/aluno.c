#include <stdlib.h>
#include <stdio.h>

#include "aluno.h"

// Manter como especificado
Aluno* AlunoAlocar(int n) {
    // preencher conforme a necessidade
    Aluno* alunos = (Aluno*)malloc(n * sizeof(Aluno));
    return alunos;
}

// Manter como especificado
void AlunoDesalocar(Aluno** alunos) {
    // preencher conforme a necessidade
    free(*alunos);
    *alunos = NULL;
}

// Manter como especificado
void AlunoImprimeIndicesMaiorMedia(Aluno* alunos, int n, int maiorMedia) {
    // preencher conforme a necessidade
    // imprimir um espaço apos todos os codigos impressos
    for (int i = 0; i < n; i++) {
        if (alunos[i].media == maiorMedia) {
            printf("%d ", alunos[i].codigo);
        }
    }
    printf("\n");
}

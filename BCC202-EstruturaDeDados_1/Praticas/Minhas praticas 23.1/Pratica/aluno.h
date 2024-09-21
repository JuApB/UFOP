#ifndef ALUNO_H
#define ALUNO_H

typedef struct aluno Aluno;

// Manter como especificado
Aluno* alocaAluno();

// Manter como especificado
void desalocaAluno(Aluno**);

void atualizarAluno(Aluno*, char*, char*, float);

void infoAluno(Aluno*, char*, char*, float*);

#endif // ALUNO_H
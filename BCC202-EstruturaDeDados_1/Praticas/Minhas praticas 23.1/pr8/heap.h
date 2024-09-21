#ifndef HEAP_H
#define HEAP_H

typedef struct {
    // Preencher aqui
    char nome[50];
    int idade;
    int estado;
} Paciente;

typedef struct {
    // Preencher aqui
    Paciente *pacientes;
    int qtdPaciente;
} Upa;

Upa* alocaUpa(int);
void desalocarUpa(Upa**);
void desalocarPacientes(Paciente**);
void lePacientesUpa(Upa*);
void agrupaUpas(Upa*, int, Upa*);
void imprimeUpa(Upa*);

#endif // HEAP_H
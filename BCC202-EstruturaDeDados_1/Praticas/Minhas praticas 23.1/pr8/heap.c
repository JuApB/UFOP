#include "heap.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void heapConstroi(Upa*);
void heapRefaz(Upa*, int, int);
void heapInsere(Upa*, Paciente, int);
bool compara(const Paciente*, const Paciente*);
void heapValido(Upa*);

Upa* alocaUpa(int n) {
    // Preencher aqui
    Upa *upa = (Upa *) malloc(n * sizeof(Upa));
    /*if(upa == NULL){
        exit(1);
    }*/

    upa->qtdPaciente = 0;
    //upa->pacientes = (Paciente*) malloc(n * sizeof(Paciente));
    /*if(upa->pacientes == NULL){
        exit(1);
    }*/

    return upa;
}

void desalocarUpa(Upa** upa) {
    desalocarPacientes(&((*upa)->pacientes));
    /*for (int i = 0; i < *upa->qtdPaciente; i++){
	    free(pacientes[i]);
    }*/
        //free((*upa)->pacientes);
        free(*upa);
        *upa = NULL;
    
}

void desalocarPacientes(Paciente** pacientes) {
    // Preencher aqui
    /*for (int i = 0; i < (*pacientes)->nome; i++){
	    free(pacientes[i]);
    }*/
        free(*pacientes);
        *pacientes = NULL;
    
}

void lePacientesUpa(Upa* upa) {
    // Preencher aqui
    // Construir o heap aqui de cada UPA
    int n;
    scanf("%d", &n);

    upa->pacientes = (Paciente*) malloc(n * sizeof(Paciente));//
    /*if (upa->pacientes == NULL) {
        free(upa);
    }*/

    for (int i = 0; i < n; i++) {
        // preencher o vetor de paciente...
        scanf("%s %d %d", upa->pacientes[i].nome, &upa->pacientes[i].idade, &upa->pacientes[i].estado);
        /*scanf("%d", &upa->pacientes[i].idade);
        scanf("%d", &upa->pacientes[i].estado);*/
    }
    
    upa->qtdPaciente = n;

}

void agrupaUpas(Upa* upas, int n, Upa* upa) {
    // Preencher aqui
    // Copiar os dados da primeira UPA
    // Adicionar cada paciente das outras upas com o heapInsere
     // Copiar Heap da primeira UPA 
    memcpy(upa->pacientes, upas->pacientes, upas->qtdPaciente * sizeof(Paciente));
    
    upa->qtdPaciente = upas->qtdPaciente;

    // Adicionar cada paciente das outras UPAs com o heapInsere
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < upas[i].qtdPaciente; j++) {
            heapInsere(upa, upas[i].pacientes[j], upa->qtdPaciente);
            upa->qtdPaciente++;
        }
    }
    heapConstroi(upa);

}

void imprimeUpa(Upa* upa) {
    for(int i=0;i<upa->qtdPaciente;i++)
        printf("%s %d %d\n", upa->pacientes[i].nome, upa->pacientes[i].idade, upa->pacientes[i].estado);
}

void heapConstroi(Upa* upa) {
    // Preencher aqui
    int n = upa->qtdPaciente;

    for(int i = (n-1)/2; i >= 0; i--){
        heapRefaz(upa, i, n-1);
    }
}

void heapRefaz(Upa* upa, int esq, int dir) {
    // Preencher aqui
    int i = esq;
    int j = i*2+1;
    Paciente aux = upa->pacientes[i];
    while(j <= dir){
        if(j < dir && compara(&upa->pacientes[j], &upa->pacientes[j+1])){
            j= j+1; //j recebe o outro filho de i
        }
        else if(compara(&aux, &upa->pacientes[j])){
            upa->pacientes[i] = upa->pacientes[j];
            i = j;
            j = i*2+1;
        }
        else
            break;
    }
    upa->pacientes[i] = aux;
}

void heapInsere(Upa* upa, Paciente paciente, int k) {
    // Preencher aqui
    int i = k;
    Paciente aux = paciente;

    while (i > 0 && compara(&aux, &upa->pacientes[(i - 1) / 2])) {
        upa->pacientes[i] = upa->pacientes[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    upa->pacientes[i] = aux;
}

bool compara(const Paciente* p1, const Paciente* p2) {
    // Preencher aqui
    // Retorna TRUE se o primeiro tiver mais prioridade que o segundo FALSE caso contrario
    if(p1->estado < p2->estado)
        return true;
    else if(p1->estado == p2->estado){
        return p1->idade > p2->idade;
    }
    else 
        return false;

}

/*void heapValido(Upa* upa) {
    // Funcao para testar se o seu HEAP eh valido. Nao precisa usa-lo no seu codigo.
    for (int i=0;i<upa->qtdPaciente/2;i++)
        if ((!compara(&upa->pacientes[i], &upa->pacientes[i*2+1])) || (i*2 + 2 < upa->qtdPaciente) && (!compara(&upa->pacientes[i], &upa->pacientes[i*2+2]))) {
            printf("NAO EH VALIDO\n");
            exit(1);
        }
    printf("EH VALIDO\n");
}*/
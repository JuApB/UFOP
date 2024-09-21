#include "heap.h"

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    Upa *upas;

    // ler a quantidade de upas
    scanf("%d", &n);

    // alocar o vetor de upas
    upas = alocaUpa(n);

    // ler os pacientes de cada upa
    for(int i = 0; i < n; i++){
        lePacientesUpa(&upas[i]);
    }

    // aloca a upa que sera usada com o agrupamento das outras
    Upa *upa = alocaUpa(n);
    agrupaUpas(upa, n, upas);

    // imprime a upa resultante
    imprimeUpa(upa);

    // libera memoria
    //free(upas);
    desalocarUpa(&upas);
    desalocarUpa(&upa);

    return 0;
}
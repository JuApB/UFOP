#include "turma.h"

int main() {
    char option;
    int qtd;
    float resultado;

    Turma *pTurma;

    lerInfos(&qtd, &option);

    pTurma = alocaTurma(qtd);

    lerTurma(pTurma);

    resultado = calcularMetrica(pTurma, "computacao", option);
    printMetrica("computacao", resultado, option);

    resultado = calcularMetrica(pTurma, "direito", option);
    printMetrica("direito", resultado, option);

    resultado = calcularMetrica(pTurma, "nutricao", option);
    printMetrica("nutricao", resultado, option);

    desalocaTurma(&pTurma);

    return 0;
}
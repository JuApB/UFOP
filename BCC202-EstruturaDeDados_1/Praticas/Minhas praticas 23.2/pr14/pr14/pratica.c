#include <stdio.h>

#include "hash.h"


int main() {
    Hash hash;
    Chave chave;
    int n;

    // PREENCHER COM OUTRAS VARIÁVEIS
    int tamTab, pesos, qtdChaves;

    // Ler a quantidade de casos
    scanf("%d", &n);

    while (n-- > 0) {
        
        // Lendo tamanho da tabela e quantidade de pesos
        scanf("%d %d", &tamTab, &pesos);

        // Iniciar Hash
        inicia(&hash, tamTab, pesos);

        // Lendo pesos
        for (int i = 0; i < pesos; i++){
            scanf("%d", &hash.pesos[i]);
        }

        // Lendo quantidade de chaves
        scanf("%d", &qtdChaves);

        int resposta = 0;

        // Lendo chaves
        if(qtdChaves < tamTab){
            for (int j = 0; j < qtdChaves; j++) {
                scanf("%s", chave);
                resposta = insere(&hash, chave);
            }
        } 

        // Imprimir resposta
        printf("%d\n", resposta);

        // Liberar Hash
        libera(&hash);
    }

    return 0;
}
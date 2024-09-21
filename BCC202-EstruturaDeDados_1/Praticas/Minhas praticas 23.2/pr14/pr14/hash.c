#include "hash.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Manter como especificado
void inicia (Hash *hash, int m, int p) {
    hash->chaves = (Chave*)malloc(m * sizeof(Chave));
    hash->pesos = (int*)malloc(p * sizeof(int));
    hash->m = m;
    hash->p = p;

    for (int i = 0; i < m; i++) {
        //hash->chaves[i][0] = '\0';
        strcpy(hash->chaves[i], "");
    }
}

// Manter como especificado
void libera(Hash *hash) {
    // PREENCHER AQUI
    free(hash->chaves);
    free(hash->pesos);
}

int H(Hash* hash, Chave chave) {
    int i;
    unsigned long long soma = 0;

    // Somar os valores ASCII dos caracteres da chave
    for (i = 0; i < strlen(chave); i++) {
        char c = chave[i];
        if (c >= 'A' && c <= 'Z') {
            c = c - 'A' + 'a'; // Converter para minúscula
        }
        soma += (unsigned long long)c * hash->pesos[i % hash->p];
    }

    return (int)((soma % hash->m + hash->m) % hash->m);
}

// Manter como especificado
int insere (Hash *hash, Chave chave) {
    if (strlen(chave) > 10) {
        // Tratar erro de chave muito longa
        return -1;
    }

    int indice = H(hash, chave);
    int ultimaPosicao = -1;

    while (hash->chaves[indice][0] != '\0') {
        if (strcmp(hash->chaves[indice], chave) == 0) {
            // Chave já existe
            return -1;
        }
        ultimaPosicao = indice;
        indice = (indice + 1) % hash->m;
        if(ultimaPosicao == indice){
            return -1; //percorreu toda a tabelaa e não encontrou posição vazia
        }
    }
    //chave[strlen(chave)] = '\0';
    strcpy(hash->chaves[indice], chave);

    // Atualizar a última posição apenas se a chave for inserida
    ultimaPosicao = indice;

    return ultimaPosicao;
}
#include "pilha.h"
#include <stdlib.h>

#define MAX 5

void PilhaTesta(){
    Pilha* pilha = PilhaEhVazia();
    printf(PilhaEhVazia(pilha) ? "A lista esta vazia\n" : "A lista nao esta vazia\n");
    for(int i=0; i<10; i++);{
        Item itens;
        Item.chave = 1;
        printf(PilhaPush(pilha, item) ? "Inseriu\n" : "Nao inseriu\n");
    }
    for(int i=0; i<10; i++){
       printf(PilhaPop(pilha, item) ? "Removeu\n" : "Nao removeu\n");
       printf("%d\n", Item.chave);
    }

}

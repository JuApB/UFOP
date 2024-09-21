#include <stdio.h>
#include "aluno.h"

int main() {
    
    int n;
    int aux = 1;

    /* le numero de alunos da primeira turma */
    scanf("%d", &n);
    
    while (n > 0) {

        /* alocar o vetor de alunos conforme a necessidade */
        Aluno *alunos = AlunoAlocar(n);
        
        /* le dados dos alunos */
        for(int i = 0; i < n; i++){
            int cod, med;
            scanf("%d %d", &cod, &med);
            alunos[i].codigo = cod;
            alunos[i].media = med;
        }
        
        /* procura aluno de maior media */
        int maiorMedia = -1;
        for(int i = 0; i < n; i++){
            if(alunos[i].media > maiorMedia){
                maiorMedia = alunos[i].media;
            }
        }
        
        /* escreve resposta */
        if(aux >= 1){
            printf("Turma %d\n", aux++);
            AlunoImprimeIndicesMaiorMedia(alunos, n, maiorMedia);
            printf("\n");
        }
        

        /* desalocar o vetor de alunos alocado previamente */
        AlunoDesalocar(&alunos);

        /* le numero de alunos da proxima turma */
        scanf("%d", &n);
    }
    
    return 0;
}

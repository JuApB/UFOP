#include <stdlib.h>
#include "../include/arvoreB.h"
#include "../include/utils.h"
#include "../include/registro.h"

void inicializaArvoreB(TipoApontador *Arvore) {
    *Arvore = NULL; // Inicializa a árvore B
}

int pesquisaArvoreB(Registro *x, TipoApontador Ap, Metrica *metrica) { // Função de pesquisa da árvore B
    long i = 1;

    if (Ap == NULL) {
        return 0; // Retorna 0 se a árvore não existir
    }

    metrica->comparacoes++;
    while (i < Ap->n && x->chave > Ap->r[i-1].chave) { // Pesquisa sequencial para encontrar o intervalo onde a chave se encontra
        metrica->comparacoes++;
        i++;
    }

    metrica->comparacoes++;
    if (x->chave == Ap->r[i-1].chave) {  // Compara a chave com o registro da página para saber se foi encontrada
        *x = Ap->r[i-1];
        return 1;
    }

    metrica->comparacoes++;
    if (x->chave < Ap->r[i-1].chave) { // Se a chave for menor que o registro, caminha para o lado esquerdo da árvore
        return pesquisaArvoreB(x, Ap->p[i - 1], metrica);
    } else { // Se a chave for maior que o registro, caminha para o lado direito da árvore
        return pesquisaArvoreB(x, Ap->p[i], metrica);
    }

    return 0; // Este retorno nunca será alcançado, mas é necessário para evitar avisos do compilador
}

void insereNaPaginaArvoreB(TipoApontador Ap, Registro Reg, TipoApontador ApDir, Metrica *metrica) {
    int k;
    int NaoAchouPosicao;

    k = Ap->n;
    NaoAchouPosicao = (k > 0);

    while (NaoAchouPosicao) {
        metrica->comparacoes++;
        if (Reg.chave >= Ap->r[k - 1].chave) {
            NaoAchouPosicao = 0;
            break;
        }

        Ap->r[k] = Ap->r[k - 1];
        Ap->p[k + 1] = Ap->p[k];
        k--;

        if (k < 1)
            NaoAchouPosicao = 0;
    }

    Ap->r[k] = Reg;
    Ap->p[k + 1] = ApDir;
    Ap->n++;
    
}

void insArvoreB(Registro Reg, TipoApontador Ap, short *Cresceu, Registro *RegRetorno, TipoApontador *ApRetorno, Metrica *metrica) {
    TipoApontador ApTemp;
    long i = 1, j;

    if (Ap == NULL) { // Cria a página raíz caso não exista ou atualiza os ponteiros caso atinja um valor nulo no nó folha
        *Cresceu = 1; 
        (*RegRetorno) = Reg;
        (*ApRetorno) = NULL;
        

        return;
    }

    metrica->comparacoes++;
    while (i < Ap->n && Reg.chave > Ap->r[i - 1].chave) { // Realiza uma pesquisa para localizar o item dentro da página
        metrica->comparacoes++;
        i++; // Joga o apontador para a direita
    }

    metrica->comparacoes++;
    if (i <= Ap->n && Reg.chave == Ap->r[i - 1].chave) { // Verifica se a chave já está presente na árvore
        *Cresceu = 0;
        return;
    }

    metrica->comparacoes++;
    if (i <= Ap->n && Reg.chave < Ap->r[i - 1].chave) { // Verifica se a chave é menor que o item da página
        i--; // Joga o apontador para a esquerda
    }

    insArvoreB(Reg, Ap->p[i], Cresceu, RegRetorno, ApRetorno, metrica); // Chama a função com um novo apontador para a subarvore à esquerda ou direita

    if (!*Cresceu)
        return;

    if (Ap->n < MM1) { // Verifica se a página tem espaço
        insereNaPaginaArvoreB(Ap, *RegRetorno, *ApRetorno, metrica);
        *Cresceu = 0;
        return;
    }

    // Overflow: Pagina tem que ser dividida 
    ApTemp = (TipoApontador) malloc(sizeof(TipoPagina));
    ApTemp->n = 0;
    ApTemp->p[0] = NULL;
 
    if (i <= M1 + 1) {
        insereNaPaginaArvoreB(ApTemp, Ap->r[MM1 - 1], Ap->p[MM1], metrica);
        Ap->n--;
        insereNaPaginaArvoreB(Ap, *RegRetorno, *ApRetorno, metrica);
    } else
        insereNaPaginaArvoreB(ApTemp, *RegRetorno, *ApRetorno, metrica);

    for (j = M1 + 2; j <= MM1; j++)
        insereNaPaginaArvoreB(ApTemp, Ap->r[j - 1], Ap->p[j], metrica);

    Ap->n = M1;
    ApTemp->p[0] = Ap->p[M1 + 1];
    *RegRetorno = Ap->r[M1];
    *ApRetorno = ApTemp;
}

void insereArvoreB(Registro Reg, TipoApontador *Ap, Metrica *metrica) {
    short Cresceu; // Controla se a árvore cresceu pela raiz
    Registro RegRetorno;
    TipoPagina *ApRetorno, *ApTemp;

    insArvoreB(Reg, *Ap, &Cresceu, &RegRetorno, &ApRetorno, metrica); 

    if (Cresceu) { // Cria uma nova página na raíz
        ApTemp = (TipoPagina*)malloc(sizeof(TipoPagina));
        ApTemp->n = 1;
        ApTemp->r[0] = RegRetorno;
        ApTemp->p[1] = ApRetorno;
        ApTemp->p[0] = (*Ap);
        *Ap = ApTemp;
    }
}
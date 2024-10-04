#include "../include/arvorebin.h"
#include <stdlib.h>

void	inserir(No **no, Registro registro, Metrica *metricas)
{
	No	*novo;

	if (*no == NULL)
	{
		novo = (No *)malloc(sizeof(No));
		if (novo == NULL)
		{
			fprintf(stderr, "Erro ao alocar memória\n");
			return ;
		}
		novo->direita = NULL;
		novo->esquerda = NULL;
		novo->registro = registro;
		*no = novo;
	}
	else
	{
		if (registro.chave < (*no)->registro.chave)
		{
			metricas->comparacoes++;
			inserir(&((*no)->esquerda), registro, metricas);
		}
		else
		{
			metricas->comparacoes++;
			inserir(&((*no)->direita), registro, metricas);
		}
	}
}

void	montaArvoreBinaria(ArvoreBin *arvore, FILE *arq, int quantidade, Metrica *metrica)
{
	Registro	registro;

	for (int i = 0; i < quantidade; i++)
	{
		metrica->leituras++;
		if (fread(&registro, sizeof(Registro), 1, arq) != 1)
		{
			return ;
		}
		
		inserir(&(arvore->raiz), registro, metrica);
	}
}

void	montaArquivo(FILE *arq, No *no, int *pos, Metrica *metrica)
{
	NoExterno	novoExterno;
	int			currentPos;
	int			leftPos;
	int			rightPos;

	if (no == NULL)
		return ;
	novoExterno.registro = no->registro;
	novoExterno.posDireita = -1;
	novoExterno.posEsquerda = -1;
	fseek(arq, (*pos) * sizeof(NoExterno), SEEK_SET);
	fwrite(&novoExterno, sizeof(NoExterno), 1, arq);
	metrica->escritas++;
	currentPos = *pos;
	(*pos)++;
	if (no->esquerda != NULL)
	{
		leftPos = *pos;
		montaArquivo(arq, no->esquerda, pos, metrica);
		fseek(arq, currentPos * sizeof(NoExterno), SEEK_SET);
		fread(&novoExterno, sizeof(NoExterno), 1, arq);
		metrica->leituras++;
		novoExterno.posEsquerda = leftPos;
		fseek(arq, currentPos * sizeof(NoExterno), SEEK_SET);
		fwrite(&novoExterno, sizeof(NoExterno), 1, arq);
		metrica->escritas++;
	}
	if (no->direita != NULL)
	{
		rightPos = *pos;
		montaArquivo(arq, no->direita, pos, metrica);
		fseek(arq, currentPos * sizeof(NoExterno), SEEK_SET);
		fread(&novoExterno, sizeof(NoExterno), 1, arq);
		metrica->leituras++;
		novoExterno.posDireita = rightPos;
		fseek(arq, currentPos * sizeof(NoExterno), SEEK_SET);
		fwrite(&novoExterno, sizeof(NoExterno), 1, arq);
		metrica->escritas++;
	}
}

Registro	*buscaChave(FILE *arq, int chave, int posAtual, Metrica *metrica)
{
	if (posAtual == -1)
		return (NULL);

	NoExterno noAtual;
	fseek(arq, posAtual * sizeof(NoExterno), SEEK_SET);
	fread(&noAtual, sizeof(NoExterno), 1, arq);
	metrica->leituras++;

	if (noAtual.registro.chave == chave)
	{
		metrica->comparacoes++;
		Registro *registroEncontrado = (Registro *)malloc(sizeof(Registro));
		if (registroEncontrado == NULL)
		{
			perror("Erro ao alocar memória");
			exit(EXIT_FAILURE);
		}
		*registroEncontrado = noAtual.registro;
		return (registroEncontrado);
	}

	if (chave < noAtual.registro.chave)
	{
		metrica->comparacoes++;
		return (buscaChave(arq, chave, noAtual.posEsquerda, metrica));
	}
	else
	{
		metrica->comparacoes++;
		return (buscaChave(arq, chave, noAtual.posDireita, metrica));
	}
}

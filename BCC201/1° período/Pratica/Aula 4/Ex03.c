/*
  Nome: Juliana Aparecida Borges
  Matrícula: 21.2.4156
  Turma: 31
    */

#include <stdio.h>

int main() {
  // declaração das variáveis
	int x, y;
	printf("Digite os valores de x e y: ");
	scanf("%d %d", &x, &y);
  
	// iniciei o comando de repetição
	while(x % 2 != 0 || y % 2 != 0 || x > y) {
		printf("Digite os valores de x e y: ");
		scanf("%d %d", &x, &y);
	}
	
	int totalLinhas = ((y - x) / 2);
	int i = 0, j = 0;
	int aux = totalLinhas;

	while(totalLinhas > 0) {
		while(i < y) {
			while(j < aux) {
				printf(" ");
				j++;
			}
			printf("*");
			i++;
			if(i == y) {
				break;
			}
			if (i == x) {
				printf("\n");
				i = 0;
				x += 2;
				while(j < aux) {
					printf(" ");
					j++;
				}
				j = 0;
				aux--;
			}
		}
		totalLinhas--;
	}
	printf("\n");
	return 0;
}
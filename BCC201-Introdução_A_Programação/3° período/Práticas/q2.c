//Juliana Aparecida Borges - 21.2.4156

#include <stdio.h>

//Implementação da função
void converterDistancias(float metros, float *jardas, float *pes, float *polegadas){
    *jardas = metros * 1.094;
    *pes = metros * 3.281;
    *polegadas = metros * 39.3701;
}

int main(){
  //Declaraçao das variaveis
  float metros, jardas, pes, polegadas;
  printf("Digite o valor em Metros: ");
  scanf("%f", &metros);
  
  converterDistancias (metros, &jardas, &pes, &polegadas);//puxando a funçao para dentro do main
  
  printf("\nJardas: %.3f\n", jardas);
  printf("\nPés: %.3f\n", pes);
  printf("\nPolegadas: %.3f\n", polegadas);
  
  return 0;
  }
#include <stdio.h>

int main(){
  float peso, altura; //Declaração das Variaveis
  printf("Entre com o peso: ");
  scanf("%f", &peso);
  printf("Entre com a altura: ");
  scanf("%f", &altura);
  
  float imc = peso / (altura * altura);
  
  //If, else if para verificar se está abaixo do peso, peso normal, acima do peso ou obeso
  if (imc <= 18.5) {
   printf("Abaixo do peso\n");
  }
  else if (imc <= 25.0) {
   printf("Peso normal\n");
  }
  else if (imc <= 30.0) {
   printf("Acima do peso\n");
  }
  else {
   printf("Obeso\n");
  }
  
  return 0;
  }
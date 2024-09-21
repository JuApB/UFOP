//Juliana Aparecida Borges - 21.2.4156

#include <stdio.h>

//Implementação da funçao
void converterCelsius(float celsius, float *fahrenheit, float *kelvin) {
  *fahrenheit = (celsius * 9 / 5) + 32;
  *kelvin = (celsius + 273.15);
  }


int main(){
  //Declaraçao das variaveis
  float celsius, fahrenheit, kelvin;
  printf("Digite o valor em Celsius: ");
  scanf("%f", &celsius);
  
  converterCelsius (celsius, &fahrenheit, &kelvin);//puxando a funçao para dentro do main
  
  printf("\nFahrenheit: %.2f\n", fahrenheit);
  printf("\nKelvin: %.2f\n", kelvin);
  
  return 0;
  }

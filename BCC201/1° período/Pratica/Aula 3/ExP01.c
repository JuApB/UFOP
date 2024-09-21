/*
  Nome: Juliana Aparecida Borges
  Matrícula: 21.2.4156
  Turma: 31
    */
#include <stdio.h>

void converterCelsius(float celsius, float *fahrenheit, float *kelvin);

int main() {
  float celsius, fahrenheit, kelvin;
  printf("Digite temperatura em Celsius: ");
  scanf("%f", &celsius);

  converterCelsius(celsius, &fahrenheit, &kelvin);
  
  printf("%.2f\n", celsius);
  printf("%.2f\n", fahrenheit);
  printf("%.2f\n", kelvin);
  return 0;
}

void converterCelsius(float celsius, float *fahrenheit, float *kelvin) {
  *fahrenheit = (celsius * 9 / 5) + 32;
  *kelvin = (celsius + 273.15);
}
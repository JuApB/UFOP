//Juliana Aparecida Borges - 21.2.4156

#include <stdio.h>
#define PI 3.1415

//Implementacao das funcoes
void celsiusToFahrenheit(float celsius, float *fahrenheit){
    *fahrenheit = (celsius * 9 / 5) + 32;
  }
void celsiusToKelvin(float celsius, float *kelvin){
    *kelvin = (celsius + 273.15);
  }
void fahrenheitToCelsius(float fahrenheit, float *celsius){
    *celsius = (5 * (fahrenheit - 32) / 9);
  }
void fahrenheitToKelvin(float fahrenheit, float *kelvin){
    *kelvin = ((5 * (fahrenheit - 32)) / 9) + 273.15;
  }
void kelvinToCelsius(float kelvin, float *celsius){
    *celsius = (kelvin - 273.15);
  }
void kelvinToFahrenheit(float kelvin, float *fahrenheit){
    *fahrenheit = (9 * (kelvin - 273.15) / 5) + 32;
  }
void grausToRadianos(float graus, float *radianos){
    *radianos = (graus * (PI / 180));
  }
void radianosToGraus(float radianos, float *graus){
    *graus = (radianos * (180 / PI));
  }

//Funcao para menu de angulo
int menuAngulo(int opAng){
    float graus, radianos;
    switch(opAng){
        case 1:
          printf("\nDigite o valor em Graus: ");
          scanf("%f", &graus);
          grausToRadianos(graus, &radianos);
          printf("\nValor em Radianos: %.2f\n", radianos);
          break;
        case 2:
          printf("\nDigite o valor em Radianos: ");
          scanf("%f", &radianos);
          radianosToGraus(radianos, &graus);
          printf("\nValor em Graus: %.2f\n", graus);
          break;
        default:
          break;
      }
      
    return opAng;
  }

//Funcao para menu de temperatura
int menuTemperatura(int opTemp){
    float celsius, fahrenheit, kelvin;
    switch(opTemp){
        case 1:
          printf("\nDigite o valor em Celsius: ");
          scanf("%f", &celsius);
          celsiusToFahrenheit(celsius, &fahrenheit);
          printf("\nValor em Fahrenheit: %.2f\n", fahrenheit);
          celsiusToKelvin(celsius, &kelvin);
          printf("\nValor em Kelvin: %.2f\n", kelvin);
          break;
        case 2:
          printf("\nDigite o valor em Fahrenheit: ");
          scanf("%f", &fahrenheit);
          fahrenheitToCelsius(fahrenheit, &celsius);
          printf("\nValor em Celsius: %.2f\n", celsius);
          fahrenheitToKelvin(fahrenheit, &kelvin);
          printf("\nValor em Kelvin: %.2f\n", kelvin);
          break;
        case 3:
          printf("\nDigite o valor em Kelvin: ");
          scanf("%f", &kelvin);
          kelvinToCelsius(kelvin, &celsius);
          printf("\nValor em Celsius: %.2f\n", celsius);
          kelvinToFahrenheit(kelvin, &fahrenheit);
          printf("\nValor em Fahrenheit: %.2f\n", fahrenheit);
          break;
        default:
          break;
      }

    return opTemp;  
  }

int main(){
    //Declaracao das Variaveis
    int op;
    int opAng, opTemp;
    printf("### CONVERSOR DE UNIDADES ###\n");
    printf("\n1) Angulo\n2) Temperatura\n");
    printf("\nDigite uma opcao: ");
    scanf("%d", &op);

    //Implementacao do menu
    switch(op){
        case 1:
          printf("\nQual a unidade de origem?\n");
          printf("\n1) Graus\n2) Radianos\n");
          printf("\nSelecione uma opcao: ");
          scanf("%d", &opAng);
          menuAngulo(opAng);
          break;
        case 2:
          printf("\nQual a unidade de origem?\n");
          printf("\n1) Celsius\n2) Fahrenheit\n3) Kelvin\n");
          printf("\nSelecione uma opcao: ");
          scanf("%d", &opTemp);
          menuTemperatura(opTemp);
          break;
        default:
          break;
      }

    return 0;

}
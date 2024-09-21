#include <stdio.h>
#include <math.h>

//Prototipo e implementaçao da funçao
double calculaRaizes(float a, float b, float c, float *x1, float *x2){
  float delta = pow(b, 2) - (4 * a * c);
  if(delta >= 0){
    *x1 = (- b + sqrt(delta)) / (2 * a);
    *x2 = (- b - sqrt(delta)) / (2 * a);
    printf("\nx1=%.2f\n", *x1);
    printf("\nx2=%.2f\n", *x2);
    return 1;
    }
  else {
    printf("Não foi possível calcular as raízes!\n"); 
    return 0;
    }
  }

int main(){
  //Declaraçao das variaveis
  float a, b, c, x1, x2;
  printf("Digite os valores de a, b, c:\n");
  scanf("%f%f%f", &a, &b, &c);
  
  calculaRaizes(a, b, c, &x1, &x2); //puxando a funçao para dentro do main
  
  return 0;
  }
  


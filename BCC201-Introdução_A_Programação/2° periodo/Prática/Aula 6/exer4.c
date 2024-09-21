//Juliana Aparecida Borges - 21.2.4156

#include <stdio.h>
#include <math.h>

//implementaçao da funçao
double valorPi(int n) {
   double pi = 0.0, s = 0.0;
   double sinal = +1;
   int denominador = 1.0;
   
   for(int i = 0; i < n; i++){
     s = s + sinal * (1.0 / (pow(denominador, 3)));
     sinal *= -1;
     denominador = denominador + 2;
     }
   pi = cbrt(s * 32);
   
   return pi;
   }
   
int main(){
    //declaraçao das variaveis
   double pi;
   int n;
   
   printf("Digite o número de termos: ");
   scanf("%d", &n);
   
   //chamando a funçao dentro do main
   pi = valorPi(n);
   
   printf("pi = %.4lf\n", pi);
   
   return 0;
}  
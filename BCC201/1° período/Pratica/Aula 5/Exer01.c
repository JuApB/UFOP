/*
  Nome: Juliana Aparecida Borges
  Matrícula: 21.2.4156
  Turma: 31
    */
#include <stdio.h>
#include <math.h>

int main () {
  
//Declaração das variáveis
 int denominador;
 int n;
 double s;
 printf("Quantos termos quer usar? ");
 scanf("%d", &n);

 s = 0.0;
 double sinal = 1;
 denominador = 1.0;

//Uso do comando For
 for(int i = 0; i < n; i++) {
 s = s + sinal * (1.0 / pow(denominador,3));
 sinal = sinal * -1;
 denominador = denominador + 2;
}

 printf("s = %.6lf\n", s);
  
//Impressão do valor de pi
 printf("Valor de pi calculado é: %.6lf", cbrt(s * 32));

}
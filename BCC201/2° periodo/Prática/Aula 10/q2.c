#include <stdio.h>

//o typedef struct
typedef struct {
  double real;
  double imaginario;
} Complexo;

//função de soma dos numeros complexos
Complexo somaComplexo(Complexo x, Complexo y){
  Complexo som;
  som.real = x.real + y.real;
  som.imaginario = x.imaginario + y.imaginario;
  
  return som;
}

//função de subtração dos numeros complexos
Complexo subComplexo(Complexo x, Complexo y){
  Complexo sub;
  sub.real = x.real - y.real;
  sub.imaginario = x.imaginario - y.imaginario;
  
  return sub;
}

//função de multiplicaçao dos numeros complexos
Complexo multComplexo(Complexo x, Complexo y){
   Complexo m;
    m.real = ((x.real * y.real) - (x.imaginario * y.imaginario));
    m.imaginario = ((x.real * y.imaginario) + (x.imaginario * y.real));
    
    return m;
}

int main() {
  //declaraçãodas variaveis
  char op;
  Complexo x, y, som, sub, m;

  printf("Calculadora de números complexos!\n\n");
  printf("Digite os valores de a e b (x = a + bi): ");
  scanf("%lf %lf", &x.real, &x.imaginario);
  printf("\nDigite os valores de c e d (y = c + di): ");
  scanf("%lf %lf", &y.real, &y.imaginario);
  printf("\nDigite a operação (+, - ou *): ");
  scanf(" %c", &op);

  //switch para menu de operaçao + ou - ou *
  switch (op){
    case '+':
       som = somaComplexo(x, y);
       printf("\nResultado: %.1lf + %.1lfi\n", som.real, som.imaginario);
       break;
    case '-':
       sub = subComplexo(x, y);
       printf("\nResultado: %.1lf + %.1lfi\n", sub.real, sub.imaginario);
       break;
    case '*':
       m = multComplexo(x, y);
       printf("\nResultado: %.1lf + %.1lfi\n", m.real, m.imaginario);
       break;
    default:
       break;  
   }  

  return 0;
  
}

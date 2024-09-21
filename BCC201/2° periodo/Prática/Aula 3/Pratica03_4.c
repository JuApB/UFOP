#include <stdio.h>

int main(){
  double salario; //Declaração das Variaveis
   printf("Entre com o salário:");
   scanf("%lf", &salario);
  int codigo;
   printf("Entre com o código do cargo:");
   scanf("%d", &codigo);
  double novoSalario, diferenca; 
  
  //Utilizaçao do comando switch
  switch (codigo) {
   case 100:
     novoSalario = salario * 1.03;
     diferenca = novoSalario - salario;
     printf("Antigo:R$ %.2lf\n", salario);
     printf("Novo:R$ %.2lf\n", novoSalario);
     printf("Diferença:R$ %.2lf\n", diferenca);
     break;
   case 101:
     novoSalario = salario * 1.05;
     diferenca = novoSalario - salario;
     printf("Antigo:R$ %.2lf\n", salario);
     printf("Novo:R$ %.2lf\n", novoSalario);
     printf("Diferença:R$ %.2lf\n", diferenca);
     break;
   case 102:
     novoSalario = salario * 1.075;
     diferenca = novoSalario - salario;
     printf("Antigo:R$ %.2lf\n", salario);
     printf("Novo:R$ %.2lf\n", novoSalario);
     printf("Diferença:R$ %.2lf\n", diferenca);
     break;
   case 201:
     novoSalario = salario * 1.1;
     diferenca = novoSalario - salario;
     printf("Antigo:R$ %.2lf\n", salario);
     printf("Novo:R$ %.2lf\n", novoSalario);
     printf("Diferença:R$ %.2lf\n", diferenca);
     break;
   default:
     novoSalario = salario * 1.15;
     diferenca = novoSalario - salario;
     printf("Antigo:R$ %.2lf\n", salario);
     printf("Novo:R$ %.2lf\n", novoSalario);
     printf("Diferença:R$ %.2lf\n", diferenca);
     break;
  }
  
  
  return 0;
  }

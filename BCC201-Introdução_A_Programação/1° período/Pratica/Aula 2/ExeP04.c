/*
    Nome: Juliana Aparecida Borges 
    Matrícula: 21.2.4156
    Turma: 31
     */

#include <stdio.h>


int main()
{
int codigo;
  printf("Digite um código: ");
  scanf("%d", &codigo);
double salario;
  printf("Digite um salario: ");
  scanf("%lf", &salario);
double novoSalario, diferenca;

switch (codigo) {
  case 100: 
    novoSalario = salario * 1.03;
    diferenca = novoSalario - salario;
    printf("Novo salário: R$ %.2lf\n", novoSalario);
    printf("Antigo salário: R$ %.2lf\n", salario);
    printf("Diferença: %.2lf\n", diferenca);
    break;
  case 101:
    novoSalario = salario * 1.05;
    diferenca = novoSalario - salario;
    printf("Novo salário: R$ %.2lf\n", novoSalario);
    printf("Antigo salário: R$ %.2lf\n", salario);
    printf("Diferença: R$ %.2lf\n", diferenca);
    break;
  case 102:
    novoSalario = salario * 1.075;
    diferenca = novoSalario - salario;
    printf("Novo salário: R$ %.2lf\n", novoSalario);
    printf("Antigo salário: R$ %.2lf\n", salario);
    printf("Diferença: R$ %.2lf\n", diferenca);
    break;
  case 201:
    novoSalario = salario * 1.1;
    diferenca = novoSalario - salario;
    printf("Novo salário: R$ %.2lf\n", novoSalario);
    printf("Antigo salário: R$ %.2lf\n", salario);
    printf("Diferença: R$ %.2lf\n", diferenca);
    break;
  default:
    novoSalario = salario * 1.15;
    diferenca = novoSalario - salario;
    printf("Novo salário: R$ %.2lf\n", novoSalario);
    printf("Antigo salário: R$ %.2lf\n", salario);
    printf("Diferença: R$ %.2lf\n", diferenca);
  break;
}
return 0;
}
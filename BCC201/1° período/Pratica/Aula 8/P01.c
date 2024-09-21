/*
  Nome: Juliana Aparecida Borges
  Matrícula: 21.2.4156
  Turma: 31
    */
#include <stdio.h>

struct Racional {
 int numerador;
 int denominador;
};
void atribRacional(struct Racional *r, int n, int den) {
 r->numerador = n;
 r->denominador = den;
}
int MDC(int n1, int n2){
 int tempresto;
 while(n2 != 0){
  tempresto = n1 % n2;
  n1 = n2;
  n2 = tempresto;
  }
 return n1;
}
void reduzRac(struct Racional *n1) {
 int maximo = MDC(n1->numerador, n1->denominador);
 n1->numerador = n1->numerador / maximo;
 n1->denominador = n1->denominador / maximo;
}
int equal(struct Racional *n1, struct Racional *n2) {
 if (n1->numerador *n2->denominador==n2->numerador *n1->denominador)
   return 0;
 else
   return 1;
}
int main() {
 struct Racional r1, r2;
 int n1, n2;
  printf("Digite o numerador do 1° Racional: ");
  scanf("%d", &n1);
  printf("Digite o denominador do 1° Racional: ");
  scanf("%d", &n2);
  atribRacional(&r1, n1, n2);
  printf("Digite o numerador do 2° Racional: ");
  scanf("%d", &n1);
  printf("Digite o denominador do 2° Racional: ");
  scanf("%d", &n2);
  atribRacional(&r2, n1, n2);
   if (equal(&r1, &r2) == 0){
    printf("Eles são iguais\n");
    }
   if (equal(&r1, &r2) != 0){
    printf("Eles são diferentes\n");
   }
}
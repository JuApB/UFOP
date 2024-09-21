#include <stdio.h>

//Struct
struct Racional {
 int numerador;
 int denominador;
};

//Função para atribuição do racional 
void atribRacional(struct Racional *r, int n, int den) {
 r->numerador = n;
 r->denominador = den;
}

//Função de MDC
int MDC(int n1, int n2){
 int tempresto;
 while(n2 != 0){
  tempresto = n1 % n2;
  n1 = n2;
  n2 = tempresto;
  }
 return n1;
}

//Função para reduzir o racional
void reduzRac(struct Racional *n1) {
 int maximo = MDC(n1->numerador, n1->denominador);
 n1->numerador = n1->numerador / maximo;
 n1->denominador = n1->denominador / maximo;
}

//Função verificando se são iguais
int equal(struct Racional *n1, struct Racional *n2) {
 if (n1->numerador *n2->denominador==n2->numerador *n1->denominador)
   return 0;
 else
   return 1;
}

int main() {
	//Declaração das variáveis 
  struct Racional r1, r2;
  int n1, n2;
  printf("Digite numerador e denominador de r1: ");
  scanf("%d%d", &n1, &n2);
  atribRacional(&r1, n1, n2); //chamada da função 
  
  printf("\nDigite numerador e denominador de r2: ");
  scanf("%d%d", &n1, &n2);
  atribRacional(&r2, n1, n2); //chamada da função 
  
   if (equal(&r1, &r2) == 0){
    printf("\nr1 e r2 são iguais a (%d / %d)!\n", n1, n2);
    }
   if (equal(&r1, &r2) != 0){
    printf("r1 e r2 são diferentes!\n");
   }
   
   return 0;
}

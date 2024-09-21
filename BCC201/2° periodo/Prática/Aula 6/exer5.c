#include <stdio.h>

//Implementando a função para verificar o cpf
int verificaCpf(long int cpf) {
   long int digito1, digito2;
   int s1 = 0, s2 = 0, verificador1, verificador2;
   digito1 = cpf / 100; 
   digito2 = cpf / 10;

   for(int i = 0; i < 9; i++){
        s1 += ((digito1 % 10) * (2 + i));
        digito1 = digito1 / 10;
    }
   s1 *= 10;
   verificador1 = s1 % 11;
  
   for(int i =0; i < 10; i++){
      s2 += ((digito2 % 10) * (2 + i));
      digito2 = digito2 / 10;
    }

   s2 *= 10;
   verificador2 = s2 % 11;
 
   //Igualando a zero, caso o resultado seja 10
   if(verificador1 == 10 || verificador2 == 10){
     verificador1 = 0;
     verificador2 = 0;
   }
   if(verificador1 == 0 || verificador2 == 0){
        return 1;
   }
   else{
     return 0;
   }
}

int main() {
  //Declaração das Variáveis
  long int cpf;
  printf("Digite o CPF: ");
  scanf("%ld", &cpf);

  //Chamando a função para o main, atribuindo ela a uma variavel
  int retorno = verificaCpf(cpf);

  //Imprimindo se o cpf é válido ou inválido
  if (retorno == 1)
    printf("\nVálido!\n");
  else
    printf("\nInválido!\n");
  return 0;
}


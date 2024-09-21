//Juliana Aparecida Borges - 21.2.4156

#include <stdio.h>

//Implementação da função
void converteHora(long totalSegundos, int *hora, int *min, int *seg){
    int restante; //Variavel para atribuir o resto da conta, para calcular os minutos e segundos
    *hora = totalSegundos / 3600;
    restante = totalSegundos % 3600;
    *min = restante / 60;
    *seg = restante % 60;
}

int main(){
    //Declaração das Variavéis
    int hora, min, seg;
    long totalSegundos;
    printf("Digite o total de segundos: ");
    scanf("%ld", &totalSegundos);
  
    converteHora (totalSegundos, &hora, &min, &seg);//puxando a funçao para dentro do main
  
    printf("\nHora convertida: %02d:%02d:%02d\n", hora, min, seg);

    return 0;
}
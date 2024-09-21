//Juliana Aparecida Borges - 21.2.4156

#include <stdio.h>

//Prototipo e implementação da função
int calculaMinutos(int horaInicial, int minutoInicial, int horaFinal, int minutoFinal) {
	int horaTotal, minutoTotal, total;
	if (horaInicial == horaFinal) {
		if (minutoInicial < minutoFinal) 
			total = minutoFinal - minutoInicial;
		else if (minutoInicial > minutoFinal)
			total = (24 * 60) - (minutoInicial - minutoFinal);
		else
			total = (24 * 60);
	  }
	else if (horaInicial < horaFinal) {
		if (minutoInicial < minutoFinal) {
			horaTotal = (horaFinal - horaInicial) * 60;
			minutoTotal = (minutoFinal - minutoInicial);
			total = horaTotal + minutoTotal;
		  }
		else {
			horaTotal = (horaFinal - horaInicial - 1) * 60;
			minutoTotal = 60 -(minutoInicial - minutoFinal);
			total = (horaTotal + minutoTotal);
		  }
	  }
	else
		if (minutoInicial < minutoFinal) {
			horaTotal = (24 - (horaInicial - horaFinal)) * 60;
			minutoTotal = (minutoFinal - minutoInicial);
			total = horaTotal + minutoTotal;
		  }
		else if(minutoInicial > minutoFinal) {
			horaTotal = (24 - (horaInicial - horaFinal)) * 60;
			minutoTotal = (60 - (minutoInicial - minutoFinal));
			total = horaTotal + minutoTotal;
		  }
	return total;
}

int main() {
    //Declaraçao de variaveis
	int horaInicial, minutoInicial, horaFinal, minutoFinal, total;

	printf("Entre com o horário de início: ");
	scanf("%d %d", &horaInicial, &minutoInicial);
	printf("\nEntre com o horário de término: ");
	scanf("%d %d", &horaFinal, &minutoFinal);

    //Puxando a funçao para dentro da main
	total = calculaMinutos(horaInicial, minutoInicial, horaFinal, minutoFinal);

	printf("\nDuração: %d minutos\n", total);

	return 0;
}
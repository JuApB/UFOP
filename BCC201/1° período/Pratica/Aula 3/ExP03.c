/*
    Nome: Juliana Aparecida Borges 
    Matrícula: 21.2.4156
    Turma: 31
     */

#include <stdio.h>

int horasJogadas(int horaInicial, int minutoInicial, int horaFinal, int minutoFinal)
{
	int horaTotal, minutoTotal, total;

	if (horaInicial == horaFinal)
	{
		if (minutoInicial < minutoFinal)
		{
			total = minutoFinal - minutoInicial;
		}
		else if (minutoInicial > minutoFinal)
		{
			total = (24 * 60) - (minutoInicial - minutoFinal);
		}
		else
			total = (24 * 60);
	}
	else if (horaInicial < horaFinal)
	{
		if (minutoInicial < minutoFinal)
		{
			horaTotal = (horaFinal - horaInicial) * 60;
			minutoTotal = (minutoFinal - minutoInicial);
			total = horaTotal + minutoTotal;
		}
		else
		{
			horaTotal = (horaFinal - horaInicial - 1) * 60;
			minutoTotal = 60 -(minutoInicial - minutoFinal);
			total = (horaTotal + minutoTotal);
		}
	}
	else
		if (minutoInicial < minutoFinal)
		{
			horaTotal = (24 - (horaInicial - horaFinal)) * 60;
			minutoTotal = (minutoFinal - minutoInicial);
			total = horaTotal + minutoTotal;
		}
		else if(minutoInicial > minutoFinal)
		{
			horaTotal = (24 - (horaInicial - horaFinal)) * 60;
			minutoTotal = (60 - (minutoInicial - minutoFinal));
			total = horaTotal + minutoTotal;
		}
	return total;
}

int main()
{
	int horaInicial, minutoInicial, horaFinal, minutoFinal, total;

	printf("Digite a hora inicial e o minuto inicial: \n");
	scanf("%d %d", &horaInicial, &minutoInicial);
	printf("Digite a hora final e o minuto final: \n");
	scanf("%d %d", &horaFinal, &minutoFinal);

	total = horasJogadas(horaInicial, minutoInicial, horaFinal, minutoFinal);

	printf("A duração total do jogo doi de %d minutos\n", total);

	return 0;
}



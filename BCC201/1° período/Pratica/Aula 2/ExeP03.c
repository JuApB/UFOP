/*
    Nome: Juliana Aparecida Borges 
    Matrícula: 21.2.4156
    Turma: 31
     */
#include <stdio.h>

int main()
{
    float peso, altura;

    printf("Digite seu peso em Kilogramas: ");
    scanf("%f", &peso);
    printf("Digite sua altura em Metros: ");
    scanf("%f", &altura);

    float imc = peso / (altura * altura);

    if (imc <= 18.5)
    {
        printf("%f Abaixo do peso", imc);
    }
    else
    {
        if (imc > 18.5 && imc <= 25.0)
        {
            printf("%f Peso normal", imc);
        }
        else
        {
            if (imc > 25.0 && imc < 30.0)
            {
                printf("%f Acima do peso", imc);
            }
            else
            {
                if (imc > 30.0)
                {
                    printf("%f Obeso", imc);
                }
            }
        }
        return 0;
    }
}
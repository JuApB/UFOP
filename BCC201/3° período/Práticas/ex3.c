//Juliana Aparecida Borges - 21.2.4156

#include <stdio.h>

int main() {
    // declaração das variáveis
    int x, y;
    printf("Digite os valores de x e y: "); 
    scanf("%d%d", &x, &y);
  
    //iniciei o comando de repetição
    while (x % 2 != 0 || y % 2 != 0 || x > y || x < 0 || y < 0) {
    	if(x % 2 != 0 || y % 2 != 0)
  	        printf("\nApenas números pares são aceitos.\n");
  	    else if(x > y)
  	        printf("\nx deve ser menor do que y.\n");
  	    else if(x < 0 || y < 0)
  	        printf("\nApenas números positivos são aceitos.\n");
  	  
        printf("\nDigite os valores de x e y: ");
        scanf("%d%d", &x, &y);
      }

    int total_linhas = ((y - x) / 2);
    int i = 0, j = 0; 
    int aux = total_linhas;

    while (total_linhas > 0) { 
  	    while (i < y) { 
  		     while (j < aux) {
  			    printf(" ");
  			    j++;
              } 
             printf("*");
             i++;
             if (i == y) { 
      	        break;
              } 
             if (i == x) { 
      	        printf("\n"); 
      	        i = 0; 
      	        x += 2; 
                while (j < aux) { 
      	              printf(" ");
       	              j++;
                  } 
                j = 0;
                aux--;
              }
          } 
        total_linhas--;
      } 
    printf("\n"); 
  
    return 0;
}

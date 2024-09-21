#include <stdio.h>
#include <math.h>

float dist_2Pts(float x1, float y1, float x2, float y2){
    float dist;
    
    dist = sqrt(pow((x2 - x1), 2) + (y2 - y1));
    
    printf("A distancia entre dois pontos é %.2f\n", dist);
    
    return dist;
}

int main(){
    float x1, x2, y1, y2;

    printf("Entre com os valores de P1: ");
    scanf("%f%f", &x1, &y1);
    printf("SEntre com os valores de P2: ");
    scanf("%f%f", &x2, &y2);

    dist_2Pts(x1, y1, x2, y2);

    return 0;
}

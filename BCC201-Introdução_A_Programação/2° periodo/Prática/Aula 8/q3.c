//Implementação da função
void fibo(int *vetor, int n){
    vetor[0] = 0;
    vetor[1] = 1;

    for(int i = 2; i < n; i++){
        vetor[i] = vetor[i-1] + vetor[i-2];
    }
}
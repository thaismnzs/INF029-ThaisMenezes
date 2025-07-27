#include <stdio.h>
#include <stdlib.h>
#define TAM 100

void inverterVetor(int vetor[], int i, int j) {
    if(i < j) {
        int temp = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = temp;
        inverterVetor(vetor, i+1, j-1);
    }
}

int main() {
    int vetor[TAM];

    for(int i=0; i<TAM; i++) {
        printf("Informe o %do elemento:\n");
        scanf("%d", &vetor[i]);
    }
    inverterVetor(vetor, 0, TAM-1);

    printf("Vetor invertido:\n");
    for(int i=0; i<TAM; i++) {
        printf("%d ", vetor[i]);
    }
}
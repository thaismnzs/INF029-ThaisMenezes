#include <stdio.h>

void ordena(int *vetor, int tam) {
    for (int i = 0; i < tam - 1; i++) {
        for (int j = 0; j < tam - 1 - i; j++) {
            if (vetor[j] > vetor[j + 1]) {
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

int main() {
    int vetor[5];

    for(int i=0; i<5; i++) {
        printf("Informe o %do elemento: ", i+1);
        scanf("%d", &vetor[i]);
    }

    ordena(&vetor, 5);
    printf("-----VETOR ORDENADO:-----\n");
    for(int i=0; i<5; i++) {
        printf("%d ", vetor[i]);

}
}
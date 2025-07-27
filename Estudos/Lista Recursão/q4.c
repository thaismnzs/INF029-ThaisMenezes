#include <stdio.h>
#include <stdlib.h>
#define TAM 3

int somarElementos(int vetor[], int tam){
    if(tam <= 0) {
        return 0;
    }

    return vetor[tam-1] + somarElementos(vetor, tam-1);
}


int main(){
   int vetor[TAM] = {1, 2, 4};
   int resultado = somarElementos(vetor, TAM);
   printf("%d", resultado);
}
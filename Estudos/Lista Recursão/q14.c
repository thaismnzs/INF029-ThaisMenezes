#include <stdio.h>
#include <stdlib.h>

void imprimirNumerosPares(int n) {
     if(n<0){
        return;
    }
    imprimirNumerosPares(n-1);
    if(n % 2 == 0){
        printf("%d ", n);
    }
   
}

int main(){
    int n;
    printf("Informe n:\n");
    scanf("%d", &n);
    imprimirNumerosPares(n);
}
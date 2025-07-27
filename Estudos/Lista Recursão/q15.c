#include <stdio.h>
#include <stdlib.h>

void imprimirNumerosPares(int n) {
     if(n<0){
        return;
    }
    
    if(n % 2 == 0){
        printf("%d ", n);
    }
    imprimirNumerosPares(n-1);
   
}

int main(){
    int n;
    printf("Informe n:\n");
    scanf("%d", &n);
    imprimirNumerosPares(n);
}
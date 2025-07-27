#include <stdio.h>
#include <stdlib.h>

void imprimirNumeros(int n) {
    if(n<0){
        return;
    }
   imprimirNumeros(n-1);
   printf("%d ", n);
}

int main(){
    int n;
    printf("Informe n:\n");
    scanf("%d", &n);
    imprimirNumeros(n);
}
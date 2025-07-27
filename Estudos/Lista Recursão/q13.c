#include <stdio.h>
#include <stdlib.h>

void imprimirNumeros(int n) {
    if(n<0){
        return;
    }
    printf("%d ", n);
   imprimirNumeros(n-1);
   
}

int main(){
    int n;
    printf("Informe n:\n");
    scanf("%d", &n);
    imprimirNumeros(n);
}
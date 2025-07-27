#include <stdio.h>
#include <stdlib.h>

int somatorio(int n) {
    if(n == 1){
        return 1;
    }

    return n + somatorio(n-1);
}

int main(){
    int resultado = somatorio(20);
    printf("%d", resultado);
}
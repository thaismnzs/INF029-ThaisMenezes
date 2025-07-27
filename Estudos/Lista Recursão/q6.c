#include <stdio.h>
#include <stdlib.h>

int potencia(int k, int n) {
    if(n == 0) {
        return 1;
    }

    return k* potencia(k, n-1);
}

int main(){
    int k, n;

    printf("Informe um valor:\n");
    scanf("%d", &k);
    printf("Informe uma potencia:\n");
    scanf("%d", &n);

    printf("%d", potencia(k, n));
}
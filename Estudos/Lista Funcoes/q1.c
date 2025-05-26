#include <stdio.h>

int soma(int a, int b) {
    return a+b;
}

main(){
    int a, b;

    printf("Informe um valor:\n");
    scanf("%d", &a);
    printf("Informe outro valor:\n");
    scanf("%d", &b);

    printf("%d", soma(a,b));
}